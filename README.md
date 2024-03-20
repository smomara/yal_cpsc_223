# Yale CPSC 223: Data Structures and Programming Techniques (Spring 2022)

This repository is designed to be a valuable resource for individuals interested in engaging with the course materials for CPSC 223: Data Structures and Programming Techniques, as offered in Spring 2022 through the Yale Zoo website. It provides a comprehensive overview of the course structure, including a detailed schedule that outlines readings and homework assignments in the sequence they were originally presented.

This repository is based on [James Aspnes' notes](http://cs.yale.edu/homes/aspnes/classes/223/notes.html) from his course offering hosted on the Zoo Website. A [markdown version](notes.md) is available in this repository, as well.

## Overview

### Course Description

Topics include programming in C; data structures (arrays, stacks, queues, lists, trees, heaps, graphs); sorting and searching; storage allocation and management; data abstraction; programming style; testing and debugging; writing efficient programs.

### Textbook
* [The C Programming Language (2nd Edition)](resources/K&R.pdf), by Brian W. Kernighan and Dennis M. Ritchie. Prentice Hall, 1988. ISBN 0131103628. The definitive introduction to C. You should memorize this book.

## Course Schedule

The following table is an aggregation of the reading assignments, homework assingments, and the lecture schedule from the [course's web page](cs.yale.edu/homes/aspnes/classes/223/notes.html) on the Yale Zoo website. Homework assignments appear on the date they are due.

Bear in mind these dates are from the Spring 2022 offering of the course.

Date | Item | Topic | Materials
-|-|-|-
01/25/22 | Lecture 1 | Introduction. What the course is about. Getting started with C: running the compiler, the `main` function, program structure, basic integer data types | [The Linux programming environment](notes.md#3-the-linux-programming-environment), [developing on your own machine](notes.md#24-developing-on-your-own-machine), [Structure of a C program](notes.md#41-structure-of-a-c-program), [Basic integer types](notes.md#4211-basic-integer-types), K&R §§1.1, 1.2
01/28/22 | Lecture 2 | Arithmetic in C | [Integer Types in C](notes.md#421-integer-types-in-c), [Floating-point types](notes.md#423-floating-point-types), K&R §§2.2, 2.3, 2.5
01/31/22 | Lecture 3 | Statements and control flow: `if`, `while`, `for`, `do...while`. Relational and logical operators: `<`, `<=`, `==`, `!=`, `>=`, `>`, `&&`, `\|\|`, `!`, `?:`, and `,`. More assignment operators: `+=` and friends, `++` and `--` | [Statements](notes.md#47-statements-and-control-structures), K&R §§1.5, 2.6, 2.8, 2.10, 2.12, 3.1, 3.2, 3.3, 3.5, and 3.6
02/02/22 | Lecture 4 | Character I/O using `getchar`, `putchar`, and `ungetc`. Goto-like statements: `switch`, `break`, `continue`, and `goto` | [Reading and writing single characters](notes.md#462-reading-and-writing-single-characters), K&R §§1.5, 3.7, and 3.8
02/03/22 | Assignment 1 | Hello, World! | [Assignment 1](notes.html#81-assignment-1-due-2022-02-03-at-1700)
02/07/22 | Lecture 5 | Functions | [Functions](notes.md#48-functions), K&R §§4.1–4.5
02/09/22 | Lecture 6 | Start of pointers and arrays: pointer types and pointer variables. The `&` and `*` operators. Using a pointer to get a value out of a function. Array declarations | [Pointers up through Arrays](notes.md#49-pointers), K&R §§5.1–5.4
02/10/22 | Assignment 2 | Transposition | [Assignment 2](notes.html#81-assignment-2-due-2022-02-10-at-1700)
02/14/22 | Lecture 7 | Strings: basic idea of null-terminated strings, how C interacts with Unicode, `char *` vs. `const char *`, `argv`, various pointer hackery involving `*` and `++` | [Strings](notes.md#410-strings), K&R §5.5
02/16/22 | Lecture 8 | Storage allocation: `malloc`, `calloc`, `free`, and `realloc`. The `void *` pointer type. Finding storage allocation bugs using valgrind | [Run-time storage allocation using malloc](notes.md#497-run-time-storage-allocation-using-malloc), [Valgrind](notes.md#344-valgrind)
02/17/22 | Assignment 3 | BCD Arithmetic | [Assignment 3](notes.html#83-assignment-3-due-2022-02-17-at-1700)
02/21/22 | Lecture 9 | Using `realloc` to deal with data of unknown size. Basics of debugging with gdb and valgrind | [Debugging](notes.md#34-debugging-tools), [Dynamic arrays for a bit more about use of realloc](notes.md#52-dynamic-arrays)
02/23/22 | Lecture 10 | Structured data types: structs, unions, and enums | [Structured data types](notes.md#411-structured-data-types), K&R Chapter 6, §2.5 (for enums)
02/24/22 | Assignment 4 | Split and Join String Operations | [Assignment 4](notes.html#84-assignment-4-due-2022-02-24-at-1700)
02/28/22 | Lecture 11 | Managing large C programs. More on source files vs header files. Controlling information with typedefs. Linking and make. The `stdio.h` library and file I/O | [Function declarations and modules](notes.md#485-function-declarations-and-modules), [Static functions](notes.md#486-static-functions), [Make](notes.md#332-make), [File I/O](notes.md#466-file-io)
03/02/22 | Lecture 12 | Recursion | [Recursion](notes.md#53-recursion)
03/03/22 | Assignment 5 | Hypercomplex Number Arithmetic Library | [Assignment 5](notes.html#85-assignment-5-due-2022-03-03-at-1700)
03/07/22 | Lecture 13 | Worst-case and amortized efficiency of data structures. Linked lists and stacks | [Asymptotic notation](notes.md#51-asymptotic-notation), [Linked lists](notes.md#54-linked-lists)
03/09/22 | Lecture 14 | Designing and implementing abstract data types: abstraction barriers, information hiding principle, representations invariants, and abstraction functions. Examples of abstract data types often implemented with linked lists: bags, stacks. queues, and deques. Doubly-linked lists | [Abstract data types](notes.md#55-abstract-data-types)
03/10/22 | Assignment 6 | Macro Processor | [Assignment 6](notes.html#86-assignment-6-due-2022-03-10-at-1700)
03/14/22 | Lecture 15 | Set and map abstract data types. Hash tables. A very small preview of using function pointers for iteration | [Hash tables](notes.md#56-hash-tables)
03/16/22 | Lecture 16 | Function pointers and applications: `qsort`, dispatch tables, callbacks, closures | [Function pointers](notes.md#498-function-pointers), K&R §5.11
03/17/22 | Assignment 7 | Map of a Maze | [Assignment 7](notes.html#87-assignment-7-due-2022-03-17-at-1700)
03/28/22 | Lecture 17 | Generic containers; object-oriented programming in C | [Generic containers](notes.md#57-generic-containers), [Object-oriented programming](notes.md#58-object-oriented-programming)
03/30/22 | Lecture 18 | Trees. Structure of trees. Standard tree algorithms. Parse trees and recursive descent parsing | [Trees](notes.md#59-trees), [Recursive descent parsing](notes.md#465-recursive-descent-parsing)
03/31/22 | Assignment 8 | Telegraph-Style Commercial Code Decoder | [Assignment 8](notes.html#88-assignment-8-due-2022-03-31-at-1700)
04/04/22 | Lecture 19 | Heaps | [Heaps](notes.md#510-heaps)
04/06/22 | Lecture 20 | Start of binary search trees. Basic binary search tree algorithms. Preview of tree rotation | [Binary search trees](notes.md#511-binary-search-trees)
04/07/22 | Assignment 9 | Infinite Stream Data Structure | [Assignment 9](notes.html#89-assignment-9-due-2022-04-07-at-1700)
04/11/22 | Lecture 21 | Balanced binary search trees: Treaps | [Treaps](notes.md#5132-treaps)
04/13/22 | Lecture 22 | Augmented trees (carrying over from previous lecture; added improved treeSize and treeDepth functions). Timing and profiling. Optimizing for performance | [Augmented trees](notes.md#512-augmented-trees), [Performance tuning](notes.md#35-performance-tuning)
04/14/22 | Assignment 10 | Greedy Trash Collecting | [Assignment 10](notes.md#810-assignment-10-due-2022-04-14-at-2359)
04/18/22 | Lecture 23 | Graphs: structure and representations | [Graphs up to start of Graph search](notes.md#514-graphs)
04/20/22 | Lecture 24 | Graph search: DFS and BFS algorithms | [Graph search](notes.md#5145-searching-for-paths-in-a-graph)
04/21/22 | Assignment 11 | Expandable Vector Type | [Assignment 11](notes.md#811-assignment-11-due-2022-04-21-at-2359)
04/25/22 | Lecture 25 | Data structures for strings: tries and TSTs; radix sort | [String processing](notes.md#517-string-processing)
04/27/22 | Lecture 26 | Dynamic programming: basics, all-pairs shortest paths, longest increasing subsequence, longest common subsequence | [Dynamic programming](notes.md#515-dynamic-programming)
04/28/22 | Assignment 12 | Majority Dynamics Simulator | [Assignment 12](notes.md#812-assignment-12-due-2022-04-28-at-2359)