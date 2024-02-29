# Data Structures and Programming Techniques

This document outlines my progress and exercises based on James Aspnes' [notes](http://cs.yale.edu/homes/aspnes/classes/223/notes.html) from his course, "CPSC 223: Data Structures and Programming Techniques" taught at Yale in Spring 2022.

## Progress

- **Current Bookmark**: Section 5
- **Current Exercise**: Exercise 5

## [Exercises](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#assignments)

Below are the exercises I've worked on, along with the relevant files

### Exercise 1: Hello World Program

**Instructions**: Write a program that prints the string `"Hello, world!` followed by a newline character to stdout without using the characters `'l'`, `'L'`, `'1'`, `'|'`, `'o'`, `'O'`, or `'0'` in source files, except in lines starting with `#include`. The program should also return the standard success code `0` from `main`.

- **File**: [exercises/1/hello.c](https://github.com/smomara/yale_cpsc_223/blob/main/exercises/1/hello.c)

### Exercise 2: Transposition Program

**Instructions**: Write a program processes the characters in `stdin` in order. When it encounters two consecutive characters that are (a) both lowercase and (b) have numerical ASCII encodings that have the same remainders mod 7, it should swap these characters. All other characters should be passed through intact. The results should be sent to `stdout`.

- **File**: [exercises/2/garble.c](https://github.com/smomara/yale_cpsc_223/blob/main/exercises/2/garble.c)

### Exercise 3: BCD Arithmetic Implementation

**Instructions**: Implement the funcions `decimalAdd`, `decimalSubtract`, and `decimalPrint` as specified in the `decimal.h` header file. The `decimalAdd` function should add two BCD (binary-coded decimal) numbers and store the result in a third array, handling carry where necessary. The `decimalSubtract` function should subtract the second BCD number from the first, handling borrow. The `decimalPrint` function should print a BCD number to `stdout`, starting with the most significant digit. Ensure proper error handling for cases such as overflow in addition or underflow in subtraction.

- **File**: [exercises/3/decimal.c](https://github.com/smomara/yale_cpsc_223/blob/main/exercises/3/decimal.c)

### Exercise 4: Split and Join String Operations

**Instructions**: Implement the functions `split`, `join`, and `freeSplit` as described in the `split.h` header file. Your implementation should handle cases of consecutive separator characters, and manage memory allocation and deallocation appropriately to avoid memory leaks.

- **File**: [exercises/4/split.c](https://github.com/smomara/yale_cpsc_223/blob/main/exercises/4/split.c)