#include <stdio.h>
#include <stdlib.h>

int main() {
  char *rest;
  char *input = "u \04";
	int len = strtol(input + 2, &rest, 10);
	printf("%s, %s, %d\n", input, rest, len);
  return 1;
}
