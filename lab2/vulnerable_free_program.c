#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = malloc(10);
    free(buffer);
    strcpy(buffer, "Hello!");
    printf("%s\n", buffer);
    return 0;
}
