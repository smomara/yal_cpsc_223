# Data Structures and Programming Techniques

This document outlines my progress and exercises based on James Aspnes' [notes](http://cs.yale.edu/homes/aspnes/classes/223/notes.html) from his course, "CPSC 223: Data Structures and Programming Techniques" taught at Yale in Spring 2022.

## Progress

- **Current Bookmark**: Section 4.5
- **Current Exercise**: Exercise 3

## [Exercises](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#assignments)

Below are the exercises I've worked on, along with the relevant files

### Exercise 1: Hello World Program

**Instructions**: Write a program that prints the string `"Hello, world!` followed by a newline character to stdout without using the characters `'l'`, `'L'`, `'1'`, `'|'`, `'o'`, `'O'`, or `'0'` in source files, except in lines starting with `#include`. The program should also return the standard success code `0` from `main`.

- **File**: exercises/hello.c

### Exercise 2: Transposition Program

**Instructions**: Write a program processes the characters in `stdin` in order. When it encounters two consecutive characters that are (a) both lowercase and (b) have numerical ASCII encodings that have the same remainders mod 7, it should swap these characters. All other characters should be passed through intact. The results should be sent to `stdout`.

- **File**: exercises/garble.c