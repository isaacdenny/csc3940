#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("usage: rm <filename>");
  }
  const char* file = argv[1];

  if (remove(file) == 0) {
    printf("File removed successfully: %s\n", file);
    return 0;
  }
  else{
    perror("Error removing file");
    exit(1);
  }
}
