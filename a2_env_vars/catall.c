#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char** argv) {
  char *v[3];
  char *command;

  system("env | grep PATH");
  system("which cat");
  if (argc < 2) {
    printf("usage: catall <filename>");
    return 1;
  }

  v[0] = "/bin/cat"; v[1] = argv[1]; v[2] = NULL;
  command = malloc(strlen(v[0]) + strlen(v[1]) + 2);
  sprintf(command, "%s %s", v[0], v[1]);

  system(command);
  //execve(v[0], v, NULL);
  return 0;
}
