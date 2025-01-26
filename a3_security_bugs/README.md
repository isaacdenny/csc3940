# Identify Security Bugs

## Sample programs identified

1. Stack-based buffer overflow

- The user can enter any length string and gets() will read until a new line, overflowing the buffer

2. Heap-based buffer overflow 

- The buffer is heap allocated and strcpy copies a string larger than the buffer size

3. 

4. Use after free

- The buffer is freed and then accessed again

5. Double free

- The buffer is freed twice

6. 
