# Lab3 - Analyzing Crash Results with AFL and AddressSanitizer

## Setup and General steps

1. Compile the code with the makefile (rename source to convert.c)
2. Fuzz with AFL - 5 crashes after 5 min
3. Move crash inputs to a crashes dir and rename for quick analysis
4. Compile with address sanitizer and run code with inputs individually
5. Analyze the crash messages

---

## Crash Results Analyzed

![AFL](https://github.com/isaacdenny/csc3940/blob/master/lab3/screenshots/afl.png)
The crash inputs are labeled in the crashes folder

### c00

*Bug Type*: Stack-based buffer overflow

*Input*: `head 200` will overflow because line 49 `rest[200]` will be greater than the `input` buffer size)

![c00](https://github.com/isaacdenny/csc3940/blob/master/lab3/screenshots/c00.png)

*Conditions*: This crash can be recreated using input that starts with "head " followed by any float value or integer greater than the buffer size. The `strtol` function returns a float and sets the `rest` pointer to the first unparsed value in the input string, but the program then uses this float to end the string with `\0`, writing to an arbitrary address if exploited.

*Mitigation*: To keep the same functionality, but add safety to the code, we could just add a check to see if the result from `strtol` on line 48 (`len`) falls outside the bounds of the input string the program will output an out-of-bounds message.

```
    len = strtol(input + 4, &rest, 10);
    if (len + 5 > strlen(input)) {// add 5 to account for the head command
        fprintf(stderr, "head input out of bounds\n");
        return 2;
    }
    rest += 1;		  
    rest[len] = '\0'; 
    printf("%s\n", rest);
```

---

### c01

*Bug Type*: Heap-based buffer overflow

*Input*: `u 44444`

![c01](https://github.com/isaacdenny/csc3940/blob/master/lab3/screenshots/c01.png)

*Conditions*: `out` is heap-allocated on line 18, then line 29 has a really weird for-loop condition that runs as long as long as `i != len`, which will never be false if len is a float (which may frequently occur via strtol); this results in an overflow on line 36 `out[i] = c`

*Mitigation*: Change the loop condition to stop when `i >= len` like so

```
    for (int i = 0; i < len; i++)
```

---

### c02

*Bug Type*: Heap-based buffer overflow

*Input*: `u 8 capgggg ggggggggggggggggggs`

![c02](https://github.com/isaacdenny/csc3940/blob/master/lab3/screenshots/c02.png)

*Conditions*: Because the program uses strlen to allocate `out` on line 18, and the input contains an early null character (represented above with `^@`), the out buffer is overflowed when we try to `strcat` on line 39

*Mitigation*: Check the length of the `out` buffer before concatenating the rest of input to it

---

### c03

*Bug Type*: Heap-based buffer overflow

*Input*: `u  4ððððððððððððððððððððððððððððððð4444044W4`

![c03](https://github.com/isaacdenny/csc3940/blob/master/lab3/screenshots/c03.png)

*Conditions*: The null byte immediately following the command makes strtol return a len of 0. Because of this, the out buffer is only allocated 3 bytes ('u' + <space> + '\0'). Then, when rest is incremented by 1, it now points past the null character and causes the strcat on line 39 to overflow the out buffer.

*Mitigation*: Add a check before the strcat on line 39 to check if the length of len + rest can be concatenated to the out buffer

```
    if (strlen(rest + 4) > sizeof(out) - 1 - strlen(out)) {
        fprintf(stderr, "Error evaluating rest of input\n");
        return 3;
    }
```

---

### c04

*Bug Type*: Stack-based buffer overflow

*Input*: head 99

![c04](https://github.com/isaacdenny/csc3940/blob/master/lab3/screenshots/c04.png)

*Conditions*: The pointer arithmetic on line 48 assumes there are more characters after the float value. As in the above input, this is not always the case. Then on line 49 we access memory way out of bounds (99 characters after the input string.

*Mitigation*: add a check after parsing the float value to make sure there are more characters after the input (and also more than the float value.

```
    if (strlen(rest) < len) {
        fprintf(stderr, "Invalid input\n");
        return 2;
    }
```
