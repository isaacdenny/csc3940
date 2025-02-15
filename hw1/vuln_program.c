#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function contains a buffer overflow vulnerability
void vulnerable_function() {
    char buffer[300]; // The buffer size is 300 bytes

    printf("Enter input: ");
    gets(buffer);  // Unsafe function, allows buffer overflow
}

int main() {
    printf("Welcome to your Stack Smashing Homework!\n");
    vulnerable_function();
    printf("Goodbye!\n");
    return 0;
}
