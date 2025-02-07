#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function contains a buffer overflow vulnerability
void vulnerable_function() {
    char buffer[256]; // The buffer size is 256 bytes

    printf("Enter input: ");
    gets(buffer);  // Unsafe function, allows buffer overflow
}

int main() {
    printf("Welcome to the Stack Smashing Lab!\n");
    vulnerable_function();
    printf("Goodbye!\n");
    return 0;
}
