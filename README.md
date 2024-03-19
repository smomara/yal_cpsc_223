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
01/25/22 | Lecture 1 | Introduction. What the course is about. Getting started with C: running the compiler, the `main` function, program structure, basic integer data types | [The Linux programming environment](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#linux), [developing on your own machine](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#developingOnYourOwnMachine), [Structure of a C program](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#CProgramStructure), [Basic integer types](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#basicIntegerTypes), K&R §§1.1, 1.2
01/28/22 | Lecture 2 | Arithmetic in C | [Integer Types in C](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#integerTypes), [Floating-point types](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#floatingPointTypes), K&R §§2.2, 2.3, 2.5
01/31/22 | Lecture 3 | Statements and control flow: `if`, `while`, `for`, `do...while`. Relational and logical operators: `<`, `<=`, `==`, `!=`, `>=`, `>`, `&&`, `\|\|`, `!`, `?:`, and `,`. More assignment operators: `+=` and friends, `++` and `--` | [Statements](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#statements), K&R §§1.5, 2.6, 2.8, 2.10, 2.12, 3.1, 3.2, 3.3, 3.5, and 3.6
02/02/22 | Lecture 4 | Character I/O using `getchar`, `putchar`, and `ungetc`. Goto-like statements: `switch`, `break`, `continue`, and `goto` | [Reading and writing single characters](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#characterIO), K&R §§1.5, 3.7, and 3.8
02/03/22 | Assignment 1 | Hello, World! | [Assignment 1](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw1-2022)
02/07/22 | Lecture 5 | Functions | [Functions](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#functions), K&R §§4.1–4.5
02/09/22 | Lecture 6 | Start of pointers and arrays: pointer types and pointer variables. The `&` and `*` operators. Using a pointer to get a value out of a function. Array declarations | [Pointers up through Arrays](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#pointers), K&R §§5.1–5.4
02/10/22 | Assignment 2 | Transposition | [Assignment 2](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw2-2022)
02/14/22 | Lecture 7 | Strings: basic idea of null-terminated strings, how C interacts with Unicode, `char *` vs. `const char *`, `argv`, various pointer hackery involving `*` and `++` | [Strings](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#strings), K&R §5.5
02/16/22 | Lecture 8 | Storage allocation: `malloc`, `calloc`, `free`, and `realloc`. The `void *` pointer type. Finding storage allocation bugs using valgrind | [Run-time storage allocation using malloc](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#malloc), [Valgrind](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#valgrind)
02/17/22 | Assignment 3 | BCD Arithmetic | [Assignment 3](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw3-2022)
02/21/22 | Lecture 9 | Using `realloc` to deal with data of unknown size. Basics of debugging with gdb and valgrind | [Debugging](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#debugging), [Dynamic arrays for a bit more about use of realloc](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#dynamicArrays)
02/23/22 | Lecture 10 | Structured data types: structs, unions, and enums | [Structured data types](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#structuredDataTypes), K&R Chapter 6, §2.5 (for enums)
02/24/22 | Assignment 4 | Split and Join String Operations | [Assignment 4](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw4-2022)
02/28/22 | Lecture 11 | Managing large C programs. More on source files vs header files. Controlling information with typedefs. Linking and make. The `stdio.h` library and file I/O | [Function declarations and modules](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#functionDeclarations), [Static functions](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#staticFunctions), [Make](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#make), [File I/O](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#fileIO)
03/02/22 | Lecture 12 | Recursion | [Recursion](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#recursion)
03/03/22 | Assignment 5 | Hypercomplex Number Arithmetic Library | [Assignment 5](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw5-2022)
03/07/22 | Lecture 13 | Worst-case and amortized efficiency of data structures. Linked lists and stacks | [Asymptotic notation](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#asymptoticNotation), [Linked lists](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#linkedLists)
03/09/22 | Lecture 14 | Designing and implementing abstract data types: abstraction barriers, information hiding principle, representations invariants, and abstraction functions. Examples of abstract data types often implemented with linked lists: bags, stacks. queues, and deques. Doubly-linked lists | [Abstract data types](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#abstractDataTypes)
03/10/22 | Assignment 6 | Macro Processor | [Assignment 6](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw6-2022)
03/14/22 | Lecture 15 | Set and map abstract data types. Hash tables. A very small preview of using function pointers for iteration | [Hash tables](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hashTables)
03/16/22 | Lecture 16 | Function pointers and applications: `qsort`, dispatch tables, callbacks, closures | [Function pointers](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#functionPointers), K&R §5.11
03/17/22 | Assignment 7 | Map of a Maze | [Assignment 7](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw7-2022)
03/28/22 | Lecture 17 | Generic containers; object-oriented programming in C | [Generic containers](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#genericContainers), [Object-oriented programming](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#oopInC)
03/30/22 | Lecture 18 | Trees. Structure of trees. Standard tree algorithms. Parse trees and recursive descent parsing | [Trees](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#trees), [Recursive descent parsing](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#recursiveDescent)
03/31/22 | Assignment 8 | Telegraph-Style Commercial Code Decoder | [Assignment 8](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw8-2022)
04/04/22 | Lecture 19 | Heaps | [Heaps](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#heaps)
04/06/22 | Lecture 20 | Start of binary search trees. Basic binary search tree algorithms. Preview of tree rotation | [Binary search trees](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#binarySearchTrees)
04/07/22 | Assignment 9 | Infinite Stream Data Structure | [Assignment 9](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw9-2022)
04/11/22 | Lecture 21 | Balanced binary search trees: Treaps | [Treaps](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#treaps)
04/13/22 | Lecture 22 | Augmented trees (carrying over from previous lecture; added improved treeSize and treeDepth functions). Timing and profiling. Optimizing for performance | [Augmented trees](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#augmentedTrees), [Performance tuning](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#performanceTuning)
04/14/22 | Assignment 10 | Greedy Trash Collecting | [Assignment 10](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw10-2022)
04/18/22 | Lecture 23 | Graphs: structure and representations | [Graphs up to start of Graph search](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#graphs)
04/20/22 | Lecture 24 | Graph search: DFS and BFS algorithms | [Graph search](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#graphSearch)
04/21/22 | Assignment 11 | Expandable Vector Type | [Assignment 11](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw11-2022)
04/25/22 | Lecture 25 | Data structures for strings: tries and TSTs; radix sort | [String processing](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#stringProcessing)
04/27/22 | Lecture 26 | Dynamic programming: basics, all-pairs shortest paths, longest increasing subsequence, longest common subsequence | [Dynamic programming](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#dynamicProgramming)
04/28/22 | Assignment 12 | Majority Dynamics Simulator | [Assignment 12](http://cs.yale.edu/homes/aspnes/classes/223/notes.html#hw12-2022)