Notes on Data Structures and Programming Techniques (CPSC 223, Spring 2022) 

Notes on Data Structures and Programming Techniques (CPSC 223, Spring 2022)
===========================================================================

James Aspnes

2023-09-25T21:31:32-0400

*   [1 Course administration](#courseAdministration)
    *   [1.1 Overview](#index)
        *   [1.1.1 License](#license)
        *   [1.1.2 Resources](#resources)
        *   [1.1.3 Documentation](#Documentation)
        *   [1.1.4 Questions and comments](#questions-and-comments)
    *   [1.2 Lecture schedule](#schedule)
    *   [1.3 Syllabus](#syllabus)
        *   [1.3.1 On-line course information](#On-line_course_information)
        *   [1.3.2 Meeting times](#Meeting_times)
        *   [1.3.3 Course synopsis](#Course_synopsis)
        *   [1.3.4 Prerequisites](#Prerequisites)
        *   [1.3.5 Textbook](#Textbook)
        *   [1.3.6 Course requirements](#Course_requirements)
        *   [1.3.7 Staff](#staff)
            *   [1.3.7.1 Instructor](#instructor)
            *   [1.3.7.2 Undergraduate Learning Assistants](#undergraduate-learning-assistants)
        *   [1.3.8 Use of outside help](#Use_of_outside_help)
        *   [1.3.9 Clarifications for homework assignments](#Clarifications_for_homework_assignments)
        *   [1.3.10 Late assignments](#Late_assignments)
    *   [1.4 Introduction](#introduction)
        *   [1.4.1 Why should you learn to program in C?](#whyC)
        *   [1.4.2 Why should you learn about data structures and programming techniques?](#why-should-you-learn-about-data-structures-and-programming-techniques)
*   [2 The Zoo](#zoo)
    *   [2.1 Getting an account](#Getting_an_account)
    *   [2.2 Getting into the room](#Getting_into_the_room)
    *   [2.3 Remote use](#Remote_use)
        *   [2.3.1 Terminal access](#zooSSH)
        *   [2.3.2 GUI access](#GUI_access)
    *   [2.4 Developing on your own machine](#developingOnYourOwnMachine)
        *   [2.4.1 Linux](#linuxDevelopment)
        *   [2.4.2 OSX](#OSXDevelopment)
        *   [2.4.3 Windows](#WindowsDevelopment)
    *   [2.5 How to compile and run programs](#compiling)
        *   [2.5.1 Creating the program](#Creating_the_program)
        *   [2.5.2 Compiling and running a program](#Compiling_and_running_a_program)
        *   [2.5.3 Some notes on what the program does](#Some_notes_on_what_the_program_does)
*   [3 The Linux programming environment](#linux)
    *   [3.1 The shell](#the-shell)
        *   [3.1.1 Getting a shell prompt in the Zoo](#Getting_a_shell_prompt_in_the_Zoo)
        *   [3.1.2 The Unix filesystem](#The_Unix_filesystem)
        *   [3.1.3 Unix command-line programs](#Unix_command-line_programs)
        *   [3.1.4 Stopping and interrupting programs](#Stopping_and_interrupting_programs)
        *   [3.1.5 Running your own programs](#Running_your_own_programs)
        *   [3.1.6 Redirecting input and output](#shellRedirects)
    *   [3.2 Text editors](#editing)
        *   [3.2.1 Writing C programs with Emacs](#Writing_C_programs_with_Emacs)
            *   [3.2.1.1 My favorite Emacs commands](#My_favorite_Emacs_commands)
        *   [3.2.2 Using Vi instead of Emacs](#Using_Vi_instead_of_Emacs)
            *   [3.2.2.1 My favorite Vim commands](#My_favorite_Vim_commands)
                *   [3.2.2.1.1 Normal mode](#Normal_mode)
                *   [3.2.2.1.2 Insert mode](#Insert_mode)
            *   [3.2.2.2 Settings](#Settings)
    *   [3.3 Compilation tools](#compilationTools)
        *   [3.3.1 The GNU C compiler `gcc`](#gcc)
        *   [3.3.2 Make](#make)
            *   [3.3.2.1 Make gotchas](#Make_gotchas)
    *   [3.4 Debugging tools](#debugging)
        *   [3.4.1 Debugging in general](#Debugging_in_general)
        *   [3.4.2 Assertions](#Assertions)
        *   [3.4.3 The GNU debugger `gdb`](#gdb)
            *   [3.4.3.1 My favorite gdb commands](#My_favorite_gdb_commands)
            *   [3.4.3.2 Debugging strategies](#Debugging_strategies)
            *   [3.4.3.3 Common applications of `gdb`](#common-applications-of-gdb)
                *   [3.4.3.3.1 Watching your program run](#watching-your-program-run)
                *   [3.4.3.3.2 Dealing with failed assertions](#dealing-with-failed-assertions)
                *   [3.4.3.3.3 Dealing with segmentation faults](#dealing-with-segmentation-faults)
                *   [3.4.3.3.4 Dealing with infinite loops](#dealing-with-infinite-loops)
                *   [3.4.3.3.5 Mysterious variable changes](#mysterious-variable-changes)
        *   [3.4.4 Valgrind](#valgrind)
            *   [3.4.4.1 Compilation flags](#Compilation_flags)
            *   [3.4.4.2 Automated testing](#Automated_testing)
            *   [3.4.4.3 Examples of some common valgrind errors](#Examples_of_some_common_valgrindErrors)
                *   [3.4.4.3.1 Uninitialized values](#Uninitialized_values)
                *   [3.4.4.3.2 Bytes definitely lost](#Bytes_definitely_lost)
                *   [3.4.4.3.3 Invalid write or read operations](#Invalid_write_or_read_operations)
        *   [3.4.5 Not recommended: debugging output](#Not_recommended:_debugging_output)
    *   [3.5 Performance tuning](#performanceTuning)
        *   [3.5.1 Timing under Linux](#Timing_under_Linux)
        *   [3.5.2 Profiling with `valgrind`](#profiling)
        *   [3.5.3 Profiling with `gprof`](#profilingGprof)
            *   [3.5.3.1 Effect of optimization during compilation](#effect-of-optimization-during-compilation)
    *   [3.6 Version control](#versionControl)
        *   [3.6.1 Setting up Git](#Setting_up_Git)
        *   [3.6.2 Editing files](#Editing_files)
        *   [3.6.3 Renaming files](#Renaming_files)
        *   [3.6.4 Adding and removing files](#Adding_and_removing_files)
        *   [3.6.5 Recovering files from the repository](#Recovering_files_from_the_repository)
        *   [3.6.6 Undoing bad commits](#Undoing_bad_commits)
        *   [3.6.7 Looking at old versions](#Looking_at_old_versions)
        *   [3.6.8 More information about Git](#More_information_about_Git)
    *   [3.7 Submitting assignments](#submitScript)
*   [4 The C programming language](#c)
    *   [4.1 Structure of a C program](#CProgramStructure)
    *   [4.2 Numeric data types](#numericTypes)
        *   [4.2.1 Integer types in C](#integerTypes)
            *   [4.2.1.1 Basic integer types](#basicIntegerTypes)
            *   [4.2.1.2 Overflow and the C standards](#overflow-and-the-c-standards)
            *   [4.2.1.3 C99 fixed-width types](#C99_fixed-width_types)
        *   [4.2.2 `size_t` and `ptrdiff_t`](#sizeTypes)
            *   [4.2.2.1 Integer constants](#integerConstants)
                *   [4.2.2.1.1 Naming constants](#naming-constants)
            *   [4.2.2.2 Integer operators](#integerOperators)
                *   [4.2.2.2.1 Arithmetic operators](#arithmeticOperators)
                *   [4.2.2.2.2 Bitwise operators](#Bitwise_operators)
                *   [4.2.2.2.3 Logical operators](#Logical_operators)
                *   [4.2.2.2.4 Relational operators](#Relational_operators)
            *   [4.2.2.3 Converting to and from strings](#integerStringConversion)
        *   [4.2.3 Floating-point types](#floatingPointTypes)
            *   [4.2.3.1 Floating point basics](#Floating_point_basics)
            *   [4.2.3.2 Floating-point constants](#Floating-point_constants)
            *   [4.2.3.3 Operators](#operators)
            *   [4.2.3.4 Conversion to and from integer types](#Conversion_to_and_from_integer_types)
            *   [4.2.3.5 The IEEE-754 floating-point standard](#The_IEEE-754_floating-point_standard)
            *   [4.2.3.6 Round-off error](#Round-off-error)
            *   [4.2.3.7 Reading and writing floating-point numbers](#Reading_and_writing_floating-point_numbers)
            *   [4.2.3.8 Non-finite numbers in C](#Non-finite_numbers_in_C)
            *   [4.2.3.9 The math library](#mathLibrary)
    *   [4.3 Operator precedence](#operatorPrecedence)
    *   [4.4 Programming style](#programmingStyle)
    *   [4.5 Variables](#variables)
        *   [4.5.1 Memory](#MachineMemory)
        *   [4.5.2 Variables as names](#variablesAsNames)
            *   [4.5.2.1 Variable declarations](#Variable_declarations)
            *   [4.5.2.2 Variable names](#Variable_names)
        *   [4.5.3 Using variables](#usingVariables)
        *   [4.5.4 Initialization](#initializers)
        *   [4.5.5 Storage class qualifiers](#qualifiers)
            *   [4.5.5.1 Scope and extent](#scopeAndExtent)
                *   [4.5.5.1.1 Additional qualifiers for global variables](#additional-qualifiers-for-global-variables)
        *   [4.5.6 Marking variables as constant](#const)
            *   [4.5.6.1 Pointers to `const`](#pointers-to-const)
    *   [4.6 Input and output](#IO)
        *   [4.6.1 Character streams](#Character_streams)
        *   [4.6.2 Reading and writing single characters](#characterIO)
        *   [4.6.3 Formatted I/O](#Formatted_IO)
        *   [4.6.4 Rolling your own I/O routines](#Rolling_your_own_IO_routines)
        *   [4.6.5 Recursive descent parsing](#recursiveDescentParsing)
        *   [4.6.6 File I/O](#FileIO)
    *   [4.7 Statements and control structures](#statements)
        *   [4.7.1 Simple statements](#Simple_statements)
        *   [4.7.2 Compound statements](#Compound_statements)
            *   [4.7.2.1 Conditionals](#conditionals)
            *   [4.7.2.2 Loops](#Loops)
                *   [4.7.2.2.1 The while loop](#The_while_loop)
                *   [4.7.2.2.2 The do..while loop](#The_do..while_loop)
                *   [4.7.2.2.3 The for loop](#forLoop)
                *   [4.7.2.2.4 Loops with break, continue, and goto](#gotoLikeStatements)
            *   [4.7.2.3 Choosing where to put a loop exit](#Choosing_where_to_put_a_loop_exit)
    *   [4.8 Functions](#functions)
        *   [4.8.1 Function definitions](#functionDefinitions)
        *   [4.8.2 When to write a function](#functionIdeology)
        *   [4.8.3 Calling a function](#Calling_a_function)
        *   [4.8.4 The return statement](#return)
        *   [4.8.5 Function declarations and modules](#modules)
        *   [4.8.6 Static functions](#staticFunctions)
        *   [4.8.7 Local variables](#Local_variables)
        *   [4.8.8 Mechanics of function calls](#Mechanics_of_function_calls)
    *   [4.9 Pointers](#pointers)
        *   [4.9.1 Memory and addresses](#addressSpace)
        *   [4.9.2 Pointer variables](#Pointer_variables)
            *   [4.9.2.1 Declaring a pointer variable](#Declaring_a_pointer_variable)
            *   [4.9.2.2 Assigning to pointer variables](#Assigning_to_pointer_variables)
            *   [4.9.2.3 Using a pointer](#Using_a_pointer)
            *   [4.9.2.4 Printing pointers](#Printing_pointers)
        *   [4.9.3 The null pointer](#The_null_pointer)
        *   [4.9.4 Pointers and functions](#Pointers_and_functions)
        *   [4.9.5 Pointer arithmetic and arrays](#pointerArithmetic)
            *   [4.9.5.1 Arrays](#arrays)
            *   [4.9.5.2 Arrays and functions](#arraysAndFunctions)
            *   [4.9.5.3 Multidimensional arrays](#multidimensionalArrays)
                *   [4.9.5.3.1 Using built-in C arrays](#multidimensionalStandard)
                *   [4.9.5.3.2 Using an array of pointers to rows](#arrayOfPointersToRows)
                *   [4.9.5.3.3 Using a one-dimensional array](#packedTwoDimensionalArray)
            *   [4.9.5.4 Variable-length arrays](#variableLengthArrays)
                *   [4.9.5.4.1 Why you shouldn’t use variable-length arrays](#why-you-shouldnt-use-variable-length-arrays)
        *   [4.9.6 Pointers to void](#voidPointers)
            *   [4.9.6.1 Alignment](#alignment)
        *   [4.9.7 Run-time storage allocation using `malloc`](#malloc)
        *   [4.9.8 Function pointers](#functionPointers)
            *   [4.9.8.1 Function pointer declarations](#Function_pointer_declarations)
            *   [4.9.8.2 Callbacks](#Callbacks)
            *   [4.9.8.3 Dispatch tables](#Dispatch_tables)
        *   [4.9.9 The restrict keyword](#The_restrict_keyword)
    *   [4.10 Strings](#strings)
        *   [4.10.1 C strings](#C_strings)
        *   [4.10.2 String constants](#String_constants)
            *   [4.10.2.1 String encodings](#string-encodings)
        *   [4.10.3 String buffers](#String_buffers)
            *   [4.10.3.1 String buffers and the perils of `gets`](#string-buffers-and-the-perils-of-gets)
        *   [4.10.4 Operations on strings](#Operations_on_strings)
        *   [4.10.5 Finding the length of a string](#Finding_the_length_of_a_string)
            *   [4.10.5.1 The strlen tarpit](#The_strlen_tarpit)
        *   [4.10.6 Comparing strings](#Comparing_strings)
        *   [4.10.7 Formatted output to strings](#Formatted_output_to_strings)
        *   [4.10.8 Dynamic allocation of strings](#Dynamic_allocation_of_strings)
        *   [4.10.9 Command-line arguments](#argv)
    *   [4.11 Structured data types](#structuredDataTypes)
        *   [4.11.1 Structs](#structs)
            *   [4.11.1.1 Operations on structs](#operations-on-structs)
            *   [4.11.1.2 Layout in memory](#structLayout)
            *   [4.11.1.3 Bit fields](#Bit_fields)
        *   [4.11.2 Unions](#unions)
        *   [4.11.3 Enums](#enums)
            *   [4.11.3.1 Specifying particular values](#specifying-particular-values)
            *   [4.11.3.2 What most people do](#what-most-people-do)
            *   [4.11.3.3 Using `enum` with `union`](#enumTagsForUnion)
    *   [4.12 Type aliases using `typedef`](#typedef)
        *   [4.12.1 Opaque structs](#opaqueStructs)
    *   [4.13 Macros](#macros)
        *   [4.13.1 Macros with arguments](#Macros_with_arguments)
            *   [4.13.1.1 Multiple arguments](#Multiple_arguments)
            *   [4.13.1.2 Perils of repeating arguments](#Perils_of_repeating_arguments)
            *   [4.13.1.3 Variable-length argument lists](#Variable-length_argument_lists)
            *   [4.13.1.4 Macros vs. inline functions](#macros-vs.-inline-functions)
        *   [4.13.2 Macros that include other macros](#Multiple_macros)
        *   [4.13.3 More specialized macros](#Macro_tricks)
            *   [4.13.3.1 Multiple expressions in a macro](#Multiple_expressions_in_a_macro)
            *   [4.13.3.2 Non-syntactic macros](#nonSyntacticMacros)
            *   [4.13.3.3 Multiple statements in one macro](#Multiple_statements_in_one_macro)
            *   [4.13.3.4 String expansion](#String_expansion)
            *   [4.13.3.5 Big macros](#Big_macros)
        *   [4.13.4 Conditional compilation](#ifdef)
        *   [4.13.5 Defining macros on the command line](#defining-macros-on-the-command-line)
        *   [4.13.6 The `#if` directive](#the-if-directive)
        *   [4.13.7 Debugging macro expansions](#Debugging_macro_expansions)
        *   [4.13.8 Can a macro call a preprocessor command?](#Can_a_macro_call_a_preprocessor_command.3F)
*   [5 Data structures and programming techniques](#dataStructuresAndProgrammingTechniques)
    *   [5.1 Asymptotic notation](#asymptoticNotation)
        *   [5.1.1 Two sorting algorithms](#two-sorting-algorithms)
        *   [5.1.2 Big-O to the rescue](#big-o-to-the-rescue)
        *   [5.1.3 Asymptotic cost of programs](#asymptotic-cost-of-programs)
        *   [5.1.4 Other variants of asymptotic notation](#other-variants-of-asymptotic-notation)
    *   [5.2 Dynamic arrays](#dynamicArrays)
    *   [5.3 Recursion](#recursion)
        *   [5.3.1 Example of recursion in C](#Example_of_recursion_in_C)
        *   [5.3.2 Common problems with recursion](#Common_problems_with_recursion)
            *   [5.3.2.1 Omitting the base case](#Omitting_the_base_case)
            *   [5.3.2.2 Blowing out the stack](#Blowing_out_the_stack)
            *   [5.3.2.3 Failure to make progress](#Failure_to_make_progress)
        *   [5.3.3 Tail-recursion and iteration](#tailRecursion)
            *   [5.3.3.1 Binary search: recursive and iterative versions](#binarySearch)
        *   [5.3.4 Mergesort: a recursive sorting algorithm](#mergesort)
        *   [5.3.5 Asymptotic complexity of recursive functions](#asymptotic-complexity-of-recursive-functions)
    *   [5.4 Linked lists](#linkedLists)
        *   [5.4.1 Stacks](#stacks)
            *   [5.4.1.1 Building a stack out of an array](#Building_a_stack_out_of_an_array)
        *   [5.4.2 Queues](#queues)
        *   [5.4.3 Looping over a linked list](#Looping_over_a_linked_list)
        *   [5.4.4 Looping over a linked list backwards](#Looping_over_a_linked_list_backwards)
        *   [5.4.5 Deques and doubly-linked lists](#deques)
            *   [5.4.5.1 Alternate implementation using a ring buffer](#ringBuffers)
        *   [5.4.6 Circular linked lists](#Circular_linked_lists)
        *   [5.4.7 What linked lists are and are not good for](#What_linked_lists_are_and_are_not_good_for)
        *   [5.4.8 Further reading](#Further_reading)
    *   [5.5 Abstract data types](#abstractDataTypes)
        *   [5.5.1 Boxed vs unboxed types](#boxedVsUnboxedTypes)
            *   [5.5.1.1 A danger with unboxed types](#a-danger-with-unboxed-types)
        *   [5.5.2 A sequence type](#abstractDataTypeExample)
            *   [5.5.2.1 Interface](#Interface)
            *   [5.5.2.2 Implementation](#adtImplementation)
            *   [5.5.2.3 Compiling and linking](#Compiling_and_linking)
        *   [5.5.3 Designing abstract data types](#Designing_abstract_data_types)
            *   [5.5.3.1 Parnas’s Principle](#Parnas.27s_Principle)
            *   [5.5.3.2 When to build an abstract data type](#When_to_build_an_abstract_data_type)
    *   [5.6 Hash tables](#hashTables)
        *   [5.6.1 Dictionary data types](#dictionaries)
        *   [5.6.2 Basics of hashing](#Basics_of_hashing)
        *   [5.6.3 Resolving collisions](#Resolving_collisions)
            *   [5.6.3.1 Chaining](#Chaining)
            *   [5.6.3.2 Open addressing](#Open_addressing)
        *   [5.6.4 Choosing a hash function](#Choosing_a_hash_function)
            *   [5.6.4.1 Division method](#Division_method)
            *   [5.6.4.2 Multiplication method](#Multiplication_method)
            *   [5.6.4.3 Universal hashing](#Universal_hashing)
        *   [5.6.5 Maintaining a constant load factor](#Maintaining_a_constant_load_factor)
        *   [5.6.6 Examples](#Examples)
            *   [5.6.6.1 A low-overhead hash table using open addressing](#A_low-overhead_hash_table_using_open_addressing)
            *   [5.6.6.2 A string to string dictionary using chaining](#A_string_to_string_dictionary_using_chaining)
    *   [5.7 Generic containers](#genericContainers)
        *   [5.7.1 Generic dictionary: interface](#Generic_dictionary:_interface)
        *   [5.7.2 Generic dictionary: implementation](#genericDictionaryImplementation)
    *   [5.8 Object-oriented programming](#objectOrientedProgramming)
    *   [5.9 Trees](#trees)
        *   [5.9.1 Tree basics](#Tree_basics)
        *   [5.9.2 Tree-structured data](#treeStructuredData)
        *   [5.9.3 Binary trees](#binaryTrees)
        *   [5.9.4 The canonical binary tree algorithm](#The_canonical_binary_tree_algorithm)
        *   [5.9.5 Nodes vs leaves](#Nodes_vs_leaves)
        *   [5.9.6 Special classes of binary trees](#Special_classes_of_binary_trees)
    *   [5.10 Heaps](#heaps)
        *   [5.10.1 Priority queues](#priorityQueues)
        *   [5.10.2 Expensive implementations of priority queues](#Expensive_implementations_of_priority_queues)
        *   [5.10.3 Structure of a heap](#heapStructure)
        *   [5.10.4 Packed heaps](#Packed_heaps)
        *   [5.10.5 Bottom-up heapification](#Bottom-up_heapification)
        *   [5.10.6 Heapsort](#heapSort)
        *   [5.10.7 More information](#heapMoreInformation)
    *   [5.11 Binary search trees](#binarySearchTrees)
        *   [5.11.1 Searching for a node](#Searching_for_a_node)
        *   [5.11.2 Inserting a new node](#Inserting_a_new_node)
        *   [5.11.3 Deleting a node](#deleting-a-node)
        *   [5.11.4 Costs](#Costs)
    *   [5.12 Augmented trees](#augmentedTrees)
        *   [5.12.1 Applications](#applications)
    *   [5.13 Balanced trees](#balancedTrees)
        *   [5.13.1 Tree rotations](#treeRotations)
        *   [5.13.2 Treaps](#treaps)
        *   [5.13.3 AVL trees](#AVLtrees)
            *   [5.13.3.1 Sample implementation](#avlTreeImplementation)
        *   [5.13.4 2–3 trees](#A2.2BIBM-3_trees)
        *   [5.13.5 Red-black trees](#redBlackTrees)
        *   [5.13.6 B-trees](#B-trees)
        *   [5.13.7 Splay trees](#splayTrees)
            *   [5.13.7.1 How splaying works](#how-splaying-works)
            *   [5.13.7.2 Analysis](#splayTreeAnalysis)
            *   [5.13.7.3 Other operations](#other-operations)
            *   [5.13.7.4 Top-down splaying](#top-down-splaying)
            *   [5.13.7.5 An implementation](#splayTreeImplementation)
            *   [5.13.7.6 More information](#splayTreesMoreInformation)
        *   [5.13.8 Scapegoat trees](#scapegoatTrees)
        *   [5.13.9 Skip lists](#skip-lists)
        *   [5.13.10 Implementations](#treeImplementations)
    *   [5.14 Graphs](#graphs)
        *   [5.14.1 Basic definitions](#graphDefinitions)
        *   [5.14.2 Why graphs are useful](#Why_graphs_are_useful)
        *   [5.14.3 Operations on graphs](#Operations_on_graphs)
        *   [5.14.4 Representations of graphs](#Representations_of_graphs)
            *   [5.14.4.1 Adjacency matrices](#Adjacency_matrices)
            *   [5.14.4.2 Adjacency lists](#Adjacency_lists)
                *   [5.14.4.2.1 An implementation](#An_implementation)
            *   [5.14.4.3 Implicit representations](#Implicit_representations)
        *   [5.14.5 Searching for paths in a graph](#graphSearch)
            *   [5.14.5.1 Implementation of depth-first and breadth-first search](#graphSearchImplementation)
            *   [5.14.5.2 Combined implementation of depth-first and breadth-first search](#combinedDFSBFS)
            *   [5.14.5.3 Other variations on the basic algorithm](#Other_variations_on_the_basic_algorithm)
    *   [5.15 Dynamic programming](#dynamicProgramming)
        *   [5.15.1 Memoization](#Memoization)
        *   [5.15.2 Dynamic programming](#Dynamic_programming)
            *   [5.15.2.1 More examples](#More_examples)
                *   [5.15.2.1.1 Longest increasing subsequence](#Longest_increasing_subsequence)
                *   [5.15.2.1.2 All-pairs shortest paths](#All-pairs_shortest_paths)
                *   [5.15.2.1.3 Longest common subsequence](#longestCommonSubsequence)
    *   [5.16 Randomization](#randomization)
        *   [5.16.1 Generating random values in C](#Generating_random_values_in_C)
            *   [5.16.1.1 The `rand` function from the standard library](#The_rand_function_from_the_standard_library)
                *   [5.16.1.1.1 Supplying a seed with `srand`](#supplying-a-seed-with-srand)
            *   [5.16.1.2 Better pseudorandom number generators](#Better_pseudorandom_number_generators)
            *   [5.16.1.3 Random numbers without the pseudo](#Random_numbers_without_the_pseudo)
            *   [5.16.1.4 Range issues](#RANDMAX)
        *   [5.16.2 Randomized algorithms](#Randomized_algorithms)
            *   [5.16.2.1 Randomized search](#Randomized_search)
            *   [5.16.2.2 Quickselect and quicksort](#quicksort)
        *   [5.16.3 Randomized data structures](#randomizedDataStructures)
            *   [5.16.3.1 Skip lists](#skipLists)
            *   [5.16.3.2 Universal hash families](#Universal_hash_families)
    *   [5.17 String processing](#stringProcessing)
        *   [5.17.1 Radix search](#radixSearch)
            *   [5.17.1.1 Tries](#Tries)
                *   [5.17.1.1.1 Searching a trie](#Searching_a_trie)
                *   [5.17.1.1.2 Inserting a new element into a trie](#Inserting_a_new_element_into_a_trie)
                *   [5.17.1.1.3 Implementation](#trieImplementation)
            *   [5.17.1.2 Patricia trees](#Patricia_trees)
            *   [5.17.1.3 Ternary search trees](#ternarySearchTrees)
            *   [5.17.1.4 More information](#treesMoreInformation)
        *   [5.17.2 Radix sort](#radixSort)
            *   [5.17.2.1 Bucket sort](#Bucket_sort)
            *   [5.17.2.2 Classic LSB radix sort](#Classic_LSB_radix_sort)
            *   [5.17.2.3 MSB radix sort](#MSB_radix_sort)
                *   [5.17.2.3.1 Issues with recursion depth](#Issues_with_recursion_depth)
                *   [5.17.2.3.2 Implementing the buckets](#Implementing_the_buckets)
                *   [5.17.2.3.3 Further optimization](#Further_optimization)
                *   [5.17.2.3.4 Sample implementation](#radixSortImplementation)
*   [6 Other topics](#other-topics)
    *   [6.1 More applications of function pointers](#more-applications-of-function-pointers)
        *   [6.1.1 Iterators](#iterators)
            *   [6.1.1.1 Option 1: Function that returns a sequence](#Option_1:_Function_that_returns_a_sequence)
            *   [6.1.1.2 Option 2: Iterator with first/done/next operations](#Option_2:_Iterator_with_first.2Fdone.2Fnext_operations)
            *   [6.1.1.3 Option 3: Iterator with function argument](#Option_3:_Iterator_with_function_argument)
        *   [6.1.2 Closures](#closures)
        *   [6.1.3 Objects](#Objects)
    *   [6.2 Suffix arrays](#suffixArrays)
        *   [6.2.1 Why do we want to do this?](#Why_do_we_want_to_do_this.3F)
        *   [6.2.2 String search algorithms](#String_search_algorithms)
        *   [6.2.3 Suffix trees and suffix arrays](#Suffix_trees_and_suffix_arrays)
            *   [6.2.3.1 Building a suffix array](#Building_a_suffix_array)
            *   [6.2.3.2 Searching a suffix array](#Searching_a_suffix_array)
    *   [6.3 Burrows-Wheeler transform](#Burrows-Wheeler_transform)
        *   [6.3.1 Suffix arrays and the Burrows-Wheeler transform](#Suffix_arrays_and_the_Burrows-Wheeler_transform)
        *   [6.3.2 Sample implementation](#sample-implementation)
    *   [6.4 C++](#cplusplus)
        *   [6.4.1 Hello world](#Hello_world)
        *   [6.4.2 References](#References)
        *   [6.4.3 Function overloading](#Function_overloading)
        *   [6.4.4 Classes](#Classes)
        *   [6.4.5 Operator overloading](#Operator_overloading)
        *   [6.4.6 Templates](#Templates)
        *   [6.4.7 Exceptions](#Exceptions)
        *   [6.4.8 Storage allocation](#Storage_allocation)
            *   [6.4.8.1 Storage allocation inside objects](#Storage_allocation_inside_objects)
        *   [6.4.9 Standard library](#Standard_library)
        *   [6.4.10 Things we haven’t talked about](#Things_we_haven.27t_talked_about)
    *   [6.5 Testing during development](#testingDuringDevelopment)
        *   [6.5.1 Unit tests](#unitTests)
            *   [6.5.1.1 What to put in the test code](#what-to-put-in-the-test-code)
            *   [6.5.1.2 Example](#example)
        *   [6.5.2 Test harnesses](#test-harnesses)
            *   [6.5.2.1 Module interface](#Module_interface)
                *   [6.5.2.1.1 stack.h](#stack.h)
            *   [6.5.2.2 Test code](#Test_code)
                *   [6.5.2.2.1 test-stack.c](#test-stack.c)
            *   [6.5.2.3 Makefile](#Makefile)
                *   [6.5.2.3.1 Makefile](#Makefile-1)
        *   [6.5.3 Stub implementation](#Stub_implementation)
            *   [6.5.3.1 stack.c](#stack.c)
        *   [6.5.4 Bounded-space implementation](#Bounded-space_implementation)
            *   [6.5.4.1 stack.c](#stack.c-1)
        *   [6.5.5 First fix](#First_fix)
        *   [6.5.6 Final version](#Final_version)
            *   [6.5.6.1 stack.c](#stack.c-2)
        *   [6.5.7 Moral](#Moral)
        *   [6.5.8 Appendix: Test macros](#Appendix:_Test_macros)
    *   [6.6 Algorithm design techniques](#algorithmDesignTechniques)
        *   [6.6.1 Basic principles of algorithm design](#Basic_principles_of_algorithm_design)
        *   [6.6.2 Specific techniques](#algorithmDesignTechniquesClassification)
        *   [6.6.3 Example: Finding the maximum](#Example:_Finding_the_maximum)
        *   [6.6.4 Example: Sorting](#algorithmDesignSorting)
    *   [6.7 Bit manipulation](#bitManipulation)
    *   [6.8 Persistence](#persistence)
        *   [6.8.1 A simple solution using text files](#A_simple_solution_using_text_files)
        *   [6.8.2 Using a binary file](#Using_a_binary_file)
        *   [6.8.3 A version that updates the file in place](#A_version_that_updates_the_file_in_place)
        *   [6.8.4 An even better version using mmap](#An_even_better_version_using_mmap)
        *   [6.8.5 Concurrency and fault-tolerance issues: ACIDity](#Concurrency_and_fault-tolerance_issues:_ACIDity)
*   [7 What next?](#whatNext)
    *   [7.1 What’s wrong with C](#What.27s_wrong_with_C)
    *   [7.2 What C++ fixes](#What_C.2B-.2B-_fixes)
    *   [7.3 Other C-like languages](#other-c-like-languages)
    *   [7.4 Scripting languages](#Scripting_languages)
*   [8 Assignments](#assignments)
    *   [8.1 Assignment 1, due 2022-02-03 at 17:00](#hw1-2022)
        *   [8.1.1 Bureaucratic part](#bureaucratic-part)
        *   [8.1.2 Hello, world: A program in honor of Georges Perec](#hello-world-a-program-in-honor-of-georges-perec)
        *   [8.1.3 Submitting your assignment](#submitting-your-assignment)
        *   [8.1.4 Sample solution](#sample-solution)
    *   [8.2 Assignment 2, due 2022-02-10 at 17:00](#hw2-2022)
        *   [8.2.1 Recognizing lowercase letters](#recognizing-lowercase-letters)
        *   [8.2.2 Non-ASCII characters](#non-ascii-characters)
        *   [8.2.3 Testing your assignment](#testing-your-assignment)
        *   [8.2.4 Clarifications](#clarifications)
        *   [8.2.5 Submitting your assignment](#submitting-your-assignment-1)
        *   [8.2.6 Sample solution](#sample-solution-1)
    *   [8.3 Assignment 3, due 2022-02-17 at 17:00](#hw3-2022)
        *   [8.3.1 Testing your assignment](#testing-your-assignment-1)
        *   [8.3.2 Submitting your assignment](#submitting-your-assignment-2)
        *   [8.3.3 Notes](#notes)
        *   [8.3.4 Clarifications](#clarifications-1)
        *   [8.3.5 Sample solution](#sample-solution-2)
    *   [8.4 Assignment 4, due 2022-02-24 at 17:00](#hw4-2022)
        *   [8.4.1 Testing your assignment](#testing-your-assignment-2)
        *   [8.4.2 Submitting your assignment](#submitting-your-assignment-3)
        *   [8.4.3 Notes](#notes-1)
        *   [8.4.4 Sample solution](#sample-solution-3)
    *   [8.5 Assignment 5, due 2022-03-03 at 23:59](#hw5-2022)
        *   [8.5.1 Your task](#your-task)
        *   [8.5.2 Submitting your assignment](#submitting-your-assignment-4)
        *   [8.5.3 Sample solutions](#sample-solutions)
    *   [8.6 Assignment 6, due 2022-03-10 at 23:59](#hw6-2022)
        *   [8.6.1 A macro processor](#a-macro-processor)
        *   [8.6.2 Unexpanded delimiters](#unexpanded-delimiters)
        *   [8.6.3 Directories](#directories)
        *   [8.6.4 Recursion depth](#recursion-depth)
        *   [8.6.5 Bad arguments](#bad-arguments)
        *   [8.6.6 Submitting your assignment](#submitting-your-assignment-5)
        *   [8.6.7 Sample solution](#sample-solution-4)
    *   [8.7 Assignment 7, due 2022-03-17 at 23:59](#hw7-2022)
        *   [8.7.1 A maze of twisty little pointers](#a-maze-of-twisty-little-pointers)
        *   [8.7.2 Submitting your assignment](#submitting-your-assignment-6)
        *   [8.7.3 Testing your assignment](#testing-your-assignment-3)
        *   [8.7.4 Sample solution](#sample-solution-5)
    *   [8.8 Assignment 8, due 2022-03-31 at 23:59](#hw8-2022)
        *   [8.8.1 Your task](#your-task-1)
        *   [8.8.2 Submitting your assignment](#submitting-your-assignment-7)
        *   [8.8.3 Sample solution](#sample-solution-6)
    *   [8.9 Assignment 9, due 2022-04-07 at 23:59](#hw9-2022)
        *   [8.9.1 An infinite stream data structure](#an-infinite-stream-data-structure)
        *   [8.9.2 Submitting your assignment](#submitting-your-assignment-8)
        *   [8.9.3 Sample solution](#sample-solution-7)
    *   [8.10 Assignment 10, due 2022-04-14 at 23:59](#hw10-2022)
        *   [8.10.1 Greedy trash collecting](#greedy-trash-collecting)
        *   [8.10.2 Example](#example-1)
        *   [8.10.3 Submitting your assignment](#submitting-your-assignment-9)
        *   [8.10.4 Sample solution](#sample-solution-8)
    *   [8.11 Assignment 11, due 2022-04-21 at 23:59](#hw11-2022)
        *   [8.11.1 An expandable vector type](#an-expandable-vector-type)
        *   [8.11.2 Efficiency](#efficiency)
        *   [8.11.3 Submitting your assignment](#submitting-your-assignment-10)
        *   [8.11.4 Testing your assignment](#testing-your-assignment-4)
        *   [8.11.5 Sample solution](#sample-solution-9)
    *   [8.12 Assignment 12, due 2022-04-28 at 23:59](#hw12-2022)
        *   [8.12.1 A simulator for majority dynamics](#a-simulator-for-majority-dynamics)
        *   [8.12.2 Input format](#input-format)
        *   [8.12.3 Output format](#output-format)
        *   [8.12.4 Examples](#examples)
        *   [8.12.5 Submitting your assignment](#submitting-your-assignment-11)
        *   [8.12.6 Testing your assignment](#testing-your-assignment-5)
        *   [8.12.7 Sample solution](#sample-solution-10)
*   [9 Sample assignments from Spring 2021](#sample-assignments-from-spring-2021)
    *   [9.1 Assignment 1, due 2021-02-18 at 17:00 Eastern US time](#hw1-2021)
        *   [9.1.1 Bureaucratic part](#bureaucratic-part-1)
        *   [9.1.2 Run-length encoding](#run-length-encoding)
        *   [9.1.3 Testing your assignment](#testing-your-assignment-6)
        *   [9.1.4 Submitting your assignment](#submitting-your-assignment-12)
        *   [9.1.5 Sample solution](#hw1solution-2021)
    *   [9.2 Assignment 2, due 2021-02-25 at 17:00 Eastern US time](#hw2-2021)
        *   [9.2.1 Output format](#output-format-1)
        *   [9.2.2 Input range](#input-range)
        *   [9.2.3 Testing your assignment](#testing-your-assignment-7)
        *   [9.2.4 Submitting your assignment](#submitting-your-assignment-13)
        *   [9.2.5 Sample solution](#hw2solution-2021)
    *   [9.3 Assignment 3, due 2021-03-04 at 17:00 Eastern US time](#hw3-2021)
        *   [9.3.1 Pancake instruction set](#pancake-instruction-set)
            *   [9.3.1.1 Undefined behavior](#undefined-behavior)
            *   [9.3.1.2 Example](#example-2)
        *   [9.3.2 Testing your program](#testing-your-program)
        *   [9.3.3 Submitting your assignment](#submitting-your-assignment-14)
        *   [9.3.4 Sample solution](#hw3solution-2021)
    *   [9.4 Assignment 4, due 2021-03-11 at 17:00 Eastern US time](#hw4-2021)
        *   [9.4.1 Details](#details)
        *   [9.4.2 Testing your assignment](#testing-your-assignment-8)
        *   [9.4.3 Submitting your assignment](#submitting-your-assignment-15)
        *   [9.4.4 Sample solution](#hw4solution-2021)
    *   [9.5 Assignment 5, due 2021-03-18 at 17:00 Eastern US time](#hw5-2021)
        *   [9.5.1 Testing your assignment](#testing-your-assignment-9)
        *   [9.5.2 Sample solution](#hw5solution-2021)
        *   [9.5.3 Submitting your assignment](#submitting-your-assignment-16)
    *   [9.6 Assignment 6, due 2021-03-26 at 17:00 Eastern US time](#hw6-2021)
        *   [9.6.1 Testing your assignment](#testing-your-assignment-10)
        *   [9.6.2 Submitting your assignment](#submitting-your-assignment-17)
        *   [9.6.3 Sample solution](#hw6solution-2021)
    *   [9.7 Assignment 7, due 2021-04-01 at 17:00 Eastern US time](#hw7-2021)
        *   [9.7.1 Password files](#password-files)
        *   [9.7.2 Decryption](#decryption)
        *   [9.7.3 Hints](#hints)
        *   [9.7.4 Submitting your assignment](#submitting-your-assignment-18)
        *   [9.7.5 Testing your assignment](#testing-your-assignment-11)
        *   [9.7.6 Sample solution](#hw7solution-2021)
    *   [9.8 Assignment 8, due 2021-04-07 at 23:59 Eastern US time](#hw8-2021)
        *   [9.8.1 Compression scheme](#compression-scheme)
        *   [9.8.2 Choice of dictionary](#choice-of-dictionary)
        *   [9.8.3 Decompressor (provided)](#decompressor-provided)
        *   [9.8.4 Compressor (to be submitted)](#compressor-to-be-submitted)
        *   [9.8.5 Testing your assignment](#testing-your-assignment-12)
        *   [9.8.6 Sample solution](#hw8solution-2021)
    *   [9.9 Assignment 9, due 2021-04-15 at 17:00 Eastern US time](#hw9-2021)
        *   [9.9.1 The Pancake Flipper Markup Language](#the-pancake-flipper-markup-language)
        *   [9.9.2 Your task](#your-task-2)
        *   [9.9.3 Submitting your assignment](#submitting-your-assignment-19)
        *   [9.9.4 Testing your assignment](#testing-your-assignment-13)
        *   [9.9.5 Sample solution](#hw9solution-2021)
    *   [9.10 Assignment 10, due 2021-04-22 at 17:00 Eastern US time](#hw10-2021)
        *   [9.10.1 Behavior](#behavior)
        *   [9.10.2 Interface](#interface)
        *   [9.10.3 Test program](#test-program)
        *   [9.10.4 Submitting your assignment](#submitting-your-assignment-20)
        *   [9.10.5 Testing your assignment](#testing-your-assignment-14)
        *   [9.10.6 Sample solution](#sample-solution-11)
    *   [9.11 Assignment 11, due 2021-04-29 at 17:00 Eastern US time](#hw11-2021)
        *   [9.11.1 The `Inserter` data type](#the-inserter-data-type)
        *   [9.11.2 Interface](#interface-1)
        *   [9.11.3 Test program](#test-program-1)
        *   [9.11.4 Submitting your assignment](#submitting-your-assignment-21)
        *   [9.11.5 Sample solution](#hw11solution-2021)
    *   [9.12 Assignment 12, due 2021-05-06 at 17:00 Eastern US time](#hw12-2021)
        *   [9.12.1 Distance-2 colorings](#distance-2-colorings)
        *   [9.12.2 Your task](#your-task-3)
        *   [9.12.3 Submitting your assignment](#submitting-your-assignment-22)
        *   [9.12.4 Testing your assignment](#testing-your-assignment-15)
        *   [9.12.5 Implementation hints](#implementation-hints)
        *   [9.12.6 Sample solution](#hw12solution-2021)
*   [10 Sample assignments from Spring 2018](#sample-assignments-from-spring-2018)
    *   [10.1 Assignment 1, due Thursday 2018-02-08, at 11:00pm](#hw1-2018)
        *   [10.1.1 Bureaucratic part](#bureaucratic-part-2)
        *   [10.1.2 Pig Esperanto](#pig-esperanto)
        *   [10.1.3 Your task](#your-task-4)
        *   [10.1.4 Testing your assignment](#testing-your-assignment-16)
        *   [10.1.5 Submitting your assignment](#submitting-your-assignment-23)
        *   [10.1.6 Sample solution](#sample-solution-12)
    *   [10.2 Assignment 2, due Thursday 2018-02-15, at 11:00pm](#hw2-2018)
        *   [10.2.1 Your task](#your-task-5)
        *   [10.2.2 Submitting your assignment](#submitting-your-assignment-24)
        *   [10.2.3 Sample solution](#sample-solution-13)
    *   [10.3 Assignment 3, due Thursday 2018-02-22, at 11:00pm](#hw3-2018)
        *   [10.3.1 Your task](#your-task-6)
        *   [10.3.2 Submitting your assignment](#submitting-your-assignment-25)
        *   [10.3.3 Clarifications added after the original assignment was posted](#clarifications-added-after-the-original-assignment-was-posted)
        *   [10.3.4 Sample solution](#sample-solution-14)
    *   [10.4 Assignment 4, due Thursday 2018-03-01, at 11:00pm](#hw4_2018)
        *   [10.4.1 Your task](#your-task-7)
        *   [10.4.2 Interface](#hw4_2018_interface)
        *   [10.4.3 Submitting your assignment](#submitting-your-assignment-26)
        *   [10.4.4 Sample solution](#sample-solution-15)
    *   [10.5 Assignment 5, due Thursday 2018-03-29, at 11:00pm](#hw5-2018)
        *   [10.5.1 Your task](#your-task-8)
        *   [10.5.2 List of commands and their effects](#list-of-commands-and-their-effects)
        *   [10.5.3 Examples](#examples-1)
        *   [10.5.4 Submitting your assignment](#submitting-your-assignment-27)
        *   [10.5.5 Sample solution](#sample-solution-16)
    *   [10.6 Assignment 6, due Thursday 2018-04-05, at 11:00pm](#hw6-2018)
        *   [10.6.1 Text representation of a tree](#text-representation-of-a-tree)
        *   [10.6.2 Examples](#examples-2)
        *   [10.6.3 Depth](#depth)
        *   [10.6.4 Submitting your assignment](#submitting-your-assignment-28)
        *   [10.6.5 Sample solution](#sample-solution-17)
    *   [10.7 Assignment 7, due Thursday 2018-04-12, at 11:00pm](#hw7-2018)
        *   [10.7.1 Interface](#interface-2)
        *   [10.7.2 Your task](#your-task-9)
        *   [10.7.3 Combining elements](#combining-elements)
        *   [10.7.4 Testing your program](#testing-your-program-1)
        *   [10.7.5 Submitting your program](#submitting-your-program)
        *   [10.7.6 Sample solution](#sample-solution-18)
    *   [10.8 Assignment 8, due Thursday 2018-04-19, at 11:00pm](#hw8-2018)
        *   [10.8.1 The game](#the-game)
        *   [10.8.2 Examples](#examples-3)
        *   [10.8.3 Your task](#your-task-10)
        *   [10.8.4 Efficiency](#efficiency-1)
        *   [10.8.5 Bad inputs](#bad-inputs)
        *   [10.8.6 Submitting your assignment](#submitting-your-assignment-29)
        *   [10.8.7 Sample solution](#sample-solution-19)
*   [11 Sample assignments from Spring 2015](#sample-assignments-from-spring-2015)
    *   [11.1 Assignment 1, due Thursday 2015-01-29, at 11:00pm](#hw1-2015)
        *   [11.1.1 Bureaucratic part](#bureaucratic-part-3)
        *   [11.1.2 A rotten cipher](#a-rotten-cipher)
        *   [11.1.3 Your task](#your-task-11)
        *   [11.1.4 Hints](#hints-1)
        *   [11.1.5 Testing your assignment](#testing-your-assignment-17)
        *   [11.1.6 Submitting your assignment](#submitting-your-assignment-30)
        *   [11.1.7 Sample solution](#hw1Solution)
    *   [11.2 Assignment 2, due Wednesday 2015-02-04, at 11:00pm](#hw2-2015)
        *   [11.2.1 Opening a safe](#opening-a-safe)
        *   [11.2.2 Submitting your assignment](#submitting-your-assignment-31)
        *   [11.2.3 Valgrind](#hw2valgrind)
        *   [11.2.4 Sample solution](#hw2Solution)
    *   [11.3 Assignment 3, due Wednesday 2015-02-11, at 11:00pm](#hw3-2015)
        *   [11.3.1 Quadratic letter sequences](#quadratic-letter-sequences)
        *   [11.3.2 Your task](#your-task-12)
        *   [11.3.3 Submitting your assignment](#submitting-your-assignment-32)
        *   [11.3.4 Sample solution](#hw3Solution)
    *   [11.4 Assignment 4, due Wednesday 2015-02-18, at 11:00pm](#hw4-2015)
        *   [11.4.1 An ASCII art compositor](#an-ascii-art-compositor)
        *   [11.4.2 Submitting your assignment](#submitting-your-assignment-33)
        *   [11.4.3 Notes](#notes-2)
            *   [11.4.3.1 Input](#input)
            *   [11.4.3.2 Output](#output)
            *   [11.4.3.3 General](#general)
        *   [11.4.4 Sample solution](#hw4Solution)
    *   [11.5 Assignment 5, due Wednesday 2015-02-25, at 11:00pm](#hw5-2015)
        *   [11.5.1 Build a Turing machine!](#build-a-turing-machine)
        *   [11.5.2 Example](#example-3)
        *   [11.5.3 Your task](#your-task-13)
        *   [11.5.4 Submitting your assignment](#submitting-your-assignment-34)
        *   [11.5.5 Sample solution](#hw5Solution)
    *   [11.6 Assignment 6, due Wednesday 2015-03-25, at 11:00pm](#hw6-2015)
        *   [11.6.1 Sinking ships](#sinking-ships)
        *   [11.6.2 Things to watch out for](#things-to-watch-out-for)
        *   [11.6.3 The `testShips` program](#the-testships-program)
        *   [11.6.4 Submitting your assignment](#submitting-your-assignment-35)
        *   [11.6.5 Provided source files](#hw6-2015-source-files)
        *   [11.6.6 Sample solution](#hw6Solution)
    *   [11.7 Assignment 7, due Wednesday 2015-04-01, at 11:00pm](#hw7-2015)
        *   [11.7.1 Solitaire with big cards](#solitaire-with-big-cards)
        *   [11.7.2 Explanation of the testing program](#explanation-of-the-testing-program)
        *   [11.7.3 Submitting your assignment](#submitting-your-assignment-36)
        *   [11.7.4 Sample solution](#hw7Solution)
    *   [11.8 Assignment 8, due Wednesday 2015-04-08, at 11:00pm](#hw8-2015)
        *   [11.8.1 An ordered set](#an-ordered-set)
        *   [11.8.2 The `testOrderedSet` wrapper](#the-testorderedset-wrapper)
        *   [11.8.3 Submitting your assignment](#hw8submission)
        *   [11.8.4 Sample solution](#hw8Solution)
    *   [11.9 Assignment 9, due Wednesday 2015-04-15, at 11:00pm](#hw9-2015)
        *   [11.9.1 Finding a cycle in a maze](#finding-a-cycle-in-a-maze)
        *   [11.9.2 Input and output format](#input-and-output-format)
        *   [11.9.3 Submitting and testing your program](#submitting-and-testing-your-program)
        *   [11.9.4 Sample solution](#hw9solution)
*   [12 Various student contributions](#various-student-contributions)
    *   [12.1 Common C coding and debugging issues](#codingHints)
    *   [12.2 223 Office Hours Bingo](#office-hours-bingo)

1 Course administration
=======================

1.1 Overview
------------

This is the course information for CPSC 223: _Data Structures and Programming Techniques_ for the Spring 2022 semester. This document is available in HTML format at the URL [https://www.cs.yale.edu/homes/aspnes/classes/223/notes.html](https://www.cs.yale.edu/homes/aspnes/classes/223/notes.html).

Code examples can be downloaded from links in the text, or can be found in the [examples directory](https://www.cs.yale.edu/homes/aspnes/classes/223/examples/).

This document is a work in progress, and is likely to change frequently as the semester progresses.

### 1.1.1 License

Copyright © 2001–2021 by James Aspnes. Distributed under a Creative Commons Attribution-ShareAlike 4.0 International license: [https://creativecommons.org/licenses/by-sa/4.0/](https://creativecommons.org/licenses/by-sa/4.0/).

### 1.1.2 Resources

*   [Schedule](#schedule): list of lectures and events. Includes reading assignments and pointers to lecture notes.
*   [Calendar](https://www.cs.yale.edu/homes/aspnes/#calendar): shows office hours, lectures, and assignment deadlines.
*   [Assignments](#assignments): list of homeworks and exams.
*   [Notes](notes.html): notes on various topics relevant to the course.
*   [Syllabus](#syllabus).
*   [Data structure visualizations](http://www.cs.usfca.edu/~galles/visualization/Algorithms.html). Much better than the ASCII art (at best) illustrations you will find in this document.[1](#fn1)

### 1.1.3 Documentation

*   [How to use the Zoo](#zoo)
*   [Zoo help](http://zoo.cs.yale.edu/help/)
*   [Coding hints](#codingHints)
*   GNU [Online Documentation](http://www.delorie.com/gnu/docs/),
    *   [gcc](http://www.delorie.com/gnu/docs/gcc/gcc_toc.html)
    *   [gdb](http://www.delorie.com/gnu/docs/gdb/gdb_toc.html)
    *   [ddd](http://www.gnu.org/software/ddd/manual/html_mono/ddd.html)
    *   [emacs](http://www.delorie.com/gnu/docs/emacs/emacs_toc.html)
*   Frequently-asked questions (FAQ) for
    *   [C](http://www.eskimo.com/~scs/C-faq.top.html)
    *   [C (abridged)](http://www.faqs.org/faqs/C-faq/abridged/)
    *   [Unix](http://www.faqs.org/faqs/unix-faq/faq/)
    *   [Emacs](http://www.faqs.org/faqs/GNU-Emacs-FAQ/)
*   [Programming in C](http://www.lysator.liu.se/c/)
*   [Valgrind documentation](http://valgrind.org/docs/)
*   [UNIXhelp for Users](http://www.mcsr.olemiss.edu/unixhelp/)

### 1.1.4 Questions and comments

Please feel free to send questions or comments on the class or anything connected to it to [james.aspnes@gmail.com](mailto:james.aspnes@gmail.com).

1.2 Lecture schedule
--------------------

K&R refers to the Kernighan and Ritchie book. Examples from lecture can be found in the [examples directory](examples) under [2022/lecture](examples/2022/lecture) if the links below have not been updated yet.

2022-01-25

Introduction. What the course is about. Getting started with C: running the compiler, the `main` function, program structure, basic integer data types. Reading: [Course administration](#courseAdministration), [The Zoo](#zoo), [The Linux programming environment](#linux), a little bit about [developing on your own machine](#developingOnYourOwnMachine), [Structure of a C program](#CProgramStructure), [Basic integer types](#basicIntegerTypes); K&R §§1.1, 1.2. [Examples from lecture](examples/2022/lecture/2022-01-26): [hello.c](examples/2022/lecture/2022-01-26/hello.c).

2022-01-28

Arithmetic in C. Reading: [Integer types in C](#integerTypes), [Floating-point types](#floatingPointTypes); K&R §§2.2, 2.3, 2.5. [Examples from lecture](examples/2022/lecture/2022-01-28): [arithmetic.c](examples/2022/lecture/2022-01-28/arithmetic.c).

2022-01-31

Statements and control flow: `if`, `while`, `for`, `do`..`while`. Relational and logical operators: `<`, `<=`, `==`, `!=`, `>=`, `>`, `&&`, `||`, `!`, `?:`, and `,`. More assignment operators: `+=` and friends, `++` and `--`. Reading: [Statements](#statements); K&R §§1.5, 2.6, 2.8, 2.10, 2.12, 3.1, 3.2, 3.3, 3.5, and 3.6.

2022-02-02

Character I/O using `getchar`, `putchar`, and `ungetc`. Goto-like statements: `switch`, `break`, `continue`, and `goto`. Reading: [Reading and writing single characters](#characterIO); K&R §§1.5, 3.7, and 3.8.

2022-02-07

Functions. Reading: [Functions](#functions); K&R §§4.1–4.5.

2022-02-09

Start of pointers and arrays: pointer types and pointer variables. The `&` and `*` operators. Using a pointer to get a value out of a function. Array declarations. Reading: [Pointers](#pointers) up through [Arrays](#arrays); K&R 5.1–5.4. Examples from lecture: [pointers.c](examples/2022/lecture/2022-02-09/pointers.c).

2022-02-14

Strings: basic idea of null-terminated strings, how C interacts with Unicode, `char *` vs. `const char *`, `argv`, various pointer hackery involving `*` and `++`. Reading: [Strings](#strings); K&R 5.5. Examples from lecture: [strings.c](examples/2022/lecture/2022-02-14/strings.c).

2022-02-16

Storage allocation: `malloc`, `calloc`, `free`, and `realloc`. The `void *` pointer type. Finding storage allocation bugs using [`valgrind`](#valgrind). Reading: [Run-time storage allocation using `malloc`](#malloc), [Valgrind](#valgrind). [Examples from lecture](examples/2022/lecture/2022-02-16/). The easiest way to compile all of these is to download everything then run `make all` or `make test`.

2022-02-21

Using `realloc` to deal with data of unknown size. Basics of debugging with `gdb` and `valgrind`. Reading: [Debugging](#debugging), [Dynamic arrays](#dynamicArrays) for a bit more about use of `realloc`. [Examples from lecture](examples/2022/lecture/2022-02-21).

2022-02-23

Structured data types: `struct`s, `union`s, and `enum`s. Reading: [Structured data types](#structuredDataTypes); K&R Chapter 6, §2.5 (for `enum`s).

2022-02-28

Managing large C programs. More on source files vs header files. Controlling information with typedefs. Linking and `make`. The `stdio.h` library and file I/O. Reading: [Function declarations and modules](#modules), [Static functions](#staticFunctions), [Make](#make), [File I/O](#FileIO). [Examples from lecture](examples/2022/lecture/2022-02-28).

2022-03-02

Recursion. Reading: [Recursion](#recursion). [Examples form lecture](examples/2022/lecture/2022-03-02).

2022-03-07

Worst-case and amortized efficiency of data structures. Linked lists and stacks. Reading: [Asymptotic notation](#asymptoticNotation), [Linked lists](#linkedLists).

2022-03-09

Designing and implementing abstract data types: abtraction barriers, information hiding principle, representations invariants, and abstraction functions. Examples of abstract data types often implemented with linked lists: bags, stacks. queues, and deques. Doubly-linked lists. Reading: [Abstract data types](#abstractDataTypes). [Examples from lecture](examples/2022/lecture/2022-03-09). The examples were intended to compare implementing a deque as a circular doubly-linked list (straightforward but slower) vs a dynamic array (error-prone but faster). Unfortunately, the dynamic-array version was so error-prone that I did not manage to debug it by the end of class. The example version linked here fixes the errors. The overall speedup on my machine for large _n_ is about 30%, at the cost of substantial added code complexity and debugging effort. This is small enough that I may need to retract some of my negative comments about the practicality of linked lists.

2022-03-14

Set and map abstract data types. Hash tables. A very small preview of using function pointers for iteration. Reading: [Hash tables](#hashTables). [Examples from lecture](examples/2022/lecture/2022-03-14).

2022-03-16

Function pointers and applications: `qsort`, dispatch tables, callbacks, closures. Reading: [Function pointers](#functionPointers); K&R §5.11. [Examples from lecture](examples/2022/lecture/2022-03-16).

2022-03-28

Generic containers; object-oriented programming in C. Reading: [Generic containers](#genericContainers), [Object-oriented programming](#objectOrientedProgramming). [Examples from lecture](examples/2022/lecture/2022-03-28).

2022-03-30

Trees. Structure of trees. Standard tree algorithms. Parse trees and recursive descent parsing. Reading: [Trees](#trees), [Recursive descent parsing](#recursiveDescentParsing). [Examples from lecture](examples/2022/lecture/2022-03-30).

2022-04-04

Heaps. Reading: [Heaps](#heaps). [Examples from lecture](examples/2022/lecture/2022-04-04): [heapsort.c](examples/2022/lecture/2022-04-04/heapsort.c).

2022-04-06

Start of binary search trees. Basic binary search tree algorithms. Preview of tree rotation. Reading: [Binary search trees](#binarySearchTrees). [Examples from lecture](examples/2022/lecture/2022-04-06): [tree.c](examples/2022/lecture/2022-04-06/tree.c).

2022-04-11

Balanced binary search trees: Treaps . Reading: [Treaps](#treaps). [Examples from lecture](examples/2022/lecture/2022-04-11): [treap.c](examples/2022/lecture/2022-04-06/treap.c). (This version fixes the size bug.)

2022-04-13

Augmented trees (carrying over from previous lecture; added improved `treeSize` and `treeDepth` functions). Timing and profiling. Optimizing for performance. Reading: [Augmented trees](#AugmentedTrees), [Performance tuning](#performanceTuning). [Examples from lecture](examples/2022/lecture/2022-04-13).

2022-04-18

Graphs: structure and representations. Reading: [Graphs](#graphs) up to start of [Graph search](#graphSearch). [Examples from lecture](examples/2022/lecture/2022-04-18).

2022-04-20

Graph search: DFS and BFS algorithms. Reading: [Graph search](#graphSearch). [Examples from lecture](examples/2022/lecture/2022-04-20).

2022-04-25

Data structures for strings: tries and TSTs; radix sort. Reading: [String processing](#stringProcessing). [Examples from lecture](examples/2022/lecture/2022-04-25).

2022-04-27

Dynamic programming: basics, all-pairs shortest paths, longest increasing subsequence, longest common subsequence. Reading: [Dynamic programming](#dynamicProgramming). [Examples from lecture](examples/2022/lecture/2022-04-27).

1.3 Syllabus
------------

Computer Science 223b, Data Structures and Programming Techniques.

Instructor: James Aspnes.

### 1.3.1 On-line course information

On-line information about the course, including the lecture schedule, lecture notes, and information about assignments, can be found at [https://www.cs.yale.edu/homes/aspnes/classes/223/notes.html](https://www.cs.yale.edu/homes/aspnes/classes/223/notes.html). This document will be updated frequently during the semester, and is also available in [PDF](https://www.cs.yale.edu/homes/aspnes/classes/223/notes.pdf) format.

### 1.3.2 Meeting times

Lectures are MW 13:00–14:15 in the 53 Wall Street Auditorium (WALL53 AUD).

The [lecture schedule](#schedule) can be found in the course notes. A [calendar](https://www.cs.yale.edu/homes/aspnes/#calendar) is also available.

### 1.3.3 Course synopsis

Topics include programming in C; data structures (arrays, stacks, queues, lists, trees, heaps, graphs); sorting and searching; storage allocation and management; data abstraction; programming style; testing and debugging; writing efficient programs.

### 1.3.4 Prerequisites

CPSC 201, or equivalent background. See me if you aren’t sure.

### 1.3.5 Textbook

The textbook for this course is:

*   _The C Programming Language (2nd Edition),_ by Brian W. Kernighan and Dennis M. Ritchie. Prentice Hall, 1988. ISBN 0131103628. The definitive introduction to C. You should memorize this book.

If you are on the Yale campus or are using VPN to get to Yale’s network, you can access this book at [http://proquest.safaribooksonline.com/book/programming/c/9780133086249](http://proquest.safaribooksonline.com/book/programming/c/9780133086249). You do not need to buy a physical copy of this book unless you want to.

### 1.3.6 Course requirements

Twelve homework assignments. For each student, the lowest two assignment grades will be dropped, and the remaining ten assignments will together count for 100% of the semester grade. Due to the size of the class and the issues of managing exams during an ongoing pandemic, there will be no exams.

### 1.3.7 Staff

See the [calendar](https://www.cs.yale.edu/homes/aspnes/#calendar) for open office hours.

#### 1.3.7.1 Instructor

James Aspnes ([james.aspnes@gmail.com](mailto:james.aspnes@gmail.com), [http://www.cs.yale.edu/homes/aspnes/](http://www.cs.yale.edu/homes/aspnes/)). Office hours are listed in the calendar on my home page. If my open office hours don’t work for you, please send email to make an appointment.

#### 1.3.7.2 Undergraduate Learning Assistants

*   Andre Braga
*   Alec Buffi
*   Jeffrey Chen
*   Eric Chien
*   Benjamin Cifu
*   Dylan Fernandez de Lara
*   Benjamin Goldstein
*   Harry Jain
*   Bradley Lewis
*   Neal Ma
*   Anushka Nijhawan
*   Dion Ong
*   Andy Pantoja Valerio
*   Adin Ring
*   Zhemin Shao
*   Dylan Vroon
*   James Wang
*   Alan Xu
*   Irene Xu
*   Kevin Zhou

### 1.3.8 Use of outside help

Students are free to discuss homework problems and course material with each other, and to consult with the instructor or a TA. Solutions handed in, however, should be the student’s own work.

As a practical guide to applying this policy, you should not look at other student’s solutions or show them your own. Any code that is directly copied (even with trivial modifications) will result in sanctions on both the provider and the recipient. To avoid the appearance of impropriety, it is recommended that if you discuss your assignment with another student, that you take some time performing some unrelated activity before generating your own code, so that you can be confident that what you are doing reflects your own understanding and not someone else’s remembered suggestions.

### 1.3.9 Clarifications for homework assignments

From time to time, ambiguities and errors may creep into homework assignments. Questions about the interpretation of homework assignments should be sent to the instructor at [james.aspnes@gmail.com](mailto:james.aspnes@gmail.com). Clarifications will appear in the on-line version of the assignment.

### 1.3.10 Late assignments

Assignments submitted after the deadline without a Dean’s Extension are automatically assessed a 2%/hour penalty.

1.4 Introduction
----------------

There are two purposes to this course: to teach you to program in the C programming language, and to teach you how to choose, implement, and use data structures and standard programming techniques.

### 1.4.1 Why should you learn to program in C?

*   It is the _de facto_ substandard of programming languages.
    *   C runs on everything.
    *   C lets you write programs that use very few resources.
    *   C gives you near-total control over the system, down to the level of pushing around individual bits with your bare hands.
    *   C imposes very few constraints on programming style: unlike higher-level languages, C doesn’t have much of an ideology. There are very few programs you can’t write in C.
    *   Many of the programming languages people actually use (Visual Basic, perl, python, ruby, PHP, etc.) are executed by interpreters written in C (or [C++](#cplusplus), an extension to C).
*   You will learn discipline.
    *   C makes it easy to shoot yourself in the foot.
    *   You can learn to avoid this by being careful about where you point it.
    *   Pain is a powerful teacher of caution.
*   You will fail CPSC 323 if you don’t learn C really well in CPSC 223 (CS majors only).

On the other hand, there are many reasons why you might not want to use C later in life. It’s missing a lot of features of modern program languages, including:

*   A garbage collector.
*   Minimal programmer-protection features like array bounds-checking or a strong type system.
*   Non-trivial built-in data structures.
*   Language support for exceptions, namespaces, object-oriented programming, etc.

For most problems where minimizing programmer time and maximizing robustness are more important than minimizing runtime, other languages are a better choice. But for this class, we’ll be using C.

If you want to read a lot of flaming about what C is or is not good for, see [http://c2.com/cgi/wiki?CeeLanguage](http://c2.com/cgi/wiki?CeeLanguage).

### 1.4.2 Why should you learn about data structures and programming techniques?

For small programs, you don’t need much in the way of data structures. But as soon as you are representing reasonably complicated data, you need some place to store it. Thinking about how you want to store and organize this data can be a good framework for organizing the rest of your program.

Many programming environments will give you a rich collection of built-in data structures as part of their standard library. C does not: unless you use third-party libraries, any data structure you want in C you will have to build yourself. For most data structures this will require an understanding of pointers and storage allocation, mechanisms often hidden in other languages. Understanding these concepts will give you a deeper understanding of how computers actually work, and will both let you function in minimalist environments where you don’t have a lot of support and let you understand what more convenient environments are doing under their abstraction barriers.

The same applies to the various programming techniques we will discuss in this class. While some of the issues that come up are specific to C and similar low-level languages (particular issues involving disciplined management of storage), some techniques will apply no matter what kinds of programs you are writing and all will help in understanding what your computer systems are doing even if some of the details are hidden.

2 The Zoo
=========

The main undergraduate computing facility for Computer Science is the Zoo, located on the third floor of AKW. The Zoo contains a large number of Linux workstations.

You don’t need to do your work for this class in the Zoo, but that is where your assignments will be submitted and tested, so if you do development elsewhere, you will need to copy your files over and make sure that they work there as well.

The best place for information about the Zoo is at [http://zoo.cs.yale.edu/](http://zoo.cs.yale.edu/). Below are some points that are of particular relevance for CS223 students.

2.1 Getting an account
----------------------

You should already have an account for the Zoo if you have registered for the class. You login is your NetID. If this doesn’t work, you will need to contact ITS at [cs.support@yale.edu](mailto:cs.support@yale.edu) to figure out what went wrong.

If you have a Zoo account but do not have a directory under `/c/cs223/class` (required to submit assignments), create this directory with the command `sudo register cs223`.

2.2 Getting into the room
-------------------------

The Zoo is located on the third floor of Arthur K Watson Hall, toward the front of the building. If you are a Yale student, your ID should get you into the building and the room. If you are not a student, you will need to get your ID validated in AKW 008a to get in after hours.

2.3 Remote use
--------------

There are several options for remote use of the Zoo. The simplest is to use `ssh` as described in the following section. This will give you a terminal session, which is enough to run anything you need to if you are not trying to do anything fancy. The related program `scp` can be used to upload and download files.

### 2.3.1 Terminal access

The best part of Unix is that nothing ever changes. The instructions below still work, and will get you a terminal window in the Zoo. The only update is that if you are on a Windows machine you can probably now skip using puttySSH and use the built-in ssh client instead.

    Date: Mon, 13 Dec 2004 14:34:19 -0500 (EST)
    From: Jim Faulkner <james.faulkner@yale.edu>
    Subject: Accessing the Zoo
    
    Hello all,
    
    I've been asked to write up a quick guide on how to access the Linux 
    computers in the Zoo.  For those who need this information, please read 
    on.
    
    There are 2 ways of accessing the Zoo nodes, by walking up to one and 
    logging in on the console (the computers are located on the 3rd floor of 
    AKW), or by connecting remotely via SSH.  Telnet access is not allowed. 
    SSH clients for various operating systems are available here:
    
    http://www.yale.edu/software/
    
    Mac OSX comes with an SSH client by default.  A good choice for an SSH 
    client if you run Microsoft Windows is PuTTY:
    
    http://www.chiark.greenend.org.uk/~sgtatham/putty/
    
    With the exception of a few legacy accounts, the Zoo uses your campus-wide 
    NetID and password for login access.  However, you must sign up for a Zoo
    account before access is allowed.  To sign up for a Zoo account, go to 
    this web page:
    
    http://zoo.cs.yale.edu/accounts.html
    
    Then login with your campus-wide NetID and password.  You may choose a 
    different shell, or set up your account to be enrolled in a class if that 
    is appropriate for you, but neither is necessary.  Just click "Submit".  
    Within an hour, your Zoo account will be created, and you will receive 
    more information via e-mail about how to access the Zoo.
    
    Users cannot log into zoo.cs.yale.edu (the central file server) directly, 
    they must log into one of the Zoo nodes.  Following is the list of Zoo 
    nodes:
    
    aphid.zoo.cs.yale.edu               lion.zoo.cs.yale.edu
    bumblebee.zoo.cs.yale.edu           macaw.zoo.cs.yale.edu
    cardinal.zoo.cs.yale.edu            monkey.zoo.cs.yale.edu
    chameleon.zoo.cs.yale.edu           newt.zoo.cs.yale.edu
    cicada.zoo.cs.yale.edu              peacock.zoo.cs.yale.edu
    cobra.zoo.cs.yale.edu               perch.zoo.cs.yale.edu
    cricket.zoo.cs.yale.edu             python.zoo.cs.yale.edu
    frog.zoo.cs.yale.edu                rattlesnake.zoo.cs.yale.edu
    gator.zoo.cs.yale.edu               rhino.zoo.cs.yale.edu
    giraffe.zoo.cs.yale.edu             scorpion.zoo.cs.yale.edu
    grizzly.zoo.cs.yale.edu             swan.zoo.cs.yale.edu
    hare.zoo.cs.yale.edu                termite.zoo.cs.yale.edu
    hippo.zoo.cs.yale.edu               tick.zoo.cs.yale.edu
    hornet.zoo.cs.yale.edu              tiger.zoo.cs.yale.edu
    jaguar.zoo.cs.yale.edu              tucan.zoo.cs.yale.edu
    koala.zoo.cs.yale.edu               turtle.zoo.cs.yale.edu
    ladybug.zoo.cs.yale.edu             viper.zoo.cs.yale.edu
    leopard.zoo.cs.yale.edu             zebra.zoo.cs.yale.edu
    
    If you have already created an account, you can SSH directly to one of 
    the above computers and log in with your campus-wide NetID and 
    password.  You can also SSH to node.zoo.cs.yale.edu, which will connect 
    you to a random Zoo node.
    
    Feel free to contact me if you have any questions about the Zoo.
    
    thanks,
    Jim Faulkner
    Zoo Systems Administrator

### 2.3.2 GUI access

If for some reason you really want to replicate the full Zoo experience on your own remote machine, you can try running an X server and forwarding your connection.

The first step is to get an X server on your local machine.

    - If you are running Linux, you probably already have an X server running.
    - For OSX, you will probably need to install [XQuartz](https://xquarz.org/).
    - For Windows, some options are [XMing](http://www.straightrunning.com/XmingNotes/) or XWin-32, which is available through the Yale Software Library.

The second step is to use ssh to forward an X connection. Typing “ssh -X netID@node.zoo.cs.yale.edu” to a Linux, OSX, or WSL terminal window should forward an X connection, allowing you to run X clients from the command line on the Zoo and have the windows show up on your local machine. But I’ve only had limited success with this myself, so no promises.

2.4 Developing on your own machine
----------------------------------

Because C is highly portable, there is a good chance you can develop assignment solutions on your own machine and just upload to the Zoo for final testing and submission. Because there are many different kinds of machines out there, I can only offer very general advice about how to do this.[2](#fn2)

You will need a text editor. I like [Vim](http://www.vim.org/), which will run on pretty much anything, but you should use whatever you are comfortable with.

You will also need a C compiler that can handle at least C99. Ideally you will have an environment that looks enough like Linux that you can also run other command-line tools like `gdb`, `make`, and possibly `git`. How you get this depends on your underlying OS.

### 2.4.1 Linux

Pretty much any Linux distribution will give you this out of the box. You may need to run your package manager to install missing utilities like the `gcc` C compiler.

### 2.4.2 OSX

OSX is not Linux, but it is Unix under the hood. You will need a terminal emulator (the built-in Terminal program works, but I like [iTerm2](https://www.iterm2.com). You will also need to set up XCode to get command-line developer tools. The method for doing this seems to vary depending on which version of XCode you have.

You may end up with `gcc` being an alias for `clang` instead of the GNU version of `gcc`. Most likely the only difference you will see is the details of the error messages. Remember to test with `gcc` on the Zoo.

Other packages can be installed using Homebrew. If you are a Mac person you probably already know more about this than I do.

### 2.4.3 Windows

What you can do here depends on your version of Windows.

*   For Windows 10, you can install [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10). This gives you the ability to type `bash` in a console window and get a full-blown Linux installation. You will need to choose a Linux distribution: if you don’t have a preference, I recommend Ubuntu.
    *   You will need to use the `apt` program to install things like `gcc`. If you use Ubuntu, it will suggest which packages to install if you type a command it doesn’t recognize.
    *   You can also run `ubuntu.exe` from Windows to get a nicer terminal emulator than the default console window.
*   For other versions of Windows, you can install a virtualization program like [VirtualBox](https://www.virtualbox.org/wiki/Downloads) or [VMware](https://www.vmware.com/) and run Linux inside it.
*   You may also be able to develop natively in Windows using [Cygwin](https://www.cygwin.com/), but this is probably harder than the other options and may produce surprising portability issues when moving your code to Linux.

2.5 How to compile and run programs
-----------------------------------

See the chapter on [how to use the Zoo](#zoo) for details of particular commands. The basic steps are

*   Creating the program with a text editor of your choosing. (I like `vim` for long programs and `cat` for very short ones.)
*   Compiling it with `gcc`.
*   Running it.

If any of these steps fail, the next step is debugging. We’ll talk about debugging elsewhere.

### 2.5.1 Creating the program

Use your favorite text editor. The program file should have a name of the form `foo.c`; the `.c` at the end tells the C compiler the contents are C source code. Here is a typical C program:

    #include <stdio.h>
    
    /* print the numbers from 1 to 10 */
    
    int
    main(int argc, char **argv)
    {
        int i;
    
        puts("Now I will count from 1 to 10");
        for(i = 1; i <= 10; i++) {
            printf("%d\n", i);
        }
    
        return 0;
    }

[examples/count.c](examples/count.c)

### 2.5.2 Compiling and running a program

Here’s what happens when I compile and run it on the Zoo:

    $ gcc -g3 -o count count.c
    $ ./count
    Now I will count from 1 to 10
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    $

The first line is the command to compile the program. The dollar sign is my **prompt**, which is printed by the system to tell me it is waiting for a command. The command calls `gcc` with arguments `-g3` (enable maximum debugging info), `-o` (specify executable file name, otherwise defaults to `a.out`), `count` (the actual executable file name), and `count.c` (the source file to compile). This tells `gcc` that we should compile `count.c` to `count` with maximum debugging info included in the executable file.

The second line runs the output file `count`. Calling it `./count` is necessary because by default the shell (the program that interprets what you type) only looks for programs in certain standard system directories. To make it run a program in the current directory, we have to include the directory name.

### 2.5.3 Some notes on what the program does

Noteworthy features of this program include:

*   The `#include <stdio.h>` in line 1. This is standard C boilerplate, and will appear in any program you see that does input or output. The meaning is to tell the compiler to include the text of the file `/usr/include/stdio.h` in your program as if you had typed it there yourself. This particular file contains declarations for the standard I/O library functions like `puts` (put string) and `printf` (print formatted), as used in the program. If you don’t put it in, your program may or may not still compile. Do it anyway.
*   Line 3 is a comment; its beginning and end is marked by the `/*` and `*/` characters. Comments are ignored by the compiler but can be helpful for other programmers looking at your code (including yourself, after you’ve forgotten why you wrote something).
*   Lines 5 and 6 declare the `main` function. Every C program has to have a `main` function declared in exactly this way—it’s what the operating system calls when you execute the program. The `int` on Line 3 says that main returns a value of type `int` (we’ll describe this in more detail later in the chapter on [functions](#functions)), and that it takes two arguments: `argc` of type `int`, the number of arguments passed to the program from the command line, and `argv`, of a [pointer](#pointers) type that we will get to eventually, which is an array of the arguments (essentially all the words on the command line, including the program name). Note that it would also work to do this as one line (as K&R typically does); the C compiler doesn’t care about whitespace, so you can format things however you like, subject to the constraint that consistency will make it easier for people to read your code.
*   Everything inside the curly braces is the body of the `main` function. This includes
    
    *   The declaration `int i;`, which says that `i` will be a variable that holds an `int` (see the chapter on [Integer Types](#integerTypes)).
    *   Line 10, which prints an informative message using `puts` (discussed in the chapter on [input and output](#IO)).
    *   The `for` loop on Lines 11–13, which executes its body for each value of `i` from 1 to 10. We’ll explain how `for` loops work [later](#forLoop). Note that the body of the loop is enclosed in curly braces just like the body of the `main` function. The only statement in the body is the call to `printf` on Line 12; this includes a format string that specifies that we want a decimal-formatted integer followed by a newline (the `\n`).
    *   The `return 0;` on Line 15 tells the operating system that the program worked (the convention in Unix is that 0 means success). If the program didn’t work for some reason, we could have returned something else to signal an error.

3 The Linux programming environment
===================================

The Zoo runs a Unix-like operating system called Linux. Most people run Unix with a command-line interface provided by a **shell**. Each line typed to the shell tells it what program to run (the first word in the line) and what arguments to give it (remaining words). The interpretation of the arguments is up to the program.

3.1 The shell
-------------

When you sign up for an account in the Zoo, you are offered a choice of possible shell programs. The examples below assume you have chosen `bash`, the [Bourne-again shell](http://www.gnu.org/software/bash/) written by the GNU project. Other shells behave similarly for basic commands.

### 3.1.1 Getting a shell prompt in the Zoo

When you log in to a Zoo node directly, you may not automatically get a shell window. If you use the default login environment (which puts you into the KDE window manager), you need to click on the picture of the display with a shell in from of it in the toolbar at the bottom of the screen. If you run Gnome instead (you can change your startup environment using the popup menu in the login box), you can click on the foot in the middle of the toolbar. Either approach will pop up a terminal emulator from which you can run emacs, gcc, and so forth.

The default login shell in the Zoo is `bash`, and all examples of shell command lines given in these notes will assume `bash`. You can choose a different login shell on the account sign-up page if you want to, but you are probably best off just learning to like `bash`.

### 3.1.2 The Unix filesystem

Most of what one does with Unix programs is manipulate the filesystem. Unix files are unstructured blobs of data whose names are given by paths consisting of a sequence of directory names separated by slashes: for example `/home/accts/some-user/cs223/hw1.c`. At any time you are in a current working directory (type `pwd` to find out what it is and `cd new-directory` to change it). You can specify a file below the current working directory by giving just the last part of the pathname. The special directory names `.` and `..` can also be used to refer to the current directory and its parent. So `/home/accts/some-user/cs223/hw1.c` is just `hw1.c` or `./hw1.c` if your current working directory is `/home/accts/some-user/cs223`, `cs223/hw1.c` if your current working directory is `/home/accts/some-user`, and `../cs223/hw1.c` if your current working directory is `/home/accts/some-user/illegal-downloads`.

All Zoo machines share a common filesystem, so any files you create or change on one Zoo machine will show up in the same place on all the others.

### 3.1.3 Unix command-line programs

Here are some handy Unix commands:

man

`man` _program_ will show you the on-line documentation (the _man page_) for a program (e.g., try `man man` or `man ls`). Handy if you want to know what a program does. On Linux machines like the ones in the Zoo you can also get information using `info program`, which has an Emacs-like interface.

You can also use `man` _function_ to see documentation for standard library functions. The command `man -k` _string_ will search for man pages whose titles contain _string_.

Sometimes there is more than one man page with the same name. In this case `man -k` will distingiush them by different manual section numbers, e.g., `printf (1)` (a shell command) vs. `printf (3)` (a library routine). To get a man page from a specific section, use `man` _section_ _name_, e.g. `man 3 printf`.

ls

`ls` lists all the files in the current directory. Some useful variants:

*   `ls /some/other/dir`; list files in that directory instead.
*   `ls -l`; long output format showing modification dates and owners.

mkdir

`mkdir dir` will create a new directory in the current directory named `dir`.

rmdir

`rmdir dir` deletes a directory. It only works on directories that contain no files.

cd

`cd dir` changes the current working directory. With no arguments, `cd` changes back to your home directory.

pwd

`pwd` (“print working directory”) shows what your current directory is.

mv

`mv old-name new-name` changes the name of a file. You can also use this to move files between directories.

cp

`cp old-name new-name` makes a copy of a file.

rm

`rm file` deletes a file. Deleted files cannot be recovered. Use this command carefully.

chmod

`chmod` changes the permissions on a file or directory. See the man page for the full details of how this works. Here are some common `chmod`’s:

*   `chmod 644 file`; owner can read or write the file, others can only read it.
*   `chmod 600 file`; owner can read or write the file, others can’t do anything with it.
*   `chmod 755 file`; owner can read, write, or execute the file, others can read or execute it. This is typically used for programs or for directories (where the execute bit has the special meaning of letting somebody find files in the directory).
*   `chmod 700 file`; owner can read, write, or execute the file, others can’t do anything with it.

`emacs`, `gcc`, `make`, `gdb`, `git`

See corresponding sections.

### 3.1.4 Stopping and interrupting programs

Sometimes you may have a running program that won’t die. Aside from costing you the use of your terminal window, this may be annoying to other Zoo users, especially if the process won’t die even if you close the terminal window or log out.

There are various control-key combinations you can type at a terminal window to interrupt or stop a running program.

ctrl-C

Interrupt the process. Many processes (including any program you write unless you trap SIGINT using the `sigaction` system call) will die instantly when you do this. Some won’t.

ctrl-Z

Suspend the process. This will leave a stopped process lying around. Type `jobs` to list all your stopped processes, `fg` to restart the last process (or `fg %1` to start process `%1` etc.), `bg` to keep running the stopped process in the background, `kill %1` to attempt to end process `%1` politely, `kill -KILL %1` to end process `%1` even if it is intercepting normal kills.

ctrl-D

Send end-of-file to the process. Useful if you are typing test input to a process that expects to get EOF eventually or writing programs using `cat > program.c` (not really recommmended). For test input, you are often better putting it into a file and using input redirection (`./program < test-input-file`); this way you can redo the test after you fix the bugs it reveals.

ctrl-\\

Quit the process. Sends a SIGQUIT, which asks a process to quit and dump core. Mostly useful if ctrl-C and ctrl-Z don’t work.

If you have a runaway process that you can’t get rid of otherwise, you can use `ps g` to get a list of all your processes and their process ids. The `kill` command can then be used on the offending process, e.g. `kill -KILL 6666` if your evil process has process id 6666. Sometimes the `killall` command can simplify this procedure, e.g. `killall -KILL evil` halts all process with command name `evil`.

### 3.1.5 Running your own programs

If you compile your own program, you will need to prefix it with `./` on the command line to tell the shell that you want to run a program in the current directory (called ‘`.`’) instead of one of the standard system directories. So for example, if I’ve just built a program called `count`, I can run it by typing

    $ ./count

Here the “`$` ” is standing in for whatever your prompt looks like; you should not type it.

Any words after the program name (separated by **whitespace**—spaces and/or tabs) are passed in as arguments to the program. Sometimes you may wish to pass more than one word as a single argument. You can do so by wrapping the argument in single quotes, as in

    $ ./count 'this is the first argument' 'this is the second argument'

### 3.1.6 Redirecting input and output

Some programs take input from **standard input** (typically the terminal). If you are doing a lot of testing, you will quickly become tired of typing test input at your program. You can tell the shell to **redirect** standard input from a file by putting the file name after a `<` symbol, like this:

    $ ./count < huge-input-file

A ‘>’ symbol is used to redirect **standard output**, in case you don’t want to read it as it flies by on your screen:

    $ ./count < huge-input-file > huger-output-file

A useful file for both input and output is the special file `/dev/null`. As input, it looks like an empty file. As output, it eats any characters sent to it:

    $ ./sensory-deprivation-experiment < /dev/null > /dev/null

You can also **pipe** programs together, connecting the output of one to the input of the next. Good programs to put at the end of a pipe are `head` (eats all but the first ten lines), `tail` (eats all but the last ten lines), `more` (lets you page through the output by hitting the space bar, and `tee` (shows you the output but also saves a copy to a file). A typical command might be something like `./spew | more` or `./slow-but-boring | tee boring-output`. Pipes can consist of a long train of programs, each of which processes the output of the previous one and supplies the input to the next. A typical case might be:

    $ ./do-many-experiments | sort | uniq -c | sort -nr

which, if `./do-many-experiments` gives the output of one experiment on each line, produces a list of distinct experimental outputs sorted by decreasing frequency. Pipes like this can often substitute for hours of real programming.

3.2 Text editors
----------------

To write your programs, you will need to use a text editor, preferably one that knows enough about C to provide tools like automatic indentation and syntax highlighting. There are two reasonable choices for this in the Zoo: `emacs`, and `vim` (which can also be run as `vi`). [Emacs](http://en.wikipedia.org/wiki/Emacs "WikiPedia") and [Vi](http://en.wikipedia.org/wiki/Vi "WikiPedia") have been the two contenders for the [One True Editor](http://en.wikipedia.org/wiki/Editor_war "WikiPedia") since the 1970s—if you learn one (or both) you will be able to use the resulting skills everywhere. My personal preference is to use Vi, but Emacs has the advantage of using the same editing commands as the shell and `gdb` command-line interfaces.

If you are not editing directly on the Zoo machines, you have more options. Some other popular text editors that work well with C are [VS Code](https://code.visualstudio.com/), [Atom](https://atom.io/), and [Sublime Text](https://www.sublimetext.com/). The main downside to these editors is that they are relatively new, and so they don’t necessarily show up everywhere the way Emacs or Vi will. The other downside is that their relative novelty means that they won’t necessarily have the same longevity as your grandfather’s text editor: by the time you read this, there is a reasonably good chance that one or more of these popular editors is no longer very popular. But you should feel free to use whatever you are comfortable with as long as it works.

### 3.2.1 Writing C programs with Emacs

To start Emacs, type `emacs` at the command line. If you are actually sitting at a Zoo node it should put up a new window. If not, Emacs will take over the current window. If you have never used Emacs before, you should immediately type `C-h t` (this means hold down the Control key, type `h`, then type `t` without holding down the Control key). This will pop you into the Emacs built-in tutorial.

#### 3.2.1.1 My favorite Emacs commands

General note: `C-x` means hold down Control and press `x`; `M-x` means hold down Alt (Emacs calls it “Meta”) and press `x`. For `M-x` you can also hit Esc and then `x`.

C-h

Get help. Everything you could possibly want to know about Emacs is available through this command. Some common versions: `C-h t` puts up the tutorial, `C-h b` lists every command available in the current mode, `C-h k` tells you what a particular sequence of keystrokes does, and `C-h l` tells you what the last 50 or so characters you typed were (handy if Emacs just garbled your file and you want to know what command to avoid in the future).

C-x u

Undo. Undoes the last change you made to the current buffer. Type it again to undo more things. A lifesaver. Note that it can only undo back to the time you first loaded the file into Emacs—if you want to be able to back out of bigger changes, use `git` (described below).

C-x C-s

Save. Saves changes to the current buffer out to its file on disk.

C-x C-f

Edit a different file.

C-x C-c

Quit out of Emacs. This will ask you if you want to save any buffers that have been modified. You probably want to answer yes (`y`) for each one, but you can answer no (`n`) if you changed some file inside Emacs but want to throw the changes away.

C-f

Go forward one character.

C-b

Go back one character.

C-n

Go to the next line.

C-p

Go to the previous line.

C-a

Go to the beginning of the line.

C-k

Delete the rest of the line starting with the current position. Useful Emacs idiom: `C-a C-k`.

C-y

“Yank.” Get back what you just deleted.

TAB

Re-indent the current line. In C mode this will indent the line according to Emacs’s notion of how C should be indented.

M-x compile

Compile a program. This will ask you if you want to save out any unsaved buffers and then run a compile command of your choice (see the section on compiling programs below). The exciting thing about `M-x compile` is that if your program has errors in it, you can type `` C-x ` `` to jump to the next error, or at least where `gcc` thinks the next error is.

### 3.2.2 Using Vi instead of Emacs

If you don’t find yourself liking Emacs very much, you might want to try Vim instead. Vim is a vastly enhanced reimplementation of the classic `vi` editor, which I personally find easier to use than Emacs. Type `vimtutor` to run the tutorial.

One annoying feature of Vim is that it is hard to figure out how to quit. If you don’t mind losing all of your changes, you can always get out by hitting the Escape key a few times and then typing ~~~\\\\\\ :qa!\\\\\\ ~~~

To run Vim, type `vim` or `vim filename` from the command line. Or you can use the graphical version `gvim`, which pops up its own window.

Vim is a _modal_ editor, meaning that at any time you are in one of several modes (normal mode, insert mode, replace mode, operator-pending mode, etc.), and the interpretation of keystrokes depends on which mode you are in. So typing `jjjj` in normal mode moves the cursor down four lines, while typing `jjjj` in insert mode inserts the string `jjjj` at the current position. Most of the time you will be in either normal mode or insert mode. There is also a command mode entered by hitting `:` that lets you type longer commands, similar to the Unix command-line or M-x in Emacs.

#### 3.2.2.1 My favorite Vim commands

##### 3.2.2.1.1 Normal mode

:h

Get help. (Hit Enter at the end of any command that starts with a colon.) Escape

Get out of whatever strange mode you are in and go back to normal mode. You will need to use this whenever you are done typing code and want to get back to typing commands.

i

Enter insert mode. You will need to do this to type anything. The command `a` also enters insert mode, but puts new text after the current cursor position instead of before it.

u

Undo. Undoes the last change you made to the current buffer. Type it again to undo more things. If you undid something by mistake, c-`R` (control `R`) will redo the last undo (and can also be repeated).

:w

Write the current file to disk. Use `:w filename` to write it to `filename`. Use `:wa` to write all files that you have modified. The command `ZZ` does the same thing without having to hit Enter at the end.

:e filename

Edit a different file.

:q

Quit. Vi will refuse to do this if you have unwritten files. See `:wa` for how to fix this, or use `:q!` if you want to throw away your changes and quit anyway. The shortcuts `:x` and `:wq` do a write of the current file followed by quitting.

h, j, k, l

Move the cursor left, down, up, or right. You can also use the arrow keys (in both normal mode and insert mode).

x

Delete the current character.

D

Delete to end of line.

dd

Delete all of the current line. This is a special case of a more general `d` command. If you precede it with a number, you can delete multiple lines: `5dd` deletes the next 5 lines. If you replace the second `d` with a motion command, you delete until wherever you land: `d$` deletes to end of line (`D` is faster), `dj` deletes this line and the line after it, `d%` deletes the next matching group of parentheses/braces/brackets and whatever is between them, `dG` deletes to end of file—there are many possibilities. All of these save what you deleted into register `""` so you can get them back with `p`.

yy

Like `dd`, but only saves the line to register `""` and doesn’t delete it. (Think _copy_). All the variants of `dd` work with `yy`: `5yy`, `y$`, `yj`, `y%`, etc.

p

Pull whatever is in register `""`. (Think _paste_).

<< and >>

Outdent or indent the current line one tab stop.

:make

Run `make` in the current directory. You can also give it arguments, e.g., `:make myprog`, `:make test`. Use `:cn` to go to the next error if you get errors.

:!

Run a command, e.g., `:! echo hello world` or `:! gdb myprogram`. Returns to Vim when the command exits (control-C can sometimes be helpful if your command isn’t exiting when it should). This works best if you ran Vim from a shell window; it doesn’t work very well if Vim is running in its own window.

##### 3.2.2.1.2 Insert mode

control-P and control-N

These are completion commands that attempt to expand a partial word to something it matches elsewhere in the buffer. So if you are a good person and have named a variable `informativeVariableName` instead of `ivn`, you can avoid having to type the entire word by typing `inf`<control-P> if it’s the only word in your buffer that starts with `inf`.

control-O and control-I

Jump to the last cursor position before a big move / back to the place you jumped from.

ESC

Get out of insert mode!

#### 3.2.2.2 Settings

Unlike Emacs, Vim’s default settings are not very good for editing C programs. You can fix this by creating a file called `.vimrc` in your home directory with the following commands:

    set shiftwidth=4
    set autoindent
    set backup
    set cindent
    set hlsearch
    set incsearch
    set showmatch
    set number
    syntax on
    filetype plugin on
    filetype indent on
    

[examples/sample.vimrc](examples/sample.vimrc)

(You can download this file by clicking on the link.)

In Vim, you can type e.g. `:help backup` to find out what each setting does. Note that because `.vimrc` starts with a `.`, it won’t be visible to `ls` unless you use `ls -a` or `ls -A`.

3.3 Compilation tools
---------------------

### 3.3.1 The GNU C compiler `gcc`

A C program will typically consist of one or more files whose names end with `.c`. To compile `foo.c`, you can type `gcc foo.c`. Assuming `foo.c` contains no errors egregious enough to be detected by the extremely forgiving C compiler, this will produce a file named `a.out` that you can then execute by typing `./a.out`.

If you want to debug your program using `gdb` or give it a different name, you will need to use a longer command line. Here’s one that compiles `foo.c` to `foo` (run it using `./foo`) and includes the information that `gdb` needs: `gcc -g3 -o foo foo.c`

By default, `gcc` doesn’t check everything that might be wrong with your program. But if you give it a few extra arguments, it will warn you about many (but not all) potential problems: `gcc -g3 -Wall -o foo foo.c`.

### 3.3.2 Make

For complicated programs involving multiple source files, you are probably better off using `make` than calling `gcc` directly. Make is a “rule-based expert system” that figures out how to compile programs given a little bit of information about their components.

For example, if you have a file called `foo.c`, try typing `make foo` and see what happens.

In general you will probably want to write a `Makefile`, which is named `Makefile` or `makefile` and tells `make` how to compile programs in the same directory. Here’s a typical Makefile:

    # Any line that starts with a sharp is a comment and is ignored
    # by Make.
    
    # These lines set variables that control make's default rules.
    # We STRONGLY recommend putting "-g3 -Wall" in your CFLAGS.
    CC=gcc
    CFLAGS=-g3 -Wall
    
    # The next line is a dependency line.
    # It says that if somebody types "make all"
    # make must first make "hello-world".
    # By default the left-hand-side of the first dependency is what you
    # get if you just type "make" with no arguments.
    all: hello-world
    
    # How do we make hello-world?
    # The dependency line says you need to first make hello-world.o
    # and hello-library.o
    hello-world: hello-world.o hello-library.o
    	# Subsequent lines starting with a TAB character give
    	# commands to execute.
    	# This command uses make built-in variables to avoid
    	# retyping (and getting things wrong):
    	#  $@ = target hello-world
    	#  $^ = dependencies hello-world.o and hello-library.o
    	$(CC) $(CFLAGS) -o $@ $^
    	# You can put whatever commands you want.
    	echo "I just built hello-world!  Hooray!"
    
    # Here we are saying that hello-world.o and hello-library.o
    #  should be rebuilt whenever their corresponding source file
    #  or hello-library.h changes.
    # There are no commands attached to these dependency lines, so
    #  make will have to figure out how to do that somewhere else
    #  (probably from the builtin .c -> .o rule).
    hello-world.o: hello-world.c hello-library.h
    hello-library.o: hello-library.c hello-library.h
    
    # Command lines can do more than just build things.  For example,
    # "make test" will rebuild hello-world (if necessary) and then run it.
    test: hello-world
    	./hello-world
    
    # This lets you type "make clean" and get rid of anything you can
    # rebuild.  The $(RM) variable is predefined to "rm -f"
    clean:
    	$(RM) hello-world *.o

[examples/usingMake/Makefile](examples/usingMake/Makefile)

Given a Makefile, make looks at each dependency line and asks: (a) does the target on the left hand side exist, and (b) is it older than the files it depends on. If so, it looks for a set of commands for rebuilding the target, after first rebuilding any of the files it depends on; the commands it runs will be underneath some dependency line where the target appears on the left-hand side. It has built-in rules for doing common tasks like building `.o` files (which contain machine code) from `.c` files (which contain C source code). If you have a fake target like `all` above, it will try to rebuild everything `all` depends on because there is no file named `all` (one hopes).

#### 3.3.2.1 Make gotchas

Make really really cares that the command lines start with a TAB character. TAB looks like eight spaces in Emacs and other editors, but it isn’t the same thing. If you put eight spaces in (or a space and a TAB), Make will get horribly confused and give you an incomprehensible error message about a “missing separator”. This misfeature is so scary that I avoided using make for years because I didn’t understand what was going on. Don’t fall into that trap—make really is good for you, especially if you ever need to recompile a huge program when only a few source files have changed.

If you use GNU Make (on a zoo node), note that beginning with version 3.78, GNU Make prints a message that hints at a possible SPACEs-vs-TAB problem, like this:

    $ make
    Makefile:23:*** missing separator (did you mean TAB instead of 8 spaces?).  Stop.

If you need to repair a Makefile that uses spaces, one way of converting leading spaces into TABs is to use the `unexpand` program:

    $ mv Makefile Makefile.old
    $ unexpand Makefile.old > Makefile

3.4 Debugging tools
-------------------

The standard debugger on the Zoo is `gdb`. Also useful is the memory error checker `valgrind`. Below are some notes on debugging in general and using these programs in particular.

### 3.4.1 Debugging in general

Basic method of all debugging:

1.  Know what your program is supposed to do.
2.  Detect when it doesn’t.
3.  Fix it.

A tempting mistake is to skip step 1, and just try randomly tweaking things until the program works. Better is to see what the program is doing internally, so you can see exactly where and when it is going wrong. A second temptation is to attempt to intuit where things are going wrong by staring at the code or the program’s output. Avoid this temptation as well: let the computer tell you what it is really doing inside your program instead of guessing.

### 3.4.2 Assertions

Every non-trivial C program should include `<assert.h>`, which gives you the `assert` macro (see Appendix B6 of K&R). The `assert` macro tests if a condition is true and halts your program with an error message if it isn’t:

    #include <assert.h>
    
    int
    main(int argc, char **argv)
    {
        assert(2+2 == 5);
        return 0;
    }

[examples/debugging/no.c](examples/debugging/no.c)

Compiling and running this program produces the following output:

    $ gcc -o no no.c
    $ ./no
    no: no.c:6: main: Assertion `2+2 == 5' failed.

Line numbers and everything, even if you compile with the optimizer turned on. Much nicer than a mere segmentation fault, and if you run it under the debugger, the debugger will stop exactly on the line where the `assert` failed so you can poke around and see why.

### 3.4.3 The GNU debugger `gdb`

The standard debugger on Linux is called `gdb`. This lets you run your program under remote control, so that you can stop it and see what is going on inside.

You can also use `ddd`, which is a graphical front-end for `gdb`. There is an [extensive tutorial](http://www.gnu.org/software/ddd/manual/html_mono/ddd.html) available for `ddd`, so we will concentrate on the command-line interface to `gdb` here.

Warning: Though `gdb` is rock-solid when running on an actual Linux kernel, if you are running on a different underlying operating system like Windows (including Windows Subsystem for Linux) or OS X, it may not work as well, either missing errors that it should catch or in some cases not starting at all. In either case you can try debugging on the Zoo machines instead. For OS X, you might also have better results using the standard OS X debugger `lldb`, which is similar enough to `gdb` to do everything `gdb` can do while being different enough that you will need to learn its own set of commands. Most IDEs that support C also include debugging tools.

Getting back to `gdb`, we’ll look at a contrived example. Suppose you have the following program `bogus.c`:

    #include <stdio.h>
    
    /* Print the sum of the integers from 1 to 1000 */
    int
    main(int argc, char **argv)
    {
        int i;
        int sum;
    
        sum = 0;
        for(i = 0; i -= 1000; i++) {
            sum += i;
        }
        printf("%d\n", sum);
        return 0;
    }

[examples/debugging/bogus.c](examples/debugging/bogus.c)

Let’s compile and run it and see what happens. Note that we include the flag `-g3` to tell the compiler to include debugging information. This allows `gdb` to translate machine addresses back into identifiers and line numbers in the original program for us.

    $ gcc -g3 -o bogus bogus.c
    $ ./bogus
    -34394132
    $

That doesn’t look like the sum of 1 to 1000. So what went wrong? If we were clever, we might notice that the test in the for loop is using the mysterious `-=` operator instead of the `<=` operator that we probably want. But let’s suppose we’re not so clever right now—it’s four in the morning, we’ve been working on `bogus.c` for twenty-nine straight hours, and there’s a `-=` up there because in our befuddled condition we know in our bones that it’s the right operator to use. We need somebody else to tell us that we are deluding ourselves, but nobody is around this time of night. So we’ll have to see what we can get the computer to tell us.

The first thing to do is fire up `gdb`, the debugger. This runs our program in stop-motion, letting us step through it a piece at a time and watch what it is actually doing. In the example below gdb is run from the command line. You can also run it directly from Emacs with `M-x gdb`, which lets Emacs track and show you where your program is in the source file with a little arrow, or (if you are logged in directly on a Zoo machine) by running `ddd`, which wraps `gdb` in a graphical user interface.

    $ gdb bogus
    GNU gdb 4.17.0.4 with Linux/x86 hardware watchpoint and FPU support
    Copyright 1998 Free Software Foundation, Inc.
    GDB is free software, covered by the GNU General Public License, and you are
    welcome to change it and/or distribute copies of it under certain conditions.
    Type "show copying" to see the conditions.
    There is absolutely no warranty for GDB.  Type "show warranty" for details.
    This GDB was configured as "i386-redhat-linux"...
    (gdb) run
    Starting program: /home/accts/aspnes/tmp/bogus 
    -34394132
    
    Program exited normally.

So far we haven’t learned anything. To see our program in action, we need to slow it down a bit. We’ll stop it as soon as it enters `main`, and step through it one line at a time while having it print out the values of the variables.

    (gdb) break main
    Breakpoint 1 at 0x8048476: file bogus.c, line 9.
    (gdb) run
    Starting program: /home/accts/aspnes/tmp/bogus 
    
    Breakpoint 1, main (argc=1, argv=0xbffff9ac) at bogus.c:9
    9           sum = 0;
    (gdb) display sum
    1: sum = 1
    (gdb) n
    10          for(i = 0; i -= 1000; i++)
    1: sum = 0
    (gdb) display i
    2: i = 0
    (gdb) n
    11              sum += i;
    2: i = -1000
    1: sum = 0
    (gdb) n
    10          for(i = 0; i -= 1000; i++)
    2: i = -1000
    1: sum = -1000
    (gdb) n
    11              sum += i;
    2: i = -1999
    1: sum = -1000
    (gdb) n
    10          for(i = 0; i -= 1000; i++)
    2: i = -1999
    1: sum = -2999
    (gdb) quit
    The program is running.  Exit anyway? (y or n) y
    $

Here we are using `break main` to tell the program to stop as soon as it enters `main`, `display` to tell it to show us the value of the variables `i` and `sum` whenever it stops, and `n` (short for `next`) to execute the program one line at a time.

When stepping through a program, gdb displays the line it will execute _next_ as well as any variables you’ve told it to display. This means that any changes you see in the variables are the result of the _previous_ displayed line. Bearing this in mind, we see that `i` drops from 0 to -1000 the very first time we hit the top of the `for` loop and drops to -1999 the next time. So something bad is happening in the top of that `for` loop, and if we squint at it a while we might begin to suspect that `i -= 1000` is not the nice simple test we might have hoped it was.

#### 3.4.3.1 My favorite gdb commands

help

Get a description of gdb’s commands.

run

Runs your program. You can give it arguments that get passed in to your program just as if you had typed them to the shell. Also used to restart your program from the beginning if it is already running.

quit

Leave gdb, terminating your program if necessary.

break

Set a breakpoint, which is a place where gdb will automatically stop your program. Some examples: - `break somefunction` stops before executing the first line `somefunction`. - `break 117` stops before executing line number 117.

list

Show part of your source file with line numbers (handy for figuring out where to put breakpoints). Examples: - `list somefunc` lists all lines of `somefunc`. - `list 117-123` lists lines 117 through 123.

next

Execute the next line of the program, including completing any procedure calls in that line.

step

Execute the next step of the program, which is either the next line if it contains no procedure calls, or the entry into the called procedure.

finish

Continue until you get out of the current procedure (or hit a breakpoint). Useful for getting out of something you stepped into that you didn’t want to step into.

cont

(Or `continue`). Continue until (a) the end of the program, (b) a fatal error like a Segmentation Fault or Bus Error, or (c) a breakpoint. If you give it a numeric argument (e.g., `cont 1000`) it will skip over that many breakpoints before stopping.

print

Print the value of some expression, e.g. `print i`.

display

Like `print`, but runs automatically every time the program stops. Useful for watching values that change often.

backtrace

Show all the function calls on the stack, with arguments. Can be abbreviated as `bt`. Do `bt full` if you also want to see local variables in each function.

set disable-randomization off

Not something you will need every day, but you should try this before running your program if it is producing segmentation faults outside of `gdb` but not inside. Normally the Linux kernel randomizes the position of bits of your program before running it, to make its response to buffer overflow attacks less predictable. By default, `gdb` turns this off so that the behavior of your program is consistent from one execution to the next. But sometimes this means that a pointer that had been bad with address randomization (causing a segmentation fault) turns out not to be bad without. This option will restore the standard behavior even inside `gdb` and give you some hope of finding what went wrong.

#### 3.4.3.2 Debugging strategies

In general, the idea behind debugging is that a bad program starts out OK, but after executing for a while it gets confused and starts misbehaving. If you can find the exact moment in its execution where it first starts acting up, you can see exactly what piece of code is causing the problem and have a reasonably good chance of being able to fix it. So a typical debugging strategy is to put in a breakpoint (using `break`) somewhere before the confusion hits, “instrument” the program (using `display`) so that you can watch it getting confused, and step through it (using `next`, `step`, or breakpoints and `cont`) until you find the point of failure. Sometimes this process requires restarting the program (using `run`) if you skip over this point without noticing it immediately.

For large or long-running programs, it often makes sense to do binary search to find the point of failure. Put in a breakpoint somewhere (say, on a function that is called many times or at the top of a major loop) and see what the state of the program is after going through the breakpoint 1000 times (using something like `cont 1000`). If it hasn’t gone off the rails yet, try restarting and going through 2000 times. Eventually you bracket the error as occurring (for example) somewhere between the 4000th and 8000th occurrence of the breakpoint. Now try stepping through 6000 times; if the program is looking good, you know the error occurs somewhere between the 6000th and 8000th breakpoint. Adding a dozen or so more experiments like this should be enough isolate the bug to a specific line of code.

_The key to all debugging_ is knowing what your code is supposed to do. If you don’t know this, then you can’t tell the cases where it is working from the cases where it isn’t. If you’re confused about what your code is supposed to be doing, you need to figure out what exactly you want it to do. If you can figure that out, often it will be obvious what is going wrong. If it isn’t obvious, you can always go back to `gdb`.

#### 3.4.3.3 Common applications of `gdb`

Here are some typical classes of bugs and how to squish them with `gdb`. (The same instructions usually work for `ddd`.)

##### 3.4.3.3.1 Watching your program run

1.  Compile your program with the `-g3` flag. You can still run `gdb` if you don’t do this, but it won’t be able to show you variable names or source lines.
2.  Run `gdb` with `gdb` _programname_.
3.  Type `break main` to stop at the start of the `main` routine.
4.  Run your program with `run` _arguments_. The `run` command stands in for the program name. You can also redirect input as in the shell with `run` _arguments_ < _filename_.
5.  When the program stops, you can display variables in the current function or expressions involving these variables using `display`, as in `display x`, `display a[i]`, `display z+17`. In `ddd`, double-clicking on a variable name will have the same effect. Use `undisplay` to get rid of any displays you don’t want.
6.  To step through your program, use `next` (always goes to next line in the current function, not dropping down into function calls), `step` (go to the next executed line, even if it is inside a called function), `finish` (run until the current function returns), and `cont` (run until the end of the program or the next breakpoint).

This can be handy if you don’t particularly know what is going on in your program and want to see.

##### 3.4.3.3.2 Dealing with failed assertions

Run the program as described above. When you hit the bad `assert`, you will stop several functions deep from where it actually happened. Use `up` to get up to the function that has the call to `assert` then use `print` or `display` to figure out what is going on.

Example program:

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    int
    main(int argc, char **argv)
    {
        int x;
    
        x = 3;
    
        assert(x+x == 4);
    
        return 0;
    }

[examples/debugging/assertFailed.c](examples/debugging/assertFailed.c)

With `gdb` in action:

    $ gcc -g3 -o assertFailed assertFailed.c 
    $ gdb assertFailed
    GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
    Copyright (C) 2014 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "i686-linux-gnu".
    Type "show configuration" for configuration details.
    For bug reporting instructions, please see:
    <http://www.gnu.org/software/gdb/bugs/>.
    Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.
    For help, type "help".
    Type "apropos word" to search for commands related to "word"...
    Reading symbols from assertFailed...done.
    (gdb) run
    Starting program: /home/aspnes/g/classes/223/notes/examples/debugging/assertFailed 
    assertFailed: assertFailed.c:12: main: Assertion `x+x == 4' failed.
    
    Program received signal SIGABRT, Aborted.
    0xb7fdd416 in __kernel_vsyscall ()
    (gdb) up
    #1  0xb7e43577 in __GI_raise (sig=sig@entry=6) at ../nptl/sysdeps/unix/sysv/linux/raise.c:56
    56  ../nptl/sysdeps/unix/sysv/linux/raise.c: No such file or directory.
    (gdb) up
    #2  0xb7e469a3 in __GI_abort () at abort.c:89
    89  abort.c: No such file or directory.
    (gdb) up
    #3  0xb7e3c6c7 in __assert_fail_base (fmt=0xb7f7a8b4 "%s%s%s:%u: %s%sAssertion `%s' failed.\n%n", 
        assertion=assertion@entry=0x804850f "x+x == 4", file=file@entry=0x8048500 "assertFailed.c", 
        line=line@entry=12, function=function@entry=0x8048518 <__PRETTY_FUNCTION__.2355> "main") at assert.c:92
    92  assert.c: No such file or directory.
    (gdb) up
    #4  0xb7e3c777 in __GI___assert_fail (assertion=0x804850f "x+x == 4", file=0x8048500 "assertFailed.c", line=12, 
        function=0x8048518 <__PRETTY_FUNCTION__.2355> "main") at assert.c:101
    101 in assert.c
    (gdb) up
    #5  0x0804845d in main (argc=1, argv=0xbffff434) at assertFailed.c:12
    12      assert(x+x == 4);
    (gdb) print x
    $1 = 3

Here we see that `x` has value 3, which may or may not be the right value, but certainly violates the assertion.

##### 3.4.3.3.3 Dealing with segmentation faults

Very much like the previous case. Run `gdb` until the segmentation fault hits, then look around for something wrong.

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    int
    main(int argc, char **argv)
    {
        int a[1000];
        int i;
    
        i = -1771724;
    
        printf("%d\n", a[i]);
    
        return 0;
    }

[examples/debugging/segmentationFault.c](examples/debugging/segmentationFault.c)

    $ gcc -g3 -o segmentationFault segmentationFault.c 
    $ gdb segmentationFault
    GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
    [...]
    Reading symbols from segmentationFault...done.
    (gdb) run
    Starting program: /home/aspnes/g/classes/223/notes/examples/debugging/segmentationFault 
    
    Program received signal SIGSEGV, Segmentation fault.
    0x08048435 in main (argc=1, argv=0xbffff434) at segmentationFault.c:13
    13      printf("%d\n", a[i]);
    (gdb) print a[i]
    $1 = 0
    (gdb) print i
    $2 = -1771724

Curiously, `gdb` has no problem coming up with a value for `a[i]`. But `i` looks pretty suspicious.

##### 3.4.3.3.4 Dealing with infinite loops

Run `gdb`, wait a while, then hit control-C. This will stop `gdb` wherever it is. If you have an infinite loop, it’s likely that you will be in it, and that the index variables will be doing something surprising. Use `display` to keep an eye on them and do `next` a few times.

    
    $ gcc -g3 -o infiniteLoop infiniteLoop.c
    $ gdb infiniteLoop
    GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
    [...]
    Reading symbols from infiniteLoop...done.
    (gdb) run
    Starting program: /home/aspnes/g/classes/223/notes/examples/debugging/infiniteLoop 
    ^C
    Program received signal SIGINT, Interrupt.
    main (argc=1, argv=0xbffff434) at infiniteLoop.c:11
    11          i *= 37;
    (gdb) display i
    1: i = 0
    (gdb) n
    10      for(i = 0; i < 10; i += 0) {
    1: i = 0
    (gdb) n
    11          i *= 37;
    1: i = 0
    (gdb) n
    10      for(i = 0; i < 10; i += 0) {
    1: i = 0
    (gdb) n
    11          i *= 37;
    1: i = 0
    (gdb) n
    10      for(i = 0; i < 10; i += 0) {
    1: i = 0
    (gdb) n
    11          i *= 37;
    1: i = 0

##### 3.4.3.3.5 Mysterious variable changes

Sometimes pointer botches don’t manifest as good, honest segmentation faults but instead as mysterious changes to seemingly unrelated variables. You can catch these in the act using conditional breakpoints. The downside is that you can only put conditional breakpoints on particular lines.

Here’s a program that violates array bounds (which C doesn’t detect):

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    int
    main(int argc, char **argv)
    {
        int x;
        int a[10];
        int i;
    
        x = 5;
    
        for(i = -1; i < 11; i++) {
            a[i] = 37;
        }
    
        assert(x == 5);
    
        return 0;
    }

[examples/debugging/mysteryChange.c](examples/debugging/mysteryChange.c)

In the debugging session below, it takes a couple of attempts to catch the change in `x` before hitting the failed assertion.

    $ gcc -g3 -o mysteryChange mysteryChange.c 
    $ gdb mysteryChange
    GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
    [...]
    Reading symbols from mysteryChange...done.
    (gdb) run
    Starting program: /home/aspnes/g/classes/223/notes/examples/debugging/mysteryChange 
    mysteryChange: mysteryChange.c:18: main: Assertion `x == 5' failed.
    
    Program received signal SIGABRT, Aborted.
    0xb7fdd416 in __kernel_vsyscall ()
    (gdb) list main
    2   #include <stdlib.h>
    3   #include <assert.h>
    4   
    5   int
    6   main(int argc, char **argv)
    7   {
    8       int x;
    9       int a[10];
    10      int i;
    11  
    (gdb) list
    12      x = 5;
    13  
    14      for(i = -1; i < 11; i++) {
    15          a[i] = 37;
    16      }
    17  
    18      assert(x == 5);
    19  
    20      return 0;
    21  }
    (gdb) break 14 if x != 5
    Breakpoint 1 at 0x804842e: file mysteryChange.c, line 14.
    (gdb) run
    The program being debugged has been started already.
    Start it from the beginning? (y or n) y
    
    Starting program: /home/aspnes/g/classes/223/notes/examples/debugging/mysteryChange 
    mysteryChange: mysteryChange.c:18: main: Assertion `x == 5' failed.
    
    Program received signal SIGABRT, Aborted.
    0xb7fdd416 in __kernel_vsyscall ()
    (gdb) break 15 if x != 5
    Breakpoint 2 at 0x8048438: file mysteryChange.c, line 15.
    (gdb) run
    The program being debugged has been started already.
    Start it from the beginning? (y or n) y
    
    Starting program: /home/aspnes/g/classes/223/notes/examples/debugging/mysteryChange 
    
    Breakpoint 2, main (argc=1, argv=0xbffff434) at mysteryChange.c:15
    15          a[i] = 37;
    (gdb) print i
    $1 = 0
    (gdb) print a[0]
    $2 = 134520832
    (gdb) print a[-1]
    $3 = 37
    (gdb) print x
    $4 = 37

One thing to note is that a breakpoint stops before the line it is on executes. So when we hit the breakpoint on line 15 (`gdb` having observed that `x != 5` is true), `i` has the value 0, but the damage happened in the previous interation when `i` was -1. If we want to see exactly what happened then, we’d need to go back in time. We can’t do this, but we could set an earlier breakpoint and run the program again.

### 3.4.4 Valgrind

The `valgrind` program can be used to detect some (but not all) common errors in C programs that use pointers and dynamic storage allocation. On the Zoo, you can run `valgrind` on your program by putting `valgrind` at the start of the command line:

    valgrind ./my-program arg1 arg2 < test-input

This will run your program and produce a report of any allocations and de-allocations it did. It will also warn you about common errors like using unitialized memory, dereferencing pointers to strange places, writing off the end of blocks allocated using `malloc`, or failing to free blocks.

You can suppress all of the output except errors using the `-q` option, like this:

    valgrind -q ./my-program arg1 arg2 < test-input

You can also turn on more tests, e.g.

    valgrind -q --tool=memcheck --leak-check=yes ./my-program arg1 arg2 < test-input

See `valgrind --help` for more information about the (many) options, or look at the documentation at [http://valgrind.org/](http://valgrind.org/) for detailed information about what the output means. For some common `valgrind` messages, see the examples section below.

If you want to run `valgrind` on your own machine, you may be able to find a version that works at [http://valgrind.org](http://valgrind.org). Unfortunately, this is only likely to work if you are running a Unix-like operating system. This does include Linux (either on its own or inside Windows Subsystem for Linux) and OSX, but it does not include stock Windows.

#### 3.4.4.1 Compilation flags

You can run `valgrind` on any program (try `valgrind ls`); it does not require special compilation. However, the output of `valgrind` will be more informative if you compile your program with debugging information turned on using the `-g` or `-g3` flags (this is also useful if you plan to watch your program running using `gdb`, ).

#### 3.4.4.2 Automated testing

Unless otherwise specified, automated testing of your program will be done using the script in `/c/cs223/bin/vg`; this runs `/c/cs223/bin/valgrind` with the `--tool=memcheck`, `--leak-check=yes`, and `-q` options, throws away your program’s output, and replaces it with `valgrind`’s output. If you have a program named `./prog`, running `/c/cs223/bin/vg ./prog` should produce no output.

#### 3.4.4.3 Examples of some common valgrind errors

Here are some examples of `valgrind` output. In each case the example program is compiled with `-g3` so that `valgrind` can report line numbers from the source code.

You may also find it helpful to play with [this demo program](examples/valgrindErrors/valgrind_errors.c) written by the Spring 2018 course staff.

##### 3.4.4.3.1 Uninitialized values

Consider this unfortunate program, which attempts to compare two strings, one of which we forgot to ensure was null-terminated:

    #include <stdio.h>
    
    int
    main(int argc, char **argv)
    {
        char a[2];
    
        a[0] = 'a';
    
        if(!strcmp(a, "a")) {
            puts("a is \"a\"");
        }
    
        return 0;
    }

[examples/valgrindErrors/uninitialized.c](examples/valgrindErrors/uninitialized.c)

Run without valgrind, we see no errors, because we got lucky and it turned out our hand-built string was null-terminated anyway:

    $ ./uninitialized 
    a is "a"

But `valgrind` is not fooled:

    $ valgrind -q ./uninitialized 
    ==4745== Conditional jump or move depends on uninitialised value(s)
    ==4745==    at 0x4026663: strcmp (mc_replace_strmem.c:426)
    ==4745==    by 0x8048435: main (uninitialized.c:10)
    ==4745== 
    ==4745== Conditional jump or move depends on uninitialised value(s)
    ==4745==    at 0x402666C: strcmp (mc_replace_strmem.c:426)
    ==4745==    by 0x8048435: main (uninitialized.c:10)
    ==4745== 
    ==4745== Conditional jump or move depends on uninitialised value(s)
    ==4745==    at 0x8048438: main (uninitialized.c:10)
    ==4745== 

Here we get a lot of errors, but they are all complaining about the same call to `strcmp`. Since it’s unlikely that `strcmp` itself is buggy, we have to assume that we passed some uninitialized location into it that it is looking at. The fix is to add an assignment `a[1] = '\0'` so that no such location exists.

##### 3.4.4.3.2 Bytes definitely lost

Here is a program that calls `malloc` but not `free`:

    #include <stdio.h>
    #include <stdlib.h>
    
    int
    main(int argc, char **argv)
    {
        char *s;
    
        s = malloc(26);
    
        return 0;
    }

[examples/valgrindErrors/missing\_free.c](examples/valgrindErrors/missing_free.c)

With no extra arguments, `valgrind` will not look for this error. But if we turn on `--leak-check=yes`, it will complain:

    $ valgrind -q --leak-check=yes ./missing_free
    ==4776== 26 bytes in 1 blocks are definitely lost in loss record 1 of 1
    ==4776==    at 0x4024F20: malloc (vg_replace_malloc.c:236)
    ==4776==    by 0x80483F8: main (missing_free.c:9)
    ==4776== 

Here the stack trace in the output shows where the bad block was allocated: inside `malloc` (specifically the paranoid replacement `malloc` supplied by `valgrind`), which was in turn called by `main` in line 9 of `missing_free.c`. This lets us go back and look at what block was allocated in that line and try to trace forward to see why it wasn’t freed. Sometimes this is as simple as forgetting to include a `free` statement anywhere, but in more complicated cases it may be because I somehow lose the pointer to the block by overwriting the last variable that points to it or by embedding it in some larger structure whose components I forget to free individually.

##### 3.4.4.3.3 Invalid write or read operations

These are usually operations that you do off the end of a block from `malloc` or on a block that has already been freed.

An example of the first case:

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    int
    main(int argc, char **argv)
    {
        char *s;
    
        s = malloc(1);
        s[0] = 'a';
        s[1] = '\0';
    
        puts(s);
    
        return 0;
    }

[examples/valgrindErrors/invalid\_operations.c](examples/valgrindErrors/invalid_operations.c)

    ==7141== Invalid write of size 1
    ==7141==    at 0x804843B: main (invalid_operations.c:12)
    ==7141==  Address 0x419a029 is 0 bytes after a block of size 1 alloc'd
    ==7141==    at 0x4024F20: malloc (vg_replace_malloc.c:236)
    ==7141==    by 0x8048428: main (invalid_operations.c:10)
    ==7141== 
    ==7141== Invalid read of size 1
    ==7141==    at 0x4026063: __GI_strlen (mc_replace_strmem.c:284)
    ==7141==    by 0x409BCE4: puts (ioputs.c:37)
    ==7141==    by 0x8048449: main (invalid_operations.c:14)
    ==7141==  Address 0x419a029 is 0 bytes after a block of size 1 alloc'd
    ==7141==    at 0x4024F20: malloc (vg_replace_malloc.c:236)
    ==7141==    by 0x8048428: main (invalid_operations.c:10)
    ==7141== 

An example of the second:

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    int
    main(int argc, char **argv)
    {
        char *s;
    
        s = malloc(2);
        free(s);
    
        s[0] = 'a';
        s[1] = '\0';
    
        puts(s);
    
        return 0;
    }

[examples/valgrindErrors/freed\_block.c](examples/valgrindErrors/freed_block.c)

    ==7144== Invalid write of size 1
    ==7144==    at 0x804846D: main (freed_block.c:13)
    ==7144==  Address 0x419a028 is 0 bytes inside a block of size 2 free'd
    ==7144==    at 0x4024B3A: free (vg_replace_malloc.c:366)
    ==7144==    by 0x8048468: main (freed_block.c:11)
    ==7144== 
    ==7144== Invalid write of size 1
    ==7144==    at 0x8048477: main (freed_block.c:14)
    ==7144==  Address 0x419a029 is 1 bytes inside a block of size 2 free'd
    ==7144==    at 0x4024B3A: free (vg_replace_malloc.c:366)
    ==7144==    by 0x8048468: main (freed_block.c:11)
    ==7144== 
    ==7144== Invalid read of size 1
    ==7144==    at 0x4026058: __GI_strlen (mc_replace_strmem.c:284)
    ==7144==    by 0x409BCE4: puts (ioputs.c:37)
    ==7144==    by 0x8048485: main (freed_block.c:16)
    [... more lines of errors deleted ...]

In both cases the problem is that we are operating on memory that is not guaranteed to be allocated to us. For short programs like these, we might get lucky and have the program work anyway. But we still want to avoid bugs like this because we might not get lucky.

How do we know which case is which? If I write off the end of an existing block, I’ll see something like `Address 0x419a029 is 0 bytes after a block of size 1 alloc'd`, telling me that I am working on an address after a block that is still allocated. When I try to write to a freed block, the message changes to `Address 0x419a029 is 1 bytes inside a block of size 2 free'd`, where the `free'd` part tells me I freed something I probably shouldn’t have. Fixing the first class of bugs is usually just a matter of allocating a bigger block (but don’t just do this without figuring out _why_ you need a bigger block, or you’ll just be introducing random mutations into your code that may cause other problems elsewhere). Fixing the second class of bugs usually involves figuring out why you freed this block prematurely. In some cases you may need to re-order what you are doing so that you don’t free a block until you are completely done with it.

### 3.4.5 Not recommended: debugging output

A tempting but usually bad approach to debugging is to put lots of `printf` statements in your code to show what is going on. The problem with this compared to using `assert` is that there is no built-in test to see if the output is actually what you’d expect. The problem compared to `gdb` is that it’s not flexible: you can’t change your mind about what is getting printed out without editing the code. A third problem is that the output can be misleading: in particular, `printf` output is usually buffered, which means that if your program dies suddenly there may be output still in the buffer that is never flushed to `stdout`. This can be very confusing, and can lead you to believe that your program fails earlier than it actually does.

If you really need to use `printf` or something like it for debugging output, here are a few rules of thumb to follow to mitigate the worst effects:

1.  Use `fprintf(stderr, ...)` instead of `printf(...)`; this allows you to redirect your program’s regular output somewhere that keeps it separate from the debugging output (but beware of misleading interleaving of the two streams—buffering may mean that output to `stdout` and `stderr` appears to arrive out of order). It also helps that output to `stderr` is usually unbuffered, avoiding the problem of lost output.
2.  If you must output to `stdout`, put `fflush(stdout)` after any output operation you suspect is getting lost in the buffer. The `fflush` function forces any buffered output to be emitted immediately.
3.  Keep all arguments passed to `printf` as simple as possible and beware of faults in your debugging code itself. If you write `printf("a[key] == %d\n", a[key])` and `key` is some bizarre value, you will never see the result of this `printf` because your program will segfault while evaluating `a[key]`. Naturally, this is more likely to occur if the argument is `a[key]->size[LEFTOVERS].cleanupFunction(a[key])` than if it’s just `a[key]`, and if it happens it will be harder to figure out where in this complex chain of array indexing and pointer dereferencing the disaster happened. Better is to wait for your program to break in `gdb`, and use the `print` statement on increasingly large fragments of the offending expression to see where the bogus array index or surprising null pointer is hiding.
4.  Wrap your debugging output in an `#ifdef` so you can turn it on and off easily.

Bearing in mind that this is a bad idea, here is an example of how one might do it as well as possible:

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    /* initialize the application */
    void
    init(void)
    {
        int x;
    
        x = *((int *) 0xbad1dea); /* if we are lucky, maybe the optimizer will remove it? */
    }
    
    int
    main(int argc, char **argv)
    {
        init();
    
    #ifdef DEBUGGING_OUTPUT
        /*
         * this type of debugging output is not recommended
         * but if you do it anyway:
         *
         * 1. Use stderr, which flushes automatically.
         * 2. Be wary of buffered data on stdout.
         * 3. Wrap your debugging statement in an #ifdef,
         *    so it is not active by default.
         */
        fputs("Returned from init() in main()\n", stderr);
    #endif
    
        return 0;
    }

[examples/debugging/usingPrintf.c](examples/debugging/usingPrintf.c)

Note that we get much more useful information if we run this under `gdb` (which will stop exactly on the bad line in `init`), but not seeing the result of the `fputs` at least tells us something.

3.5 Performance tuning
----------------------

Chapter 7 of Kernighan and Pike, _The Practice of Programming_ (Addison-Wesley, 1998) gives an excellent overview of performance tuning. This page will be limited to some Linux-specific details and an example.

### 3.5.1 Timing under Linux

Use `time`, e.g.

    $ time wc /usr/share/dict/words
     45378  45378 408865 /usr/share/dict/words
    
    real    0m0.010s
    user    0m0.006s
    sys     0m0.004s

This measures “real time” (what it sounds like), “user time” (the amount of time the program runs), and “system time” (the amount of time the operating system spends supporting your program, e.g. by loading it from disk and doing I/O). Real time need not be equal to the sum of user time and system time, since the operating system may be simultaneously running other programs.

Particularly for fast programs, times can vary from one execution to the next, e.g.

    $ time wc /usr/share/dict/words
     45378  45378 408865 /usr/share/dict/words
    
    real    0m0.009s
    user    0m0.008s
    sys     0m0.001s
    $ time wc /usr/share/dict/words
     45378  45378 408865 /usr/share/dict/words
    
    real    0m0.009s
    user    0m0.007s
    sys     0m0.002s

This arises because of measurement errors and variation in how long different operations take. But usually the variation will not be much.

Note also that `time` is often a builtin operation of your shell, so the output format may vary depending on what shell you use.

### 3.5.2 Profiling with `valgrind`

The problem with `time` is that it only tells you how much time your whole program took, but not where it spent its time. This is similar to looking at a program without a debugger: you can’t see what’s happening inside. If you want to see where your program is spending its time, you need to use a _profiler_.

The specific profiler we will use in this section is `callgrind`, a tool built into `valgrind`, which we’ve been using elsewhere to detect pointer disasters and storage leaks. Full documentation for `callgrind` can be found at [http://valgrind.org/docs/manual/cl-manual.html](http://valgrind.org/docs/manual/cl-manual.html), but we’ll give an example of typical use here.

Here is an example of a program that is unreasonably slow for what it is doing.

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    #include <string.h>
    
    /* concatenate n copies of src into dest */
    /* returns dest */
    /* caller is responsible for making dest large enough */
    char *
    replicate(char *dest, const char *src, int n)
    {
        /* truncate dest */
        dest[0] = '\0';
    
        /* BAD: each call to strcat requires walking across dest */
        for(int i = 0; i < n; i++) {
            strcat(dest, src);
        }
    
        return dest;
    }
    
    /* like strcpy, but only copies characters at indices 0, 2, 4, ...
       from src to dest */
    char *
    copyEvenCharacters(char *dest, const char *src)
    {
        int i;
        int j;
    
        /* BAD: Calls strlen on every pass through the loop */
        for(i = 0, j = 0; i < strlen(src); i += 2, j++) {
            dest[j] = src[i];
        }
    
        dest[j] = '\0';
    
        return dest;
    }
    
    /* like puts, but stops after maxChars characters */
    void
    putsRestricted(const char *s, int maxChars)
    {
        for(int i = 0; s[i]; i++) {
            if(i >= maxChars) {
                printf("[%zu more]\n", strlen(s) - i);
                return;
            } else {
                putchar(s[i]);
            }
        }
    
        putchar('\n');
    }
    
    #define SMALL (10)
    #define BIG (100000)
    #define PATTERN "abcd"
    
    #define BUFFER_SIZE (BIG * strlen(PATTERN) + 1)
    
    /* how many characters to print at once */
    #define MAX_CHARS (40)
    
    int
    main(int argc, char **argv)
    {
        char *buffer;
        char *half;
    
        buffer = malloc(BUFFER_SIZE);
        half = malloc(BUFFER_SIZE);
    
        putsRestricted(replicate(buffer, PATTERN, SMALL), MAX_CHARS);
        putsRestricted(copyEvenCharacters(half, buffer), MAX_CHARS);
    
        putsRestricted(replicate(buffer, PATTERN, BIG), MAX_CHARS);
        putsRestricted(copyEvenCharacters(half, buffer), MAX_CHARS);
    
        free(half);
        free(buffer);
    
        return 0;
    }

[examples/profiling/slow.c](examples/profiling/slow.c)

This program defines several functions for processing null-terminated strings: `replicate`, which concatenates many copies of some string together, and `copyEvenCharacters`, which copies every other character in a string to a given buffer. Unfortunately, both functions contain a hidden inefficiency arising from their use of the standard C library string functions.

The runtime of the program is not terrible, but not as sprightly as we might expect given that we are working on less than half a megabyte of text:

    $ time ./slow
    abcdabcdabcdabcdabcdabcdabcdabcdabcdabcd
    acacacacacacacacacac
    abcdabcdabcdabcdabcdabcdabcdabcdabcdabcd[399960 more]
    acacacacacacacacacacacacacacacacacacacac[199960 more]
    
    real    0m3.171s
    user    0m3.164s
    sys     0m0.001s

So we’d like to make it faster.

In this particular case, the programmer was kind enough to identify the problems in the original code in comments, but we can’t always count on that. But we can use the `callgrind` tool built into `valgrind` to find out where our program is spending most of its time.

To run `callgrind`, call `valgrind` with the `--tool=callgrind` option, like this:

    $ time valgrind --tool=callgrind ./slow
    ==5714== Callgrind, a call-graph generating cache profiler
    ==5714== Copyright (C) 2002-2017, and GNU GPL'd, by Josef Weidendorfer et al.
    ==5714== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==5714== Command: ./slow
    ==5714== 
    ==5714== For interactive control, run 'callgrind_control -h'.
    abcdabcdabcdabcdabcdabcdabcdabcdabcdabcd
    acacacacacacacacacac
    abcdabcdabcdabcdabcdabcdabcdabcdabcdabcd[399960 more]
    acacacacacacacacacacacacacacacacacacacac[199960 more]
    ==5714== 
    ==5714== Events    : Ir
    ==5714== Collected : 15339385208
    ==5714== 
    ==5714== I   refs:      15,339,385,208
    
    real    1m31.965s
    user    1m31.515s
    sys 0m0.037s

I’ve include `time` at the start of the command line to make it clear just how much of a slowdown you can expect from using `valgrind` for this purpose. Note that `valgrind` only prints a bit of summary data while executing. To get a full report, we use a separate program `callgrind_annotate`:

    $ callgrind_annotate --auto=yes --inclusive=yes > slow.callgrind

Here I sent the output to a file [slow.callgrind](examples/profiling/slow.callgrind) so I could look at it in more detail in my favorite text editor, since the actual report is pretty huge. The `--auto=yes` argument tells `callgrind_annotate` to show how many instructions were executed as part of each line of source code, and the `--inclusive=yes` argument tells use that in its report it should charge instructions executed in some function both to that function and to all functions responsible for calling it. This is usually what you want to figure out where things are going wrong.

The first thing to look at in [slow.callgrind](examples/profiling/slow.callgrind) is the table showing which functions are doing most of the work:

    --------------------------------------------------------------------------------
                Ir  file:function
    --------------------------------------------------------------------------------
    15,339,385,208  ???:0x0000000000000dd0 [/usr/lib64/ld-2.25.so]
    15,339,274,304  ???:_start [/home/accts/aspnes/g/classes/223/notes/examples/profiling/slow]
    15,339,274,293  /usr/src/debug/glibc-2.25-123-gedcf13e25c/csu/../csu/libc-start.c:(below main) [/usr/lib64/libc-2.25.so]
    15,339,273,103  slow.c:main [/home/accts/aspnes/g/classes/223/notes/examples/profiling/slow]
    15,339,273,103  /home/accts/aspnes/g/classes/223/notes/examples/profiling/slow.c:main
    11,264,058,263  slow.c:copyEvenCharacters [/home/accts/aspnes/g/classes/223/notes/examples/profiling/slow]
    11,260,141,740  /usr/src/debug/glibc-2.25-123-gedcf13e25c/string/../sysdeps/x86_64/strlen.S:strlen [/usr/lib64/ld-2.25.so]
     4,075,049,055  slow.c:replicate [/home/accts/aspnes/g/classes/223/notes/examples/profiling/slow]
     4,074,048,083  /usr/src/debug/glibc-2.25-123-gedcf13e25c/string/../sysdeps/x86_64/multiarch/strcat-ssse3.S:__strcat_ssse3 [/usr/lib64/libc-2.25.so]
           108,795  /usr/src/debug/glibc-2.25-123-gedcf13e25c/elf/rtld.c:_dl_start [/usr/lib64/ld-2.25.so]

Since each function is charged for work done by its children, the top of the list includes various setup functions included automatically by the C compiler, followed by `main`. Inside `main`, we see that the majority of the work is done in `copyEvenCharacters`, with a substantial chunk in `replicate`. The suspicious similarity in numbers suggests that most of these instructions in `copyEvenCharacters` are accounted for by calls to `strlen` and in `replicate` by calls to `__strcat_sse3`, which happens to be an assembly-language implementation of `strcat` (hence the `.S` in the source file name) that uses the special [SSE](https://en.wikipedia.org/wiki/Streaming_SIMD_Extensions) instructions in the x86 instruction set to speed up copying.

We can confirm this suspicion by looking at later parts of the file, which annotate the source code with instruction counts.

The annotated version of `slow.c` includes this annotated version of `replicate`, showing roughly 4 billion instructions executed in `__strcat_sse3`:

            .  char *
            .  replicate(char *dest, const char *src, int n)
           12  {
            .      /* truncate dest */
            4      dest[0] = '\0';
            .  
            .      /* BAD: each call to strcat requires walking across dest */
      400,050      for(int i = 0; i < n; i++) {
      600,064          strcat(dest, src);
          836  => /usr/src/debug/glibc-2.25-123-gedcf13e25c/elf/../sysdeps/x86_64/dl-trampoline.h:_dl_runtime_resolve_xsave (1x)
    4,074,048,083  => /usr/src/debug/glibc-2.25-123-gedcf13e25c/string/../sysdeps/x86_64/multiarch/strcat-ssse3.S:__strcat_ssse3 (100009x)
            .      }
            .  
            2      return dest;
            4  }

Similarly, the annotated version of `copyEvenCharacters` shows that 11 billion instructions were executed in `strlen`:

            .  char *
            .  copyEvenCharacters(char *dest, const char *src)
           12  {
            .      int i;
            .      int j;
            .  
            .      /* BAD: Calls strlen on every pass through the loop */
    2,000,226      for(i = 0, j = 0; i < strlen(src); i += 2, j++) {
    11,260,056,980  => /usr/src/debug/glibc-2.25-123-gedcf13e25c/string/../sysdeps/x86_64/strlen.S:strlen (200021x)
          825  => /usr/src/debug/glibc-2.25-123-gedcf13e25c/elf/../sysdeps/x86_64/dl-trampoline.h:_dl_runtime_resolve_xsave (1x)
    2,000,200          dest[j] = src[i];
            .      }
            .  
           10      dest[j] = '\0';
            .  
            2      return dest;
            8  }

This gives a very strong hint for fixing the program: cut down on the cost of calling `strlen` and `strcat`.

Fixing `copyEvenCharacters` is trivial. Because the length of `src` doesn’t change, we can call `strlen` once and save the value in a variable:

    char *
    copyEvenCharacters(char *dest, const char *src)
    {
        int i;
        int j;
        size_t len;
    
        /* GOOD: Calls strlen only once */
        len = strlen(src);
        for(i = 0, j = 0; i < len; i += 2, j++) {
            dest[j] = src[i];
        }
    
        dest[j] = '\0';
    
        return dest;
    }

Fixing `replicate` is trickier. The trouble with using `strcat` is that every time we call `strcat(dest, src)`, `strcat` has to scan down the entire `dest` string to find the end, which (a) gets more expensive as `dest` gets longer, and (b) involves passing over the same non-null initial characters over and over again each time we want to add a few more characters. The effect of this is that we turn what should be an _O_(_n_)\-time process of generating a string of _n_ characters into something that looks more like _O_(_n_2). We can fix this by using pointer arithmetic to keep track of the end of `dest` ourselves, which also allows us to replace `strcat` with `memcpy`, which is likely to be faster since it doesn’t have to check for nulls. Here’s the improved version:

    char *
    replicate(char *dest, const char *src, int n)
    {
        size_t len = strlen(src);
        char *tail = dest;
    
        /* GOOD: each call to memcpy only copies n*strlen(src) bytes */
        for(int i = 0; i < n; i++, tail += len) {
            memcpy(tail, src, len);
        }
    
        /* tack on final null */
        *tail = '\0';
    
        return dest;
    }

The result of applying both of these fixes can be found in [fast.c](examples/profiling/fast.c). This runs much faster than `slow`:

    abcdabcdabcdabcdabcdabcdabcdabcdabcdabcd
    acacacacacacacacacac
    abcdabcdabcdabcdabcdabcdabcdabcdabcdabcd[399960 more]
    acacacacacacacacacacacacacacacacacacacac[199960 more]
    
    real    0m0.003s
    user    0m0.001s
    sys     0m0.001s

### 3.5.3 Profiling with `gprof`

If you can’t use `valgrind` for profiling, don’t like the output you get from it, or are annoyed by the huge slowdown when profiling your program, you may be able to get similar results from an older program `gprof`, which is closely tied to the `gcc` compiler. Unlike `valgrind`, which simulates an x86 CPU one machine-code instruction at a time, `gprof` works by having `gcc` add extra code to your program to track function calls and do sampling at runtime to see where your program is spending its time. The cost of this approach is that you get a bit less accuracy. I have also found `gprof` to be tricky to get working right on some operating systems.

Here’s a short but slow program for calculating the number of primes less than some limit passed as `argv[1]`:

    #include <stdio.h>
    #include <stdlib.h>
    
    /* return 1 if n is prime, 0 otherwise */
    int
    isPrime(int n)
    {
        int factor;
    
        if(n < 2) return 0;
        /* else */
        for(factor = 2; factor < n; factor++) {
            if(n % factor == 0) return 0;
        }
        /* else */
        return 1;
    }
    
    /* return number of primes < n */
    int
    countPrimes(int n)
    {
        int i;
        int count;
    
        count = 0;
    
        for(i = 0; i < n; i++) {
            if(isPrime(i)) count++;
        }
    
        return count;
    }
    
    int
    main(int argc, char **argv)
    {
        if(argc != 2) {
            fprintf(stderr, "Usage: %s n\n", argv[0]);
            return 1;
        }
    
        printf("%d\n", countPrimes(atoi(argv[1])));
    
        return 0;
    }

[examples/profiling/countPrimes.c](examples/profiling/countPrimes.c)

And now we’ll time `countPrimes 100000`:

    $ gcc -g3 -o countPrimes countPrimes.c 
    $ time ./countPrimes 100000
    9592
    
    real    0m4.711s
    user    0m4.608s
    sys 0m0.004s

This shows that the program took just under five seconds of real time, of which most was spent in user mode and a very small fraction was spent in kernel (sys) mode. The user-mode part corresponds to the code we wrote and any library routines we call that don’t require special privileges from the operation system. The kernel-mode part will mostly be I/O (not much in this case). Real time is generally less useful than CPU time, because it depends on how loaded the CPU is. Also, none of these times are especially precise, because the program only gets charged for time on a context switch (when it switches between user and kernel mode or some other program takes over the CPU for a bit) or when the kernel decides to see what it is up to (typically every 10 milliseconds).

The overall cost is not too bad, but the reason I picked 100000 and not some bigger number was that it didn’t finish fast enough for larger inputs. We’d like to see why it is taking so long, to have some idea what to try to speed up. So we’ll compile it with the `-pg` option to `gcc`, which inserts **profiling** code that counts how many times each function is called and how long (on average) each call takes.

Because the profile is not very smart about shared libraries, we also including the `--static` option to force the resulting program to be statically linked. This means that all the code that is used by the program is baked into the executable instead of being linked in at run-time. (Normally we don’t do this because it makes for big executables and big running programs, since statically-linked libraries can’t be shared between more than one running program.)

    $ gcc -pg --static -g3 -o countPrimes countPrimes.c 
    $ time ./countPrimes 100000
    9592
    
    real    0m4.723s
    user    0m4.668s
    sys 0m0.000s

Hooray! We’ve made the program slightly slower. But we also just produced a file `gmon.out` that we can read with `gprof`. Note that we have to pass the name of the program so that `gprof` can figure out which executable generated `gmon.out`.

    $ gprof countPrimes
    Flat profile:
    
    Each sample counts as 0.01 seconds.
      %   cumulative   self              self     total           
     time   seconds   seconds    calls   s/call   s/call  name    
    100.00      4.66     4.66   100000     0.00     0.00  isPrime
      0.00      4.66     0.00        1     0.00     4.66  countPrimes
      0.00      4.66     0.00        1     0.00     4.66  main
    
    [...much explanatory text deleted]

It looks like we are spending all of our time in `isPrime`, at least if we read the columns on the left. The per-call columns are not too helpful because of granularity: `isPrime` is too fast for the profiler to wake up and detect how long it runs for. The total columns are less suspicious because they are obtained by sampling: from time to time, the profiler looks and sees what function it’s in, and charges each function a fraction of the total CPU time proportional to how often it gets sampled. So we probable aren’t really spending zero time in `countPrimes` and `main`, but the amount of time we do spend is small enough not to be detected.

This is handy because it means we don’t need to bother trying to speed up the rest of the program. We have two things we can try:

1.  Call `isPrime` less.
2.  Make `isPrime` faster.

Let’s start by seeing if we can make `isPrime` faster.

What `isPrime` is doing is testing if a number `n` is prime by the most direct way possible: dividing by all numbers less than `n` until it finds a factor. That’s a lot of divisions: if `n` is indeed prime, it’s linear in `n`. Since division is a relatively expensive operation, the first thing to try is to get rid of some.

Here’s a revised version of `isPrime`:

    /* return 1 if n is prime, 0 otherwise */
    int
    isPrime(int n)
    {
        int factor;
    
        if(n < 2) { return 0; }
        if(n % 2 == 0) {
            /* special case for the only even prime */
            return n == 2;
        }
        /* else */
        for(factor = 3; factor < n; factor+=2) {
            if(n % factor == 0) return 0;
        }
        /* else */
        return 1;
    }

[examples/profiling/countPrimesSkipEvenFactors.c](examples/profiling/countPrimesSkipEvenFactors.c)

The trick is to check first if `n` is divisible by `2`, and only test odd potential factors thereafter. This requires some extra work to handle 2, but maybe the extra code complexity will be worth it.

Let’s see how the timing goes:

    $ gcc -pg --static -g3 -o countPrimes ./countPrimesSkipEvenFactors.c 
    $ time ./countPrimes 100000
    9592
    
    real    0m2.608s
    user    0m2.400s
    sys 0m0.004s
    $ gprof countPrimes
    Flat profile:
    
    Each sample counts as 0.01 seconds.
      %   cumulative   self              self     total           
     time   seconds   seconds    calls   s/call   s/call  name    
    100.00      2.29     2.29   100000     0.00     0.00  isPrime
      0.00      2.29     0.00        1     0.00     2.29  countPrimes
      0.00      2.29     0.00        1     0.00     2.29  main
    
    [...]

Twice as fast! And the answer is still the same, too—this is important.

Can we test even fewer factors? Suppose `n` has a non-trivial factor `x`. Then `n` equals `x*y` for some `y` which is also nontrivial. One of `x` or `y` will be no bigger than the square root of `n`. So perhaps we can stop when we reach the square root of `n`,

Let’s try it:

    #include <math.h>
    
    /* return 1 if n is prime, 0 otherwise */
    int
    isPrime(int n)
    {
        int factor;
    
        if(n < 2) { return 0; }
        if(n % 2 == 0) {
            /* special case for the only even prime */
            return n == 2;
        }
        /* else */
        for(factor = 3; factor < sqrt(n)+1; factor+=2) {
            if(n % factor == 0) return 0;
        }
        /* else */
        return 1;
    }
    }

[examples/profiling/countPrimesSqrt.c](examples/profiling/countPrimesSqrt.c)

I added `+1` to the return value of `sqrt` both to allow for `factor` to be equal to the square root of `n`, and because the output of `sqrt` is not exact, and it would be embarrassing if I announced that 25 was prime because I stopped at 4.9999999997.

Using the math library not only requires including `<math.h>` but also requires compiling with the `-lm` flag after all `.c` or `.o` files, to link in the library routines:

    $ gcc -pg --static -g3 -o countPrimes ./countPrimesSqrt.c -lm
    $ time ./countPrimes 1000000
    78498
    
    real    0m1.008s
    user    0m0.976s
    sys 0m0.000s
    $ gprof countPrimes
    Flat profile:
    
    Each sample counts as 0.01 seconds.
      %   cumulative   self              self     total           
     time   seconds   seconds    calls  ms/call  ms/call  name    
     50.00      0.02     0.02   100000     0.00     0.00  isPrime
     50.00      0.04     0.02                             __sqrt_finite
      0.00      0.04     0.00        1     0.00    20.00  countPrimes
      0.00      0.04     0.00        1     0.00    20.00  main
    
    [...]

Whoosh!

Can we optimize further? Let’s see what happens on a bigger input:

    $ time ./countPrimes 1000000
    78498
    
    real    0m0.987s
    user    0m0.960s
    sys 0m0.000s
    $ gprof countPrimes
    Flat profile:
    
    Each sample counts as 0.01 seconds.
      %   cumulative   self              self     total           
     time   seconds   seconds    calls  ms/call  ms/call  name    
     51.04      0.49     0.49                             __sqrt_finite
     44.79      0.92     0.43  1000000     0.00     0.00  isPrime
      3.65      0.96     0.04                             sqrt
      0.52      0.96     0.01        1     5.00   435.00  main
      0.00      0.96     0.00        1     0.00   430.00  countPrimes
    
    [...]

This is still very good, although we’re spending a lot of time in `sqrt` (more specifically, its internal helper routine `__sqrt_finite`). Can we do better?

Maybe moving the `sqrt` out of the loop in `isPrime` will make a difference:

    /* return 1 if n is prime, 0 otherwise */
    int
    isPrime(int n)
    {
        int factor;
        int sqrtValue;
    
        if(n < 2) { return 0; }
        if(n % 2 == 0) {
            /* special case for the only even prime */
            return n == 2;
        }
        /* else */
        sqrtValue = sqrt(n) + 1;
        for(factor = 3; factor < sqrtValue; factor+=2) {
            if(n % factor == 0) return 0;
        }
        /* else */
        return 1;
    }

[examples/profiling/countPrimesSqrtOutsideLoop.c](examples/profiling/countPrimesSqrtOutsideLoop.c)

    $ gcc -pg --static -g3 -o countPrimes ./countPrimesSqrtOutsideLoop.c -lm
    $ time ./countPrimes 1000000
    78498
    
    real    0m0.413s
    user    0m0.392s
    sys 0m0.000s
    $ gprof countPrimes
    Flat profile:
    
    Each sample counts as 0.01 seconds.
      %   cumulative   self              self     total           
     time   seconds   seconds    calls  ms/call  ms/call  name    
     97.44      0.38     0.38  1000000     0.00     0.00  isPrime
      2.56      0.39     0.01        1    10.00   390.00  countPrimes
      0.00      0.39     0.00        1     0.00   390.00  main
    
    [...]

This worked! We are now spending so little time in `sqrt` that the profiler doesn’t notice it.

What if we get rid of the call to `sqrt` and test if `factor * factor <= n` instead? This way we could dump the math library:

    /* return 1 if n is prime, 0 otherwise */
    int
    isPrime(int n)
    {
        int factor;
    
        if(n < 2) { return 0; }
        if(n % 2 == 0) {
            /* special case for the only even prime */
            return n == 2;
        }
        /* else */
        for(factor = 3; factor*factor <= n; factor+=2) {
            if(n % factor == 0) return 0;
        }
        /* else */
        return 1;
    }

[examples/profiling/countPrimesSquaring.c](examples/profiling/countPrimesSquaring.c)

    $ gcc -pg --static -g3 -o countPrimes ./countPrimesSquaring.c
    $ time ./countPrimes 1000000
    78498
    
    real    0m0.450s
    user    0m0.428s
    sys 0m0.000s

This is slower, but not much slower. We might need to decide how much we care about avoiding floating-point computation in our program.

At this point we could decide that `countPrimes` is fast enough, or maybe we could look for further improvements, say, by testing out many small primes at the beginning instead of just `2`, calling `isPrime` only on odd values of `i`, or reading a computational number theory textbook to find out how the cool kids do this.

Note that in some cases going all-out to improve performance may be more trouble than it’s worth. A reasonable strategy for code for your own use might be to start running one version and make improvements on a separate copy while it’s running. If the first version finishes before you are done writing new code, it’s probably fast enough.

#### 3.5.3.1 Effect of optimization during compilation

We didn’t use any optimization flags for this example, because the optimizer can do a lot of rewriting that can make the output of the profiler confusing. For example, at high optimization levels, the compiler will often avoid function-call overhead by inserting the body of a helper function directly into its caller. But this can make a big difference in performance, so in real life you will want to compile with optimization turned on. Here’s how the performance of `countPrimes 100000` is affected by optimization level:

Version

No optimization

With -O1

With -O2

With -O3

`countPrimes.c`

4.600

4.060

3.928

3.944

`countPrimesSkipEvenFactors.c`

2.260

1.948

1.964

1.984

`countPrimesSqrt.c`

0.036

0.028

0.028

0.028

`countPrimesSqrtOutsideLoop.c`

0.012

0.012

0.008

0.008

`countPrimesSquaring.c`

0.012

0.012

0.008

0.012

In each case, the reported time is the sum of user and system time in seconds.[3](#fn3)

For the smarter routines, more optimization doesn’t necessarily help, although some of this may be experimental error since I was too lazy to get a lot of samples by running each program more than once, and the times for the faster programs are so small that granularity is going to be an issue.

Here’s the same table using `countPrimes 10000000` on the three fastest programs:

Version

No optimization

With -O1

With -O2

With -O3

`countPrimesSqrt.c`

24.236

18.840

18.720

18.564

`countPrimesSqrtOutsideLoop.c`

9.388

9.364

9.368

9.360

`countPrimesSquaring.c`

9.748

9.248

9.236

9.160

Again there are the usual caveats that I am a lazy person and should probably be doing more to deal with sampling and granularity issues, but if you believe these numbers, we actually win by going to `countPrimesSquaring` once the optimizer is turned on. I suspect that it is benefiting from [strength reduction](http://en.wikipedia.org/wiki/Strength_reduction), which would generate the product `factor*factor` in `isPrime` incrementally using addition rather than multiplying from scratch each time.

It’s also worth noting that the optimizer works better if we leave a lot of easy optimization lying around. For `countPrimesSqrt.c`, my guess is that most of the initial gains are from avoiding function call overhead on `sqrt` by compiling it in-line. But even the optimizer is not smart enough to recognize that we are computing the same value over and over again, so we still win by pulling `sqrt` out of the loop in `countPrimesSqrtOutsideLoop.c`.

If I wanted to see if my guesses about the optimizer were correct, I could use `gcc -S` and look at the assembler code. But see earlier comments about laziness.

3.6 Version control
-------------------

When you are programming, you will make mistakes. If you program long enough, these will eventually include true acts of boneheadedness like accidentally deleting all of your source files. You are also likely to spend some of your time trying out things that don’t work, at the end of which you’d like to go back to the last version of your program that did work. All these problems can be solved by using a **version control system**.

There are at least five respectable version control systems installed on the Zoo: `rcs`, `cvs`, `svn`, `hg`, and `git`. If you are familiar with any of them, you should use that. If you have to pick one from scratch, I recommend using `git`. A brief summary of `git` is given below. For more details, see the tutorials available at [http://git-scm.com](http://git-scm.com).

### 3.6.1 Setting up Git

Typically you run `git` inside a directory that holds some project you are working on (say, `hw1`). Before you can do anything with `git`, you will need to create the _repository_, which is a hidden directory `.git` that records changes to your files:

    $ mkdir git-demo
    $ cd git-demo
    $ git init
    Initialized empty Git repository in /home/classes/cs223/class/aspnes.james.ja54/git-demo/.git/

Now let’s create a file and add it to the repository:

    $ echo 'int main(int argc, char **argv) { return 0; }' > tiny.c
    $ git add tiny.c

The `git status` command will tell us that Git knows about `tiny.c`, but hasn’t commited the changes to the repository yet:

    $ git status
    # On branch master
    #
    # Initial commit
    #
    # Changes to be committed:
    #   (use "git rm --cached <file>..." to unstage)
    #
    #       new file:   tiny.c
    #

The `git commit` command will commit the actual changes, along with a message saying what you did. For short messages, the easiest way to do this is to include the message on the command line:

    $ git commit -a -m"add very short C program"
    [master (root-commit) 5393616] add very short C program
     Committer: James Aspnes <ja54@tick.zoo.cs.yale.edu>
    Your name and email address were configured automatically based
    on your username and hostname. Please check that they are accurate.
    You can suppress this message by setting them explicitly:
    
        git config --global user.name "Your Name"
        git config --global user.email you@example.com
    
    If the identity used for this commit is wrong, you can fix it with:
    
        git commit --amend --author='Your Name <you@example.com>'
    
     1 files changed, 1 insertions(+), 0 deletions(-)
     create mode 100644 tiny.c

The `-a` argument tells Git to include any changes I made to files it already knows about. The `-m` argument sets the commit message.

Because this is the first time I ever did a commit, and because I didn’t tell Git who I was before, it complains that its guess for my name and email address may be wrong. It also tells me what to do to get it to shut up about this next time:

    $ git config --global user.name "James Aspnes"
    $ git config --global user.email "aspnes@cs.yale.edu"
    $ git commit --amend --author="James Aspnes <aspnes@cs.yale.edu>" -m"add a very short C program"
    [master a44e1e1] add a very short C program
     1 files changed, 1 insertions(+), 0 deletions(-)
     create mode 100644 tiny.c

Note that I repeated the `-m` business to `git commit --amend`; if I hadn’t, it would have run the default editor (`vim`) to let me edit my commit message. If I don’t like `vim`, I can change the default using `git config --global core.editor`, e.g.:

    $ git config --global core.editor "emacs -nw"

I can see what commits I’ve done so far using `git log`:

    $ git log
    commit a44e1e195de4ce785cd95cae3b93c817d598a9ee
    Author: James Aspnes <aspnes@cs.yale.edu>
    Date:   Thu Dec 29 20:21:21 2011 -0500
    
        add a very short C program

### 3.6.2 Editing files

Suppose I edit `tiny.c` using my favorite editor to turn it into the classic hello-world program:

    #include <stdio.h>
    
    int 
    main(int argc, char **argv)
    {
        puts("hello, world");
        return 0;
    }

I can see what files have changed using `git status`:

    $ git status
    # On branch master
    # Changed but not updated:
    #   (use "git add <file>..." to update what will be committed)
    #   (use "git checkout -- <file>..." to discard changes in working directory)
    #
    #       modified:   tiny.c
    #
    no changes added to commit (use "git add" and/or "git commit -a")

Notice how Git reminds me to use `git commit -a` to include these changes in my next commit. I can also do `git add tiny.c` if I just want include the changes to `tiny.c` (maybe I made changes to a different file that I want to commit separately), but usually that’s too much work.

If I want to know the details of the changes since my last commit, I can do `git diff`:

    $ git diff
    diff --git a/tiny.c b/tiny.c
    index 0314ff1..f8d9dcd 100644
    --- a/tiny.c
    +++ b/tiny.c
    @@ -1 +1,8 @@
    -int main(int argc, char **argv) { return 0; }
    +#include <stdio.h>
    +
    +int 
    +main(int argc, char **argv)
    +{
    +    puts("hello, world");
    +    return 0;
    +}

Since I like these changes, I do a commit:

    $ git commit -a -m"expand previous program to hello world"
    [master 13a73be] expand previous program to hello world
     1 files changed, 8 insertions(+), 1 deletions(-)

Now there are two commits in my log:

    $ git log | tee /dev/null
    commit 13a73bedd3a48c173898d1afec05bd6fa0d7079a
    Author: James Aspnes <aspnes@cs.yale.edu>
    Date:   Thu Dec 29 20:34:06 2011 -0500
    
        expand previous program to hello world
    
    commit a44e1e195de4ce785cd95cae3b93c817d598a9ee
    Author: James Aspnes <aspnes@cs.yale.edu>
    Date:   Thu Dec 29 20:21:21 2011 -0500
    
        add a very short C program

### 3.6.3 Renaming files

You can rename a file with `git mv`. This is just like regular `mv`, except that it tells Git what you are doing.

    $ git mv tiny.c hello.c
    $ git status
    # On branch master
    # Changes to be committed:
    #   (use "git reset HEAD <file>..." to unstage)
    #
    #       renamed:    tiny.c -> hello.c
    #

These changes don’t get written to the repository unless you do another `git commit`:

    $ git commit -a -m"give better name to hello program"
    [master 6d2116c] give better name to hello program
     1 files changed, 0 insertions(+), 0 deletions(-)
     rename tiny.c => hello.c (100%)

### 3.6.4 Adding and removing files

To add a file, create it and then call `git add`:

    $ cp hello.c goodbye.c
    $ git status
    # On branch master
    # Untracked files:
    #   (use "git add <file>..." to include in what will be committed)
    #
    #       goodbye.c
    nothing added to commit but untracked files present (use "git add" to track)
    $ git add goodbye.c
    $ git commit -a -m"we need a second program to say goodbye"
    [master 454b24c] we need a second program to say goodbye
     1 files changed, 8 insertions(+), 0 deletions(-)
     create mode 100644 goodbye.c

To remove a file, use `git rm`:

    $ git rm goodbye.c 
    $ git status
    # On branch master
    # Changed but not updated:
    #   (use "git add/rm <file>..." to update what will be committed)
    #   (use "git checkout -- <file>..." to discard changes in working directory)
    #
    #       deleted:    goodbye.c
    #
    no changes added to commit (use "git add" and/or "git commit -a")
    $ git commit -a -m"no, goodbye.c was a bad idea"
    [master defa0e0] no, goodbye.c was a bad idea
     1 files changed, 0 insertions(+), 8 deletions(-)
     delete mode 100644 goodbye.c

### 3.6.5 Recovering files from the repository

If you make a mistake, you can back out using the repository. Here I will delete my `hello.c` file and then get it back using `git checkout -- hello.c`:

    $ rm hello.c
    $ ls
    $ git checkout -- hello.c
    $ ls
    hello.c

I can also get back old versions of files by putting the commit id before the `--`:

    $ git checkout a44e1 -- tiny.c
    $ ls
    hello.c  tiny.c

The commit id can be any unique prefix of the ridiculously long hex name shown by `git log`.

Having recovered `tiny.c`, I will keep it around by adding it to a new commit:

    $ git commit -a -m"keep tiny.c around"
    [master 23d6219] keep tiny.c around
     1 files changed, 1 insertions(+), 0 deletions(-)
     create mode 100644 tiny.c

### 3.6.6 Undoing bad commits

Suppose I commit a change that I didn’t want to make. For example, let’s suppose I decide to add some punctuation to the greeting in `hello.c` but botch my edit:

    $ vim hello.c
    $ git commit -a -m"add exclamation point"
    [master f40d8d3] add exclamation point
     1 files changed, 1 insertions(+), 1 deletions(-)

Only now does it occur to me to test my program:

    $ gcc -o hello hello.c
    $ ./hello
    hello, wolrd!

Disaster!

I can use `git diff` to see what went wrong. The command below compares the current working directory to `HEAD^`, the commit before the most recent commit:[4](#fn4)

    $ git diff HEAD^ | tee /dev/null
    diff --git a/hello.c b/hello.c
    index f8d9dcd..dc227a8 100644
    --- a/hello.c
    +++ b/hello.c
    @@ -3,6 +3,6 @@
     int 
     main(int argc, char **argv)
     {
    -    puts("hello, world");
    +    puts("hello, wolrd!");
         return 0;
     }

And I see my mistake leaping out at me on the new line I added (which `git diff` puts a `+` in front of). But now what do I do? I already commited the change, which means that I can’t get it out of the history.[5](#fn5)

Instead, I use `git revert` on `HEAD`, the most recent commit:

    $ git revert HEAD
    [master fca3166] Revert "add exclamation point"
     1 files changed, 1 insertions(+), 1 deletions(-)

(Not shown here is where it popped up a `vim` session to let me edit the commit message; I just hit `:x`<ENTER> to get out of it without changing the default.)

Now everything is back to the way it was before the bad commit:

    $ ./hello
    hello, world

### 3.6.7 Looking at old versions

Running `git log` will now show me the entire history of my project, newest commits first:

    fca3166a697c6d72fb9e8aec913bb8e36fb5fe4e Revert "add exclamation point"
    f40d8d386890103abacd0bf4142ecad62eed5aeb add exclamation point
    23d6219c9380ba03d9be0672f0a7b25d18417731 keep tiny.c around
    defa0e0430293ca910f077d5dd19fccc47ab0521 no, goodbye.c was a bad idea
    454b24c307121b5a597375a99a37a825b0dc7e81 we need a second program to say goodbye
    6d2116c4c72a6ff92b8b276eb88ddb556d1b8fdd give better name to hello program
    13a73bedd3a48c173898d1afec05bd6fa0d7079a expand previous program to hello world
    a44e1e195de4ce785cd95cae3b93c817d598a9ee add a very short C program

If I want to look at an old version (say, after I created `goodbye.c`), I can go back to it using `git checkout`:

    $ git checkout 454b2
    Note: checking out '454b2'.
    
    You are in 'detached HEAD' state. You can look around, make experimental
    changes and commit them, and you can discard any commits you make in this
    state without impacting any branches by performing another checkout.
    
    If you want to create a new branch to retain commits you create, you may
    do so (now or later) by using -b with the checkout command again. Example:
    
      git checkout -b new_branch_name
    
    HEAD is now at 454b24c... we need a second program to say goodbye
    $ ls
    goodbye.c  hello  hello.c

Now I have both `goodbye.c` and `hello.c`, as well as my compiled program `hello`, since I didn’t tell Git about it. Note that I also got lots of horrendous warnings about the fact that I am living in the past and shouldn’t expect to make any permanent changes here.

To go back to the last commit, use `git checkout master`:

    $ git checkout master
    Previous HEAD position was 454b24c... we need a second program to say goodbye
    Switched to branch 'master'
    $ ls
    hello  hello.c  tiny.c

### 3.6.8 More information about Git

All Git commands take a `--help` argument that brings up their manual page. There is also extensive documentation at [http://git-scm.com](http://git-scm.com/).

3.7 Submitting assignments
--------------------------

The submit command is is found in `/c/cs223/bin` on the Zoo. Here is the documentation (adapted from comments in the script):

    submit    assignment-number file(s)
    unsubmit  assignment-number file(s)
    check     assignment-number
    makeit    assignment-number [file]
    protect   assignment-number file(s)
    unprotect assignment-number file(s)
    retrieve  assignment-number file(s)
    testit    assignment-number test
    diffit    assignment-number file(s)
    revert    assignment-number -r[version number] file(s)
    results   assignment-number
    
    The submit program can be invoked in eleven different ways:
    
        /c/cs223/bin/submit 1 Makefile tokenize.c unique.c time.log
    
    submits the named source files as your solution to Homework #1;
    
        /c/cs223/bin/check 2
    
    lists the files that you have submitted for Homework #2;
    
        /c/cs223/bin/unsubmit 3 error.submit bogus.solution
    
    deletes the named files that you had submitted previously for Homework #3
    (i.e., withdraws them from submission, which is useful if you accidentally
    submit the wrong file);
    
        /c/cs223/bin/makeit 4 tokenize unique
    
    runs "make" on the files that you submitted previously for Homework #4;
    
        /c/cs223/bin/protect 5 tokenize.c time.log
    
    protects the named files that you submitted previously for Homework #5 (so
    they cannot be deleted accidentally);
    
        /c/cs223/bin/unprotect 6 unique.c time.log
    
    unprotects the named files that you submitted previously for Homework #6
    (so they can be deleted);
    
         /c/cs223/bin/retrieve 7 Csquash.c
    
    retrieves copies of the named files that you submitted previously for Homework #7;
    
         /c/cs223/bin/testit 8 BigTest
    
    runs the test script /c/cs223/Hwk8/test.BigTest on the submission directory;
    
        /c/cs223/bin/diffit 9 erroneous.c
    
    compares the submitted version of a file with the version in the local directory;
    
        /c/cs223/bin/revert 10 -r1.1 overWritten.c
    
    reverts a submitted file to a previous version 1.1; and
    
        /c/cs223/bin/results 11
    
    shows the grading results for Homework #11, once it has been graded.

The `retrieve` command supports a `-d` argument that can be used to retrieve the version of a file as of a particular time, as in

        /c/cs223/bin/retrieve 7 -d"2020/03/01 17:57" Csquash.c

This will also display the version used by the internal RCS version control script for use with `revert`. Note that `retrieve` makes a copy of the file in the current working directory, while `revert` updates the copy in the submission directory (including restoring its modification time). This can be used to avoid late penalties if you forget to use `protect` and accidentally overwrite a file in your submission directory after the assignment deadline.

The `submit` program will only work if there is a directory with your name and login on it under `/c/cs223/class`.

4 The C programming language
============================

The C programming language was developed at Bell Laboratories in the early 1970s as the system programming language for Unix, based on the earlier and even more primitive languages BCPL and B. When originally developed, it was targeted at machines that were extremely limited by modern standards: the first Unix implementation (and the B compiler that supported it) ran on a DEC PDP-7 with only 8192 18-bit words of memory (Dennis M. Ritchie, The development of the C language, in Thomas J. Bergin, Jr., and Richard G. Gibson, Jr., History of Programming Languages-II ed., ACM Press, 1996). So using as few resources as possible, both in the compiler and in the resulting code, was a priority.

This priority is reflected in the features (and lack of features) of C, and is partly responsible for its success. Programs written in C place almost no demands on the system they run on and give the programmer nearly complete control over their execution: this allows programs that were previously written in assembly language, like operating system kernels and device drivers, to be implemented in C. So C is often the first language ported to any new architecture, and many higher-level languages are either executed using interpreters written in C or use C as in intermediate language in the compilation process.

Since its initial development, C has gone through four major versions:

*   The original **K&R C** defined in the 1978 first edition of Kernighan and Ritchie’s book _The C Programming Language_;
*   **ANSI C**, from 1988, which fixed some oddities in the syntax and which is documented in the 1988 second edition of _The C Programming Language_;
*   **C99**, from 1999, the ISO/IEC 9899:1999 standard for C, which added some features from C++ and many new features for high-performance numerical computing;
*   **C11**, from 2011, the ISO/IEC 9899:2011 standard for C, which relaxed some of the requirements of C99 that most compilers hadn’t bothered implementing and which added a few extra features.

Unfortunately, C99 and C11 both exemplify the uselessness of standards committees in general and the [ISO](http://www.iso.org) in particular. Because the ISO has no power to enforce standards on compiler writers, and because they will charge you CHF 198 just to look at the C11 standard, many compiler writers have ignored much of C99 and C11. In particular, Microsoft pretty much gave up on adding any features after ANSI C, and support for C99 and C11 is spotty in `gcc` and `clang`, the two dominant open source C compilers. So if you want to write portable C code, it is safest to limit yourself to features in ANSI C.

For this class, we will permit you to use any feature of C that `gcc` supports, which includes all features of ANSI C and most features of later standards.

4.1 Structure of a C program
----------------------------

A C program consists of one or more files (which act a little bit like modules in more structured programming languages, each of which typically contains **definitions** of **functions**, each of which consists of **statements**, which are either **compound statements** like `if`, `while`, etc. or **expressions** that typically perform some sort of arithmetic or call other functions. Files may also include **declarations** of global variables (not recommended), and functions will often contain declarations of local variables that can only be used inside that function.

Here is a typical small C program that sums a range of integers. Since this is our first real program, it’s a little heavy on the comments (shown between `/*` and `*/`).

    #include <stdio.h>    /* This is needed to get the declarations of fprintf and printf */
    #include <stdlib.h>   /* This is needed to get the declaration of atoi */
    
    /* Return the sum of all integers i
     * such that start <= i and i < end. */
    int
    sumRange(int start, int end)
    {
        int i;    /* loop variable */
        int sum;  /* sum of all values so far */
    
        /* a mathematician would use a formula for this,
         * but we are computer programmers! */
        sum = 0;
    
        /* The three parts of the header for this loop mean:
         * 1. Set i to start initially.
         * 2. Keep doing the loop as long as i is less than end.
         * 3. After each iteration, add 1 to i.
         */
        for(i = start; i < end; i++) {
            sum += i;  /* This adds i to sum */
        }
    
        /* This exits the function immediately,
         * sending the value of sum back to the caller. */
        return sum;
    }
    
    int
    main(int argc, char **argv)
    {
        int start;    /* initial value in range */
        int end;      /* one past the last value in the range */
    
        /* This tests for the wrong number of arguments.
         * The != operator returns true (1) if its arguments are not equal,
         * and false (0) otherwise.
         * Note that the program name itself counts as an argument
         * (which is why we want the argument count to be 3)
         * and appears in position 0 in the argument vector
         * (which means we can get it using argv[0]). */
        if(argc != 3) {
            fprintf(stderr, "Usage: %s\n start end", argv[0]);
            return 1;
        }
    
        /* Convert start and end positions from strings to ints */
        start = atoi(argv[1]);
        end = atoi(argv[2]);
    
        /* Call sumRange and print the result */
        printf("sumRange(%d, %d) = %d\n", start, end, sumRange(start, end));
    
        return 0;
    }

[examples/sumRange.c](examples/sumRange.c)

This is what the program does if we compile and run it:

    $ gcc -g -Wall -o sumRange sumRange.c
    $ ./sumRange 1 100
    sumRange(1, 100) = 4950

The `sumRange.c` program contains two functions, `sumRange` and `main`. The `sumRange` function does the actual work, while `main` is the main routine of the program that gets called with the command-line arguments when the program is run. Every C program must have a routine named `main` with these particular arguments.

In addition, `main` may call three library functions, `fprintf` (which in this case is used to generate error messages), `printf` (which generates ordinary output), and `atoi` (which is used to translate the command-line arguments into numerical values). These functions must all be declared before they can be used. In the case of `sumRange`, putting the definition of `sumRange` before the definition of `main` is enough. For the library routines, the **include files** `stdio.h` and `stdlib.h` contain declarations of the functions that contain enough information about there return types and arguments that the compiler knows how to generate machine code to call them. These files are included in `sumRange.c` by the **C preprocessor**, which pastes in the contents of any file specified by the `#include` command, strips out any comments (delimited by `/*` and `*/`, or by `//` and the end of the line if you are using C99), and does some other tricks that allow you to muck with the source code before the actual compiler sees it (see [Macros](#macros)). You can see what the output of the preprocessor looks like by calling the C compiler with the `-E` option, as in `gcc -E sumRange.c`.

The **body** of each function consists of some **variable declarations** followed by a sequence of **statements** that tell the computer what to do. Unlike some languages, every variable used in a C program must be declared. A declaration specifies the **type** of a variable, which tells the compiler how much space to allocate for it and how to interpret some operations on its value. Statements may be **compound statements** like the `if` statement in `main` that executes its body only if the program is called with the wrong number of command-line arguments or the `for` loop in `sumRange` that executes its body as long as the test in its header remains true; or they may be **simple statements** that consist of a single **expression** followed by a semicolon.

An **expression** is usually either a bare function call whose value is discarded (for example, the calls to `fprintf` and `printf` in `main`), or an arithmetic expression (which may include function calls, like the calls to `atoi` or in `main`) whose value is assigned to some variable using the **assignment operator** `=` or sometimes variants like `+=` (which is shorthand for adding a value to an existing variable: `x += y` is equivalent to `x = x+y`).

When you compile a C program, after running the preprocessor, the compiler generates **assembly language** code that is a human-readable description of the ultimate machine code for your target CPU. Assembly language strips out all the human-friendly features of your program and reduces it to simple instructions usually involving moving things from one place to the other or performing a single arithmetic operation. For example, the C line

        x = y + 1;  /* add 1 to y, store result in x */

gets translated into x86 assembly as

            movl    -24(%rbp), %edi
            addl    $1, %edi
            movl    %edi, -28(%rbp)

These three operations copy the value of `y` into the CPU register `%edi`, add 1 to the `%edi` register, and then copy the value back into `x`. This corresponds directly to what you would have to do to evaluate `x = y + 1` if you could only do one very basic operation at a time and couldn’t do arithmetic operations on memory locations: fetch `y`, add 1, store `x`. Note that the CPU doesn’t know about the names `y` and `x`; instead, it computes their addresses by adding -24 and -28 respectively to the base pointer register `%rbp`. This is why it can be hard to debug compiled code unless you tell the compiler to keep around extra information.

For an arbitrary C program, if you are using `gcc`, you can see what your code looks like in assembly language using the `-S` option. For example, `gcc -S sumRange.c` will create a file `sumRange.s` that looks like this:

    	.file	"sumRange.c"
    	.text
    	.globl	sumRange
    	.type	sumRange, @function
    sumRange:
    .LFB0:
    	.cfi_startproc
    	pushl	%ebp
    	.cfi_def_cfa_offset 8
    	.cfi_offset 5, -8
    	movl	%esp, %ebp
    	.cfi_def_cfa_register 5
    	subl	$16, %esp
    	movl	$0, -4(%ebp)
    	movl	8(%ebp), %eax
    	movl	%eax, -8(%ebp)
    	jmp	.L2
    .L3:
    	movl	-8(%ebp), %eax
    	addl	%eax, -4(%ebp)
    	addl	$1, -8(%ebp)
    .L2:
    	movl	-8(%ebp), %eax
    	cmpl	12(%ebp), %eax
    	jl	.L3
    	movl	-4(%ebp), %eax
    	leave
    	.cfi_restore 5
    	.cfi_def_cfa 4, 4
    	ret
    	.cfi_endproc
    .LFE0:
    	.size	sumRange, .-sumRange
    	.section	.rodata
    .LC0:
    	.string	"Usage: %s\n start end"
    .LC1:
    	.string	"sumRange(%d, %d) = %d\n"
    	.text
    	.globl	main
    	.type	main, @function
    main:
    .LFB1:
    	.cfi_startproc
    	pushl	%ebp
    	.cfi_def_cfa_offset 8
    	.cfi_offset 5, -8
    	movl	%esp, %ebp
    	.cfi_def_cfa_register 5
    	andl	$-16, %esp
    	subl	$32, %esp
    	cmpl	$3, 8(%ebp)
    	je	.L6
    	movl	12(%ebp), %eax
    	movl	(%eax), %edx
    	movl	stderr, %eax
    	movl	%edx, 8(%esp)
    	movl	$.LC0, 4(%esp)
    	movl	%eax, (%esp)
    	call	fprintf
    	movl	$1, %eax
    	jmp	.L7
    .L6:
    	movl	12(%ebp), %eax
    	addl	$4, %eax
    	movl	(%eax), %eax
    	movl	%eax, (%esp)
    	call	atoi
    	movl	%eax, 24(%esp)
    	movl	12(%ebp), %eax
    	addl	$8, %eax
    	movl	(%eax), %eax
    	movl	%eax, (%esp)
    	call	atoi
    	movl	%eax, 28(%esp)
    	movl	28(%esp), %eax
    	movl	%eax, 4(%esp)
    	movl	24(%esp), %eax
    	movl	%eax, (%esp)
    	call	sumRange
    	movl	%eax, 12(%esp)
    	movl	28(%esp), %eax
    	movl	%eax, 8(%esp)
    	movl	24(%esp), %eax
    	movl	%eax, 4(%esp)
    	movl	$.LC1, (%esp)
    	call	printf
    	movl	$0, %eax
    .L7:
    	leave
    	.cfi_restore 5
    	.cfi_def_cfa 4, 4
    	ret
    	.cfi_endproc
    .LFE1:
    	.size	main, .-main
    	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
    	.section	.note.GNU-stack,"",@progbits

[examples/sumRange.s](examples/sumRange.s)

You usually don’t need to look at assembly language, but it can sometimes be enlightening to see what the compiler is doing with your code. One thing that I find interesting about this particular code (which is for the x86 architecture) is that most of the instructions are `movl`, the x86 instruction for copying a 32-bit quantity from one location to another. So most of what this program is doing is copying data into the places expected by the library functions it is calling. Also noteworthy is that the beautiful compound statements like `if` and `for` that so eloquently express the intent of the programmer get turned into a pile of jump (`jmp`) and conditional jump (`jl`, `je`) instructions, the machine code versions of the often dangerous and confusing `goto` statement. This is because CPUs are dumb: they don’t know how to carry out an `if` branch or a loop, and all they can do instead is be told to replace the value of their program counter register with some new value instead of just incrementing it as they usually do.

Assembly language is not the last stage in this process. The **assembler** (`as`) is a program that translates the assembly language in `sumRange.s` into machine code (which will be stored in `sumRange.o` if we aren’t compiling a single program all at once). Machine code is not human-readable, and is close to the raw stream of bytes that gets stored in the computer’s memory to represent a running program. The missing parts are that the addresses of each function and global variables are generally left unspecified, so that they can be moved around to make room for other functions and variables coming from other files and from system libraries. The job of stitching all of these pieces together, putting everything in the right place, filling in any placeholder addresses, and generating the **executable file** `sumRange` that we can actually run is given to the **linker** `ld`.

The whole process looks like this:

    sumRange.c (source code)
       |
       v
    [preprocessor (cpp)]
       |
       v
    preprocessed version of sumRange.c
       |
       v
    [compiler (gcc)]
       |
       v
    sumRange.s (assembly code)
       |
       v
    [assembler (as)]
       |
       v
    sumRange.o (machine code)
       |
       v
    [linker (ld)] <- system library (glibc.a)
       |
       v
    sumRange (executable)

The good news is, you don’t actually have to run all of these steps yourself; instead, `gcc` will take care of everything for you, particularly for simple programs like `sumRange.c` that fit in a single file.

4.2 Numeric data types
----------------------

All data stored inside a computer is ultimately represented as a sequence of **bits**, 0 or 1 values, typically organized into **words** consisting of several 8-bit **bytes**.[6](#fn6)

A typical desktop computer might have enough RAM to store 232 bytes (4 gigabytes); the Zoo machines store 235 bytes (32 gigabytes). However, the **address space** of a process might be much larger: on a 64-bit machine, the address space is 264 bytes. There’s no way to store 264 different addresses in 235 bytes of RAM; instead, a **memory mapper**, typically built in to the CPU, translates the large addresses of the parts of the address space that are actually used into smaller addresses corresponding to actual RAM locations. In some cases, regions of memory that have not been used in a while will be **swapped out** to disk, leaving more RAM free for other parts of the process (or other processes). This technique is known as **virtual memory** and is usually invisible to the programmer. The use of virtual memory can increase the available space beyond the size of the RAM a little bit, but if you try to run a process that is actively using significantly more space that can be stored in RAM, it will slow down dramatically, because disk drives are roughly ten million times slower than memory.

The most basic kind of data represents integer values from some bounded range. C supports several **integer data types**, varying in their size (and thus range), and whether or not they are considered to be signed. These are described in more detail [below](#integerTypes).

For numerical computation, integer data types can be inconvenient. So C also supports **floating-point types** that consist of a fixed-size **mantissa**, which is essentially an integer, together with an **exponent** that is used to multiply the mantissa by 2_x_ for some _x_. These allow very small or very large values to be represented with small relative error, but do not allow exact computation because of the limited precision of the mantissa. Floating-point types are also described [below](#floatingPointTypes).

All other data is represented by converting it to either integer or floating-point numbers. For example, text characters in C are represented as small integer values, so that the character constant `'z'` representation a lower-case “z” is exactly the same as the integer constant `122` (which is the [ASCII](http://en.wikipedia.org/wiki/ASCII) code for “z”). A string like `"hi there"` is represented by a sequence of 8-bit ASCII characters, with a special 0 character to mark the end of the string. Strings that go beyond the English characters available in the ASCII encoding are typically represented using [Unicode](http://www.unicode.org/) and encoded as sequences of bytes using a particular representation called UTF-8. The color of a pixel in an image might be represented as three 8-bit integers representing the intensity of red, green, and blue in the color, while an image itself might be a long sequence of such 3-byte RGB values. At the bottom, every operation applied to these more complex data types translates into a whole lot of copies and arithmetic operations on individual bytes and words.

From the CPU’s point of view, even much of this manipulation consists of operating on integers that happen to represent addresses instead of data. So when a C program writes a zero to the 19th entry in a sequence of 4-byte integers, somewhere in the implementation of this operation the CPU will be adding 4 ⋅ 19 to a base address for the sequence to computer where to write this value. Unlike many higher-level languages, C allows the program direct access to address computations via **pointer types**, which are tricky enough to get [their own chapter](#pointers). Indeed, most of the structured types that C provides for representing more complicated data can best be understood as a thin layer of abstraction on top of pointers. We will see examples of these in later chapters as well.

For now, we concentrate on integer and floating-point types, and on the operations that can be applied to them.

### 4.2.1 Integer types in C

Most variables in C programs tend to hold integer values, and indeed most variables in C programs tend to be the default-width integer type `int`. Declaring a variable to have a particular integer type controls how much space is used to store the variable (any values too big to fit will be truncated) and specifies that the arithmetic on the variable is done using integer operations.

#### 4.2.1.1 Basic integer types

The standard C integer types are:

  

Name

Typical size

Signed by default?

`char`

8 bits

unspecified

`short`

16 bits

signed

`int`

32 bits

signed

`long`

32 bits

signed

`long long`

64 bits

signed

The typical size is for architectures like the Intel x86, which is the architecture used in most desktop and server machines. Some 64-bit machines might have 64-bit `int`s and `long`s, and some microcontrollers have 16-bit `int`s. Particularly bizarre architectures might have even wilder sizes, but you are not likely to see this unless you program vintage 1970s supercomputers. The general convention is that `int` is the most convenient size for whatever computer you are using and should be used by default.

Many compilers also support a `long long` type that is usually twice the length of a long (making it 64 bits on x86 machines). This type was not officially added to the C standard prior to C99, so it may or may not be available if you insist on following the ANSI specification strictly.

If you need to know the exact size of each type, you can use the `sizeof` operator, which returns the number of `char`s in a type. For example, on a typical machine, `sizeof(int)` will evaluate to `4`, and `sizeof(long long)` will evaluate to `8`. You can multiply by the constant `CHAR_BIT`, usually defined in `/usr/include/limits.h`, to translate these number to bits. However, if you are looking for a type that holds a particular number of bits, you are better off using a [C99 fixed-width type](#C99_fixed-width_types) like `int32_t`.

Each of these types comes in signed and unsigned variants.  
This controls the interpretation of some operations (mostly comparisons and shifts) and determines the range of the type: for example, an `unsigned char` holds values in the range 0 through 255 while a `signed char` holds values in the range -128 through 127, and in general an unsigned _n_\-bit type runs from 0 through 2_n_ − 1 while the signed version runs from  − 2_n_ − 1 through 2_n_ − 1 − 1. The representation of signed integers uses **two’s-complement** notation, which means that a positive value _x_ is represented as the unsigned value _x_ while a negative value  − _x_ is represented as the unsigned value 2_n_ − _x_. For example, if we had a peculiar implementation of C that used 3-bit `int`s, the binary values and their interpretation as `int` or `unsigned int` would look like this:

  

bits

as `unsigned int`

as `int`

000

0

0

001

1

1

010

2

2

011

3

3

100

4

\-4

101

5

\-3

110

6

\-2

111

7

\-1

The reason we get one extra negative value for a signed integer type is this allows us to interpret the first bit as the sign, which makes life a little easier for whoever is implementing our CPU. Two useful features of this representation are:

1.  We can convert freely between signed and unsigned values as long as we are in the common range of both, and
2.  Addition and subtraction work exactly the same we for both signed and unsigned values. For example, on our hypothetical 3-bit machine, 1 + 5 represented as 001 + 101 = 110 gives the same answer as 1 + ( − 3) = 001 + 101 = 110. In the first case we interpret 110 as 6, while in the second we interpret it as  − 2, but both answers are right in their respective contexts.

Note that in order to make this work, we can’t detect overflow: when the CPU adds two 3-bit integers, it doesn’t know if we are adding 7 + 6 = 111 + 110 = 1101 = 13 or ( − 1) + ( − 2) = 111 + 110 = 101 = ( − 3). In both cases the result is truncated to 101, which gives the incorrect answer 5 when we are adding unsigned values.

This can often lead to surprising uncaught errors in C programs, although using more than 3 bits will make overflow less likely. It is usually a good idea to pick a size for a variable that is substantially larger than the largest value you expect the variable to hold (although most people just default to `int`), unless you are very short on space or time (larger values take longer to read and write to memory, and may make some arithmetic operations take longer).

Taking into account signed and unsigned versions, the full collection of integer types looks like this:

  

`char`

`signed char`

`unsigned char`

`short`

`unsigned short`

`int`

`unsigned int`

`long`

`unsigned long`

`long long`

`unsigned long long`

So these are all examples of declarations of integer variables:

        int i;
        char c;
        signed char temperature; /* degrees Celsius, only valid for Earth's surface */
        long netWorthInPennies;
        long long billGatesNetWorthInPennies;
        unsigned short shaveAndAHaircutTwoBytes;

For `char`s, whether the character is signed ( − 128…127) or unsigned (0…255) is at the whim of the compiler. If it matters, declare your variables as `signed char` or `unsigned char`. For storing actual 8-bit characters that you aren’t doing arithmetic on, it shouldn’t matter.

There is a slight gotcha with character processing with the input functions `getchar` and `getc`. These return the special value `EOF` (defined in `stdio.h` to be  − 1) to indicate end of file. But 255, which represents `'ÿ'` in the ISO Latin-1 alphabet and in Unicode, and which may also appear quite often in binary files, will map to  − 1 if you put it in a `char`. So you should store the output of these functions in an `int` if you need to test for end of file. After you have done this test, it’s safe to store a non-end-of-file character in a `char`.

        /* right */
        int c;
    
        while((c = getchar()) != EOF) {
            putchar(c);
        }

        /* WRONG */
        char c;
    
        while((c = getchar()) != EOF) {  /* <- DON'T DO THIS! */
            putchar(c);
        }

#### 4.2.1.2 Overflow and the C standards

So far we have been assuming that overflow implicitly applies a (mod 2_b_) operation, where _b_ is the number of bits in our integer data type. This works on many machines, but as of the C11 standard, this is defined behavior only for _unsigned_ integer types. For _signed_ integer types, the effect of overflow is **undefined**. This means that the result of adding two very large signed `int`s could be arbitrary, and not only might depend on what CPU, compiler, and compiler options you are using, but might even vary from one execution of your program to another. In many cases this is not an issue, but undefined behavior is often exploited by compilers to speed up compiled code by omitting otherwise necessary instructions to force a particular outcome. This is especially true if you turn on the optimizer using the `-O` flag.

This means that you should not depend on reasonable behavior for overflow of signed types. Usually this is not a problem, because signed computations often represent real-world values where overflow will produce bad results anyway. For unsigned computations, the implicit modulo operation applied to overflow can be useful for some applications.

#### 4.2.1.3 C99 fixed-width types

C99 provides a `stdint.h` header file that defines integer types with known size independent of the machine architecture. So in C99, you can use `int8_t` instead of `signed char` to guarantee a signed type that holds exactly 8 bits, or `uint64_t` instead of `unsigned long long` to get a 64-bit unsigned integer type. The full set of types typically defined are `int8_t`, `int16_t`, `int32_t`, and `int64_t` for signed integers and `uint8_t`, `uint16_t`, `uint32_t`, and `uint64_t` for unsigned integers. There are also types for integers that contain the fewest number of bits greater than some minimum (e.g., `int_least16_t` is a signed type with at least 16 bits, chosen to minimize space) or that are the fastest type with at least the given number of bits (e.g., `int_fast16_t` is a signed type with at least 16 bits, chosen to minimize time). The `stdint.h` file also defines constants giving the minimum and maximum values of these and standard integer types; for example, `INT_MIN` and `INT_MAX` give the smallest and largest values that can be stored in an `int`.

All of these types are defined as aliases for standard integer types using [`typedef`](#typedef); the main advantage of using `stdint.h` over defining them yourself is that if somebody ports your code to a new architecture, `stdint.h` should take care of choosing the right types automatically. The main disadvantage is that, like many C99 features, `stdint.h` is not universally available on all C compilers. Also, because these fixed-width types are a late addition to the language, the built-in routines for printing and parsing integers, as well as the mechanisms for specifying the size of an integer constant, are not adapted to deal with them.

If you do need to print or parse types defined in `stdint.h`, the larger `inttypes.h` header defines macros that give the corresponding format strings for `printf` and `scanf`. The `inttypes.h` file includes `stdint.h`, so you do not need to include both. Below is an example of a program that uses the various features provided by `inttypes.h` and `stdint.h`.

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    #include <inttypes.h>
    
    /* example of using fixed-width types */
    
    /* largest value we can apply 3x+1 to without overflow */
    #define MAX_VALUE ((UINT64_MAX - 1) / 3)
            
    int
    main(int argc, char **argv)
    {
        uint64_t big;
    
        if(argc != 2) {
            fprintf(stderr, "Usage: %s number\n", argv[0]);
            return 1;
        }
    
        /* parse argv[1] as a uint64_t */
        /* SCNu64 expands to the format string for scanning uint64_t (without the %) */
        /* We then rely on C concatenating adjacent string constants. */
        sscanf(argv[1], "%" SCNu64, &big);
    
        /* do some arithmetic on big */
        while(big != 1) {
            /* PRIu64 expands to the format string for printing uint64_t */
            printf("%" PRIu64 "\n", big);
    
            if(big % 2 == 0) {
                big /= 2;
            } else if(big <= MAX_VALUE) {
                big = 3*big + 1;
            } else {
                /* overflow! */
                puts("overflow");
                return 1;
            }
        }
    
        puts("Reached 1");
        return 0;
    }

[examples/integerTypes/fixedWidth.c](examples/integerTypes/fixedWidth.c)

### 4.2.2 `size_t` and `ptrdiff_t`

The type aliases `size_t` and `ptrdiff_t` are provided in `stddef.h` to represent the return types of the `sizeof` operator and [pointer subtraction](#pointerArithmetic). On a 32-bit architecture, `size_t` will be equivalent to the unsigned 32-bit integer type `uint32_t` (or just `unsigned int`) and `ptrdiff_t` will be equivalent to the signed 32-bit integer type `int32_t` (`int`). On a 64-bit architecture, `size_t` will be equivalent to `uint64_t` and `ptrdiff_t` will be equivalent to `int64_t`.

The place where you will most often see `size_t` is as an argument to [`malloc`](#malloc), where it gives the number of bytes to allocate.

Because `stdlib.h` includes `stddef.h`, it is often not necessary to include `stddef.h` explicitly.

#### 4.2.2.1 Integer constants

Constant integer values in C can be written in any of four different ways:

*   In the usual decimal notation, e.g. `0`, `1`, `-127`, `9919291`, `97`.
*   In **octal** or base 8, when the leading digit is `0`, e.g. `01` for 1, `010` for 8, `0777` for 511, `0141` for 97. Octal is not used much any more, but it is still conventional for representing Unix file permissions.
*   In **hexadecimal** or base 16, when prefixed with `0x`. The letters `a` through `f` are used for the digits 10 through 15. For example, `0x61` is another way to write 97.
*   Using a **character constant**, which is a single [ASCII](http://en.wikipedia.org/wiki/ASCII "WikiPedia") character or an **escape sequence** inside single quotes. The value is the ASCII value of the character: `'a'` is 97.[7](#fn7) Unlike languages with separate character types, C characters are identical to integers; you can (but shouldn’t) calculate 972 by writing `'a'*'a'`. You can also store a character in a location with any integer type.

Except for character constants, you can insist that an integer constant is unsigned or long by putting a `u` or `l` after it. So `1ul` is an `unsigned long` version of 1. By default integer constants are (signed) `int`s. For `long long` constants, use `ll`, e.g., the `unsigned long long` constant `0xdeadbeef01234567ull`. It is also permitted to write the `l` as `L`, which can be less confusing if the `l` looks too much like a `1`.

Some examples:

 

`'a'`

`int`

`97`

`int`

`97u`

`unsigned int`

`0xbea00d1ful`

`unsigned long`, written in hexadecimal

`0777s`

`short`, written in octal

A curious omission is that there is no way to write a binary integer directly in C. So if you want to write the bit pattern 00101101, you will need to encode it in hexadecimal as `0x2d` (or octal as `055`). Another potential trap is that leading zeros matter: `012` is an octal value representing the number most people call 10.

##### 4.2.2.1.1 Naming constants

Having a lot of numeric constants in your program—particularly if the same constant shows up in more than one place—is usually a sign of bad programming. There are a few constants, like 0 and 1, that make sense on their own, but many constant values are either mostly arbitrary, or might change if the needs of the program change. It’s helpful to assign these constants names that explain their meaning, instead of requiring the user to guess why there is a `37` here or an `0x1badd00d` there. This is particularly important if the constants might change in later versions of the program, since even though you could change every `37` in your program into a `38`, this might catch other `37` values that have different intended meanings.

For example, suppose that you have a function (call it `getchar`) that needs to signal that sometimes it didn’t work. The usual way is to return a value that the function won’t normally return. Now, you could just tell the user what value that is:

    /* get a character (as an `int` ASCII code) from `stdin` */
    /* return -1 on end of file */
    int getchar(void);

and now the user can write

        while((c = getchar()) != -1) {
            ...
        }

But then somebody reading the code has to remember that `-1` means “end of file” and not “signed version of `0xff`” or “computer room on fire, evacuate immediately.” It’s much better to define a constant `EOF` that happens to equal `-1`, because among other things if you change the special return value from `getchar` later then this code will still work (assuming you fixed the definition of `EOF`):

        while((c = getchar()) != EOF) {
            ...
        }

So how do you declare a constant in C? The traditional approach is to use the C preprocessor, the same tool that gets run before the compiler to expand out `#include` directives. To define `EOF`, the file `/usr/include/stdio.h` includes the text

    #define EOF (-1)

What this means is that whenever the characters `EOF` appear in a C program as a separate word (e.g. in `1+EOF*3` but not in `appurtenancesTherEOF`), then the preprocessor will replace them with the characters `(-1)`. The parentheses around the `-1` are customary to ensure that the `-1` gets treated as a separate constant and not as part of some larger expression. So from the compiler’s perspective, `EOF` really is `-1`, but from the programmer’s perspective, it’s end-of-file. This is a special case of the C preprocessor’s [macro](#macros) mechanism.

In general, any time you have a non-trivial constant in a program, it should be `#define`d. Examples are things like array dimensions, special tags or return values from functions, maximum or minimum values for some quantity, or standard mathematical constants (for example, `/usr/include/math.h` defines `M_PI` as the mathematical constant pi to umpteen digits). This allows you to write

        char buffer[MAX_FILENAME_LENGTH+1];
        
        area = M_PI*r*r;
    
        if(status == COMPUTER_ROOM_ON_FIRE) {
            evacuate();
        }

instead of

        char buffer[513];
        
        area = 3.141592319*r*r;   /* not the correct value of pi */
    
        if(status == 136) {
            evacuate();
        }

which is just an invitation to errors (including the one in the area computation).

Like `typedef`s, `#define`s that are intended to be globally visible are best done in header files; in large programs you will want to `#include` them in many source files. The usual convention is to write `#define`d names in all-caps to remind the user that they are macros and not real variables.

#### 4.2.2.2 Integer operators

##### 4.2.2.2.1 Arithmetic operators

The usual `+` (addition), `-` (negation or subtraction), and `*` (multiplication) operators work on integers pretty much the way you’d expect. The only caveat is that if the result lies outside of the range of whatever variable you are storing it in, it will be truncated instead of causing an error:

        unsigned char c;
    
        c = -1;             /* sets c = 255 */
        c = 255 + 255;      /* sets c = 254 */
        c = 256 * 1772717;  /* sets c = 0 */

This can be a source of subtle bugs if you aren’t careful. The usual giveaway is that values you thought should be large positive integers come back as random-looking negative integers.

Division (`/`) of two integers also truncates: `2/3` is 0, `5/3` is 1, etc. For positive integers it will always round down.

Prior to C99, if either the numerator or denominator was negative, the behavior was unpredictable and depended on what your processor chose to do. In practice this meant you should never use `/` if one or both arguments might be negative. The C99 standard specified that integer division always removes the fractional part, effectively rounding toward 0; so `(-3)/2` is `-1`, `3/-2` is `-1`, and `(-3)/-2` is `1`.

There is also a remainder operator `%` with e.g. `2%3` = 2, `5%3` = 2, `27 % 2` = 1, etc. The sign of the modulus is ignored, so `2%-3` is also `2`. The sign of the dividend carries over to the remainder: `(-3)%2` and `(-3)%(-2)` are both `-1`. The reason for this rule is that it guarantees that `y == x*(y/x) + y%x` is always true.

##### 4.2.2.2.2 Bitwise operators

In addition to the arithmetic operators, integer types support **bitwise logical** operators that apply some Boolean operation to all the bits of their arguments in parallel. What this means is that the i-th bit of the output is equal to some operation applied to the i-th bit(s) of the input(s). The bitwise logical operators are `~` (bitwise negation: used with one argument as in `~0` for the all-1’s binary value), `&` (bitwise AND), ‘|’ (bitwise OR), and ‘^’ (bitwise XOR, i.e. sum mod 2). These are mostly used for manipulating individual bits or small groups of bits inside larger words, as in the expression `x & 0x0f`, which strips off the bottom four bits stored in `x`.

Examples:

   

`x`

`y`

expression

value

0011

0101

`x&y`

0001

0011

0101

`x|y`

0111

0011

0101

`x^y`

0110

0011

0101

`~x`

1100

The shift operators `<<` and `>>` shift the bit sequence left or right: `x << y` produces the value _x_ ⋅ 2_y_ (ignoring overflow); this is equivalent to shifting every bit in `x` `y` positions to the left and filling in `y` zeros for the missing positions. In the other direction, `x >> y` produces the value ⌊_x_ ⋅ 2−_y_⌋ by shifting `x` `y` positions to the right. The behavior of the right shift operator depends on whether `x` is unsigned or signed; for unsigned values, it shifts in zeros from the left end always; for signed values, it shifts in additional copies of the leftmost bit (the sign bit). This makes `x >> y` have the same sign as `x` if `x` is signed.

If `y` is negative, the behavior of the shift operators is undefined.

Examples (`unsigned char x`):

   

`x`

`y`

`x << y`

`x >> y`

00000001

1

00000010

00000000

11111111

3

11111000

00011111

Examples (`signed char x`):

   

`x`

`y`

`x << y`

`x >> y`

00000001

1

00000010

00000000

11111111

3

11111000

11111111

Shift operators are often used with bitwise logical operators to set or extract individual bits in an integer value. The trick is that `(1 << i)` contains a 1 in the `i`\-th least significant bit and zeros everywhere else. So `x & (1<<i)` is nonzero if and only if `x` has a 1 in the `i`\-th place. This can be used to print out an integer in binary format (which standard `printf` won’t do).

The following program gives an example of this technique. For example, when called as `./testPrintBinary 123`, it will print `00000000000000000000000001111011` followed by a newline.

    #include <stdio.h>
    #include <stdlib.h>
    
    /* print out all bits of n */
    void
    print_binary(unsigned int n)
    {
        unsigned int mask = 0;
    
        /* this grotesque hack creates a bit pattern 1000... */
        /* regardless of the size of an unsigned int */
        mask = ~mask ^ (~mask >> 1);
    
        for(; mask != 0; mask >>= 1) {
            putchar((n & mask) ? '1' : '0');
        }
    }
    
    int
    main(int argc, char **argv)
    {
        if(argc != 2) {
            fprintf(stderr, "Usage: %s n\n", argv[0]);
            return 1;
        }
    
        print_binary(atoi(argv[1]));
        putchar('\n');
    
        return 0;
    }

[examples/integerTypes/testPrintBinary.c](examples/integerTypes/testPrintBinary.c)

In the other direction, we can set the `i`\-th bit of `x` to 1 by doing `x | (1 << i)` or to 0 by doing `x & ~(1 << i)`. See the section on [bit manipulation](#bitManipulation). for applications of this to build arbitrarily-large bit vectors.

##### 4.2.2.2.3 Logical operators

To add to the confusion, there are also three **logical** operators that work on the **truth-values** of integers, where 0 is defined to be false and anything else is defined by be true. These are `&&` (logical AND), `||`, (logical OR), and `!` (logical NOT). The result of any of these operators is always 0 or 1 (so `!!x`, for example, is 0 if `x` is 0 and 1 if `x` is anything else). The `&&` and `||` operators evaluate their arguments left-to-right and ignore the second argument if the first determines the answer (this is the only place in C where argument evaluation order is specified); so

        0 && executeProgrammer();
        1 || executeProgrammer();

is in a very weak sense perfectly safe code to run.

Watch out for confusing `&` with `&&`. The expression `1 & 2` evaluates to 0, but `1 && 2` evaluates to 1. The statement `0 & executeProgrammer();` is also unlikely to do what you want.

Yet another logical operator is the **ternary operator** `?:`, where `x ? y : z` equals the value of `y` if `x` is nonzero and `z` if `x` is zero. Like `&&` and `||`, it only evaluates the arguments it needs to:

        fileExists(badFile) ? deleteFile(badFile) : createFile(badFile);

Most uses of `?:` are better done using an [if-then-else statement](#conditionals).

The convention that Boolean values in C are represented by integers means that C traditionally did not have an explicit Boolean type. If you want to use explicit Boolean types, you can include the `stdbool.h` header file (added in C99) with `#include <stdbool.h>`. This doesn’t give you much: it makes `bool` an integer type that can hold Boolean values, and defines `false` and `true` to be constants 0 and 1. Since `bool` is just another integer type, nothing prevents you from writing `x = 12 / true` or similar insults to the type system. But having explicit `bool`, `false`, and `true` keywords might make the intent of your code more explicit than the older `int`/`0`/`1` approach.

##### 4.2.2.2.4 Relational operators

Logical operators usually operate on the results of **relational operators** or comparisons: these are `==` (equality), `!=` (inequality), `<` (less than), `>` (greater than), `<=` (less than or equal to) and `>=` (greater than or equal to). So, for example,

        if(size >= MIN_SIZE && size <= MAX_SIZE) {
            puts("just right");
        }

tests if `size` is in the (inclusive) range \[`MIN_SIZE`..`MAX_SIZE`\].

Beware of confusing `==` with `=`. The code

        /* DANGER! DANGER! DANGER! */
        if(x = 5) {
            ...

is perfectly legal C, and will set `x` to 5 rather than testing if it’s equal to 5. Because 5 happens to be nonzero, the body of the `if` statement will always be executed. This error is so common and so dangerous that `gcc` will warn you about any tests that look like this if you use the `-Wall` option. Some programmers will go so far as to write the test as `5 == x` just so that if their finger slips, they will get a syntax error on `5 = x` even without special compiler support.

#### 4.2.2.3 Converting to and from strings

To input or output integer values, you will need to convert them from or to strings. Converting from a string is easy using the `atoi` or `atol` functions declared in `stdlib.h`; these take a string as an argument and return an `int` or `long`, respectively. C99 also provides `atoll` for converting to `long long`. These routines have no ability to signal an error other than returning 0, so if you do `atoi("Sweden")`, 0 is what you will get.

Output is usually done using `printf` (or `sprintf` if you want to write to a string without producing output). Use the `%d` format specifier for `int`s, `short`s, and `char`s that you want the numeric value of, `%ld` for `long`s, and `%lld` for `long long`s.

A contrived program that uses all of these features is given below:

    #include <stdio.h>
    #include <stdlib.h>
    
    /* This program can be used to show how atoi etc. handle overflow. */
    /* For example, try "overflow 1000000000000". */
    int
    main(int argc, char **argv)
    {
        char c;
        int i;
        long l;
        long long ll;
        
        if(argc != 2) {
            fprintf(stderr, "Usage: %s n\n", argv[0]);
            return 1;
        }
        
        c = atoi(argv[1]);
        i = atoi(argv[1]);
        l = atol(argv[1]);
        ll = atoll(argv[1]);
    
        printf("char: %d  int: %d  long: %ld  long long: %lld", c, i, l, ll);
    
        return 0;
    }

[examples/integerTypes/overflow.c](examples/integerTypes/overflow.c)

### 4.2.3 Floating-point types

Real numbers are represented in C by the **floating point** types `float`, `double`, and `long double`. Just as the integer types can’t represent all integers because they fit in a bounded number of bytes, so also the floating-point types can’t represent all real numbers. The difference is that the integer types can represent values within their range exactly, while floating-point types almost always give only an approximation to the correct value, albeit across a much larger range. The three floating point types differ in how much space they use (32, 64, or 80 bits on x86 CPUs; possibly different amounts on other machines), and thus how much precision they provide. Most math library routines expect and return `double`s (e.g., `sin` is declared as `double sin(double)`, but there are usually `float` versions as well (`float sinf(float)`).

#### 4.2.3.1 Floating point basics

The core idea of floating-point representations (as opposed to **fixed point representations** as used by, say, `int`s), is that a number _x_ is written as _m_ ⋅ _b__e_ where _m_ is a **mantissa** or fractional part, _b_ is a **base**, and _e_ is an **exponent**. On modern computers the base is almost always 2, and for most floating-point representations the mantissa will be scaled to be between 1 and _b_. This is done by adjusting the exponent, e.g.

1 = 1 ⋅ 20

2 = 1 ⋅ 21

0.375 = 1.5 ⋅ 2 − 2

etc.

The mantissa is usually represented in base 2, as a binary fraction. So (in a very low-precision format), $1 would be 1.000 ⋅ 20, 2 would be 1.000 ⋅ 21, and 0.375 = 3/8 would be 1.100 ⋅ 2 − 2, where the first 1 after the decimal point counts as 1/2, the second as 1/4, etc. Note that for a properly-scaled (or **normalized**) floating-point number in base 2 the digit before the decimal point is always 1. For this reason it is usually dropped to save space (although this requires a special representation for 0).

Negative values are typically handled by adding a **sign bit** that is 0 for positive numbers and 1 for negative numbers.

#### 4.2.3.2 Floating-point constants

Any number that has a decimal point in it will be interpreted by the compiler as a floating-point number. Note that you have to put at least one digit after the decimal point: `2.0`, `3.75`, `-12.6112`. You can specific a floating point number in scientific notation using `e` for the (base 10) exponent: `6.022e23`.

#### 4.2.3.3 Operators

Floating-point types in C support most of the same arithmetic and relational operators as integer types; `x > y`, `x / y`, `x + y` all make sense when `x` and `y` are `float`s. If you mix two different floating-point types together, the less-precise one will be extended to match the precision of the more-precise one; this also works if you mix integer and floating point types as in `2 / 3.0`. Unlike integer division, floating-point division does not discard the fractional part (although it may produce round-off error: `2.0/3.0` gives `0.66666666666666663`, which is not quite exact). Be careful about accidentally using integer division when you mean to use floating-point division: `2/3` is `0`. Casts can be used to convert integer values to floating-point values to force floating-point division (see below).

Some operators that work on integers will _not_ work on floating-point types. These are `%` (use `fmod` from the math library if you really need to get a floating-point remainder) and all of the bitwise operators `~`, `<<`, `>>`, `&`, `^`, and `|`.

#### 4.2.3.4 Conversion to and from integer types

Mixed uses of floating-point and integer types will convert the integers to floating-point. So `1 / 2.0` will give `0.5`.

You can convert floating-point numbers to and from integer types explicitly using casts. A typical use might be:

    /* return the average of a list */
    double
    average(int n, int a[])
    {
        int sum = 0;
        int i;
    
        for(i = 0; i < n; i++) {
            sum += a[i];
        }
    
        return (double) sum / n;
    }

If we didn’t put in the `(double)` to convert `sum` to a `double`, we’d end up doing integer division, which would truncate the fractional part of our average. Note that casts bind tighter than arithmetic operations, so the `(double)` applies to just `sum`, and not the whole expression `sum / n`.

In the other direction, we can write:

       i = (int) f;

to convert a `float f` to `int i`. This conversion loses information by throwing away the fractional part of `f`: if `f` was `3.2`, `i` will end up being just `3`.

The math library contains a pile of functions for converting values of type `double` to integer values of type `double` that give more control over the rounding: see for example the descriptions of `floor`, `ceil`, `round`, `trunc`, and `nearbyint` in the [GNU libc reference manual](http://www.gnu.org/software/libc/manual/html_node/Rounding-Functions.html).

#### 4.2.3.5 The IEEE-754 floating-point standard

C does not require a specific implementation of floating-point numbers, but unless you are running on very old or very odd hardware, you will probably find that `float`, `double`, and `long double` types are represented using the [IEEE-754 floating-point standard](https://en.wikipedia.org/wiki/IEEE_754). The standard is designed so that floating-point operations generally behave the way one would expect. This means that for most applications, you don’t need to know the details of the representation, but it is worth knowing about limits on accuracy of results, and about some extra floating-point values provided by IEEE-754 like `NaN` (“not a number”) or `inf` (positive infinity).

IEEE-754 defines several standard representations of floating-point numbers, all of which have the following basic pattern (the specific layout here is for a 32-bit `float`):

    bit  31 30    23 22                    0
         S  EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM

The bit numbers are counting from the least-significant bit. The first bit is the sign (0 for positive, 1 for negative). The following 8 bits are the exponent in **excess-127** binary notation; this means that the binary pattern 01111111 = 127 represents an exponent of 0, 10000000 = 128 represents 1, 01111110 = 126 represents -1, and so forth. The mantissa fits in the remaining 24 bits, with its leading 1 stripped off as described above.

Certain numbers have a special representation. Because 0 cannot be represented in the standard form (there is no 1 before the decimal point), it is given the special representation `0 00000000 00000000000000000000000`. (There is also a -0 = `1 00000000 00000000000000000000000`, which looks equal to +0 but prints differently.) Numbers with exponents of 11111111 = 255 = 2128 represent non-numeric quantities such as “not a number” (`NaN`), returned by operations like (`0.0/0.0`) and positive or negative infinity. A table of some typical floating-point numbers (generated by the program [float.c](examples/floatingPoint/float.c)) is given below:

             0 =                        0 = 0 00000000 00000000000000000000000
            -0 =                       -0 = 1 00000000 00000000000000000000000
         0.125 =                    0.125 = 0 01111100 00000000000000000000000
          0.25 =                     0.25 = 0 01111101 00000000000000000000000
           0.5 =                      0.5 = 0 01111110 00000000000000000000000
             1 =                        1 = 0 01111111 00000000000000000000000
             2 =                        2 = 0 10000000 00000000000000000000000
             4 =                        4 = 0 10000001 00000000000000000000000
             8 =                        8 = 0 10000010 00000000000000000000000
         0.375 =                    0.375 = 0 01111101 10000000000000000000000
          0.75 =                     0.75 = 0 01111110 10000000000000000000000
           1.5 =                      1.5 = 0 01111111 10000000000000000000000
             3 =                        3 = 0 10000000 10000000000000000000000
             6 =                        6 = 0 10000001 10000000000000000000000
           0.1 =      0.10000000149011612 = 0 01111011 10011001100110011001101
           0.2 =      0.20000000298023224 = 0 01111100 10011001100110011001101
           0.4 =      0.40000000596046448 = 0 01111101 10011001100110011001101
           0.8 =      0.80000001192092896 = 0 01111110 10011001100110011001101
         1e+12 =             999999995904 = 0 10100110 11010001101010010100101
         1e+24 =   1.0000000138484279e+24 = 0 11001110 10100111100001000011100
         1e+36 =   9.9999996169031625e+35 = 0 11110110 10000001001011111001110
           inf =                      inf = 0 11111111 00000000000000000000000
          -inf =                     -inf = 1 11111111 00000000000000000000000
           nan =                      nan = 0 11111111 10000000000000000000000

What this means in practice is that a 32-bit floating-point value (e.g. a `float`) can represent any number between `1.17549435e-38` and `3.40282347e+38`, where the `e` separates the (base 10) exponent. Operations that would create a smaller value will underflow to 0 (slowly—IEEE 754 allows “denormalized” floating point numbers with reduced precision for very small values) and operations that would create a larger value will produce `inf` or `-inf` instead.

For a 64-bit `double`, the size of both the exponent and mantissa are larger; this gives a range from `1.7976931348623157e+308` to `2.2250738585072014e-308`, with similar behavior on underflow and overflow.

Intel processors internally use an even larger 80-bit floating-point format for all operations. Unless you declare your variables as `long double`, this should not be visible to you from C except that some operations that might otherwise produce overflow errors will not do so, provided all the variables involved sit in registers (typically the case only for local variables and function parameters).

#### 4.2.3.6 Round-off error

In general, floating-point numbers are not exact: they are likely to contain **round-off error** because of the truncation of the mantissa to a fixed number of bits. This is particularly noticeable for large values (e.g. `1e+12` in the table above), but can also be seen in fractions with values that aren’t powers of 2 in the denominator (e.g. `0.1`). Round-off error is often invisible with the default float output formats, since they produce fewer digits than are stored internally, but can accumulate over time, particularly if you subtract floating-point quantities with values that are close (this wipes out the mantissa without wiping out the error, making the error much larger relative to the number that remains).

The easiest way to avoid accumulating error is to use high-precision floating-point numbers (this means using `double` instead of `float`). On modern CPUs there is little or no time penalty for doing so, although storing `double`s instead of `float`s will take twice as much space in memory.

Note that a consequence of the internal structure of IEEE 754 floating-point numbers is that small integers and fractions with small numerators and power-of-2 denominators can be represented _exactly_—indeed, the IEEE 754 standard carefully defines floating-point operations so that arithmetic on such exact integers will give the same answers as integer arithmetic would (except, of course, for division that produces a remainder). This fact can sometimes be exploited to get higher precision on integer values than is available from the standard integer types; for example, a `double` can represent any integer between  − 253 and 253 exactly, which is a much wider range than the values from 2 − 31 to 231 − 1 that fit in a 32-bit `int` or `long`. (A 64-bit `long long` does better.) So `double` should be considered for applications where large precise integers are needed (such as calculating the net worth in pennies of a billionaire.)

One consequence of round-off error is that it is very difficult to test floating-point numbers for equality, unless you are sure you have an exact value as described above. It is generally not the case, for example, that `(0.1+0.1+0.1) == 0.3` in C. This can produce odd results if you try writing something like `for(f = 0.0; f <= 0.3; f += 0.1)`: it will be hard to predict in advance whether the loop body will be executed with `f = 0.3` or not. (Even more hilarity ensues if you write `for(f = 0.0; f != 0.3; f += 0.1)`, which after not quite hitting `0.3` exactly keeps looping for much longer than I am willing to wait to see it stop, but which I suspect will eventually converge to some constant value of `f` large enough that adding `0.1` to it has no effect.) Most of the time when you are tempted to test floats for equality, you are better off testing if one lies within a small distance from the other, e.g. by testing `fabs(x-y) <= fabs(EPSILON * y)`, where `EPSILON` is usually some application-dependent tolerance. This isn’t quite the same as equality (for example, it isn’t transitive), but it usually closer to what you want.

#### 4.2.3.7 Reading and writing floating-point numbers

Any numeric constant in a C program that contains a decimal point is treated as a `double` by default. You can also use `e` or `E` to add a base-10 exponent (see the table for some examples of this.) If you want to insist that a constant value is a `float` for some reason, you can append `F` on the end, as in `1.0F`.

For I/O, floating-point values are most easily read and written using `scanf` (and its relatives `fscanf` and `sscanf`) and `printf`. For `printf`, there is an elaborate variety of floating-point format codes; the easiest way to find out what these do is experiment with them. For `scanf`, pretty much the only two codes you need are `"%lf"`, which reads a `double` value into a `double *`, and `"%f"`, which reads a `float` value into a `float *`. Both these formats are exactly the same in `printf`, since a `float` is promoted to a `double` before being passed as an argument to `printf` (or any other function that doesn’t declare the type of its arguments). But you have to be careful with the arguments to `scanf` or you will get odd results as only 4 bytes of your 8-byte `double` are filled in, or—even worse—8 bytes of your 4-byte `float` are.

#### 4.2.3.8 Non-finite numbers in C

The values `nan`, `inf`, and `-inf` can’t be written in this form as floating-point constants in a C program, but `printf` will generate them and `scanf` seems to recognize them. With some machines and compilers you may be able to use the macros `INFINITY` and `NAN` from `<math.h>` to generate non-finite quantities. The macros `isinf` and `isnan` can be used to detect such quantities if they occur.

#### 4.2.3.9 The math library

(See also K&R Appendix B4.)

Many mathematical functions on floating-point values are not linked into C programs by default, but can be obtained by linking in the math library. Examples would be the trigonometric functions `sin`, `cos`, and `tan` (plus more exotic ones), `sqrt` for taking square roots, `pow` for exponentiation, `log` and `exp` for base-e logs and exponents, and `fmod` for when you really want to write `x%y` but one or both variables is a `double`. The standard math library functions all take `double`s as arguments and return `double` values; most implementations also provide some extra functions with similar names (e.g., `sinf`) that use `float`s instead, for applications where space or speed is more important than accuracy.

There are two parts to using the math library. The first is to include the line

    #include <math.h>

somewhere at the top of your source file. This tells the preprocessor to paste in the declarations of the math library functions found in `/usr/include/math.h`.

The second step is to link to the math library when you compile. This is done by passing the flag `-lm` to `gcc` _after_ your C program source file(s). A typical command might be:

    gcc -o program program.c -lm

If you don’t do this, you will get errors from the compiler about missing functions. The reason is that the math library is not linked in by default, since for many system programs it’s not needed.

4.3 Operator precedence
-----------------------

**Operator precedence** in C controls the interpretation of ambiguous expressions like `2+3*4`, which could in principle be parsed either as `2+(3*4)` (the right way) or as `(2+3)*4` (the cheap calculator way). For the most part, C parses unparenthesized expressions the right way, but if you are not sure what it will do with an expression, you can always put in parentheses to force it to do the right thing.

There is a table on page 53 of Kernighan and Ritchie that shows the precedence of all operators in C, which we reproduce below.

The interpretation of this table is that higher entries bind tighter than lower ones; so the fact that `*` has higher precedence that `+` and both have higher precedence than `>` means that `2+3*4 > 5` gets parsed as `(2+(3*4)) > 5`.

Associativity controls how an expression with multiple operators of the same precedence is interpreted. The fact that `+` and `-` associate left-to-right means that the expression `2+3-4-5` is interpreted as `(((2+3)-4)-5)`: the leftmost operation is done first. Unary operators, ternary `?:` and assignment operators are the only ones that associate right-to-left. For assignment operators, this is so `x = y = 0` is interpreted as `x = (y = 0)` (assigning `0` to both `x` and `y`) and not `(x = y) = 0` (which would give an error because `(x = y)` isn’t something you can assign to). For unary operators, this mostly affects expressions like `*p++`, which is equivalent to `*(p++)` (increment the pointer first then dereference it) rather than `(*p)++` (increment the thing that `p` points to).

 

`()` `[]` `->` `.`

function calls and indexing

`!` `~` `-` (unary) `*` (unary) `&`(unary) `++` `--` `(`_type_`)` `sizeof`

unary operators (associate right-to-left)

`*` (binary) `/` `%`

multiplication and division

`+` (binary) `-` (binary)

addition and subtraction

`<<` `>>`

shifts

`<` `<=` `>=` `>`

inequalities

`==` `!=`

equality

`&` (binary)

bitwise AND

`^`

bitwise XOR

`|`

bitwise OR

`&&`

logical AND

`||`

logical OR

`?:`

ternary if (associates right-to-left)

`=` `+=` `-=` `*=` `/=` `%=` `&=` `^=` `|=` `<<=` `>>=`

assignment (associate right-to-left)

`,`

comma

4.4 Programming style
---------------------

The C programming language imposes very few constraints on how programs are formatted and organized. Both of the following are legitimate C programs, which compile to exactly the same machine code using `gcc` with a high enough optimization level:

    /*
     * Count down from COUNTDOWN_START (defined below) to 0.
     * Prints all numbers in the range including both endpoints.
     */
    
    #include <stdio.h>
    
    #define COUNTDOWN_START (10)
    
    int
    main(int argc, char **argv)
    {
        for(int i = COUNTDOWN_START; i >= 0; i--) {
            printf("%d\n", i);
        }
    
        return 0;
    }

[examples/style/countdown.c](examples/style/countdown.c)

    #include <stdio.h>
    int main(int _,char**xb){_=0xb;while(_--)printf("%d\n",_);return ++_;}

[examples/style/badCountdown.c](examples/style/badCountdown.c)

The difference between these programs is that the first is designed to be easy to read and understand while the second is not. Though the compiler can’t tell the difference between them, the second will be much harder to debug or modify to accomplish some new task.

Certain formatting and programming conventions have evolved over the years to make C code as comprehensible as possible, and as we introduce various features of C, we will talk about how best to use them to make your programs understood by both computers and humans.

Submitted assignments may be graded for style in addition to correctness. Below is a checklist that has been used in past versions of the course to identify some of the more egregious violations of reasonable coding practice. For more extreme examples of what not to do, see the [International Obfuscated C Code Contest](http://www.ioccc.org).

    Style grading checklist
    Score is 20 points minus 1 for each box checked (but never less than 0)
    
    Comments
    
    [ ] Undocumented module.
    [ ] Undocumented function other than main.
    [ ] Underdocumented function: return value or args not described.
    [ ] Undocumented program input and output (when main is provided).
    [ ] Undocumented struct or union components.
    [ ] Undocumented #define.
    [ ] Failure to cite code taken from other sources.
    [ ] Insufficient comments.
    [ ] Excessive comments.
    
    Naming
    
    [ ] Meaningless function name.
    [ ] Confusing variable name.
    [ ] Inconsistent variable naming style (UgLyName, ugly_name, NAME___UGLY_1).
    [ ] Inconsistent use of capitalization to distinguish constants.
    
    Whitespace
    
    [ ] Inconsistent or misleading indentation.
    [ ] Spaces not used or used misleadingly to break up complicated expressions.
    [ ] Blank lines not used or used misleadingly to break up long function bodies.
    
    Macros
    
    [ ] Non-trivial constant with no symbolic name.
    [ ] Failure to parenthesize expression in macro definition.
    [ ] Dependent constant not written as expression of earlier constant.
    [ ] Underdocumented parameterized macro.
    
    Global variables
    
    [ ] Inappropriate use of a global variable.
    
    Functions
    
    [ ] Kitchen-sink function that performs multiple unrelated tasks.
    [ ] Non-void function that returns no useful value.
    [ ] Function with too many arguments.
    
    Code organization
    
    [ ] Lack of modularity.
    [ ] Function used in multiple source files but not declared in header file.
    [ ] Internal-use-only function not declared static.
    [ ] Full struct definition in header files when components should be hidden.
    [ ] #include "file.c"
    [ ] Substantial repetition of code.
    
    Miscellaneous
    
    [ ] Other obstacle to readability not mentioned above.

4.5 Variables
-------------

Variables in C are a direct abstraction of physical memory locations. To understand how variables work, it helps to start by understanding how computer memory works.

### 4.5.1 Memory

Memory consists of many bytes of storage, each of which has an address which is itself a sequence of bits. Though the actual memory architecture of a modern computer is complex, from the point of view of a C program we can think of as simply a large **address space** that the CPU can store things in (and load things from), provided it can supply an address to the memory. Because we don’t want to have to type long strings of bits all the time, the C compiler lets us give names to particular regions of the address space, and will even find free space for us to use.

### 4.5.2 Variables as names

A **variable** is a name given in a program for some region of memory. Each variable has a **type**, which tells the compiler how big the region of memory corresponding to it is and how to treat the bits stored in that region when performing various kinds of operations (e.g. integer variables are added together by very different circuitry than floating-point variables, even though both represent numbers as bits). In modern programming languages, a variable also has a **scope** (a limit on where the name is meaningful, which allows the same name to be used for different variables in different parts of the program) and an **extent** (the duration of the variable’s existence, controlling when the program allocates and deallocates space for it).

#### 4.5.2.1 Variable declarations

Before you can use a variable in C, you must **declare** it. Variable declarations show up in three places:

*   Outside a function. These declarations declare **global variables** that are visible throughout the program (i.e. they have **global scope**). Use of global variables is almost always a mistake.
*   In the argument list in the header of a function. These variables are **parameters** to the function. They are only visible inside the function body (**local scope**), exist only from when the function is called to when the function returns (**bounded extent**—note that this is different from what happens in some garbage-collected languages like Scheme), and get their initial values from the arguments to the function when it is called.
*   Inside a function. (Before C99, only at the start of a block delimited by curly braces.) Such variables are visible only within the block in which they are declared (local scope again) and exist only when the containing function is active (bounded extent). The convention in C is has generally been to declare all such **local variables** at the top of a function; this is different from the convention in [C++](#cplusplus) or Java, which encourage variables to be declared when they are first used. This convention may be less strong in C99 code, since C99 adopts the C++ rule of allowing variables to be declared anywhere (which can be particularly useful for index variables in `for` loops).

Another feature of function parameters and local variables is that if a function is called more than once (even if the function [calls itself](#recursion)), each copy of the function gets its own local variables.

Variable declarations consist of a type name followed by one or more variable names separated by commas and terminated by a semicolon (except in argument lists, where each declaration is terminated by a comma). I personally find it easiest to declare variables one per line, to simplify documenting them. It is also possible for global and local variables (but not function arguments) to assign an initial value to a variable by putting in something like `= 0` after the variable name. It is good practice to put a comment after each variable declaration that explains what the variable does (with a possible exception for conventionally-named loop variables like `i` or `j` in short functions). Below is an example of a program with some variable declarations in it:

    #include <stdio.h>
    #include <ctype.h>
    
    /* This program counts the number of digits in its input. */
    
    /*
     *This global variable is not used; it is here only to demonstrate
     * what a global variable declaration looks like.
     */
    unsigned long SpuriousGlobalVariable = 127;
    
    int
    main(int argc, char **argv)
    {
        int c;              /* character read */
        int count = 0;      /* number of digits found */
    
        while((c = getchar()) != EOF) {
            if(isdigit(c)) {
                count++;
            }
        }
    
        printf("%d\n", count);
    
        return 0;
    }

[examples/variables/countDigits.c](examples/variables/countDigits.c)

#### 4.5.2.2 Variable names

C is pretty generous about what you can use in a variable name: generally any sequence of digits, letters, and the underscore character `_` can be used, so long as the first character is not a digit. Very old versions of C may limit the length of **external variables** (those that can be reference from other files, like library routines) to 6 characters, but modern versions don’t. (This explains the compact form of many standard library routine names like `malloc`, `printf`, or `strlen`.)

Older languages were more restrictive, and variable names have evolved over the years:

11101001001001

Physical addresses represented as bits.

`#FC27`

Typical assembly language address represented in hexadecimal to save typing (and because it’s easier for humans to distinguish #A7 from #B6 than to distinguish 10100111 from 10110110.)

`A1$`

A string variable in BASIC, back in the old days where BASIC variables were one uppercase letter, optionally followed by a number, optionally followed by $ for a string variable and % for an integer variable. These type tags were used because BASIC interpreters didn’t have a mechanism for declaring variable types.

`IFNXG7`

A typical FORTRAN variable name, back in the days of 6-character all-caps variable names. The `I` at the start means it’s an integer variable. The rest of the letters probably abbreviate some much longer description of what the variable means. The default type based on the first letter was used because FORTRAN programmers were lazy, but it could be overridden by an explicit declaration.

`i`, `j`, `c`, `count`, `top_of_stack`, `accumulatedTimeInFlight`

Typical names from modern C programs. There is no type information contained in the name; the type is specified in the declaration and remembered by the compiler elsewhere. Note that there are two different conventions for representing multi-word names: the first is to replace spaces with underscores (**[snake case](https://en.wikipedia.org/wiki/Snake_case)**), and the second is to capitalize the first letter of each word after the first (**[camel case](https://en.wikipedia.org/wiki/Camel_case)**). You should pick **one** of these two conventions and stick to it.

`prgcGradeDatabase`

An example of **Hungarian notation**, a style of variable naming in which the type of the variable is encoded in the first few character. The type is now back in the variable name again. This is _not_ enforced by the compiler: even though `iNumberOfStudents` is supposed to be an `int`, there is nothing to prevent you from declaring `float iNumberOfStudents` if you are teaching a class on improper chainsaw handling and want to allow for the possibility of fractional students. See [this MSDN page](http://msdn.microsoft.com/en-us/library/aa260976(v=vs.60).aspx) for a much more detailed explanation of the system.

Not clearly an improvement on standard naming conventions, but it is popular in some programming shops.

In C, variable names are called **identifiers**. These are also used to identify things that are not variables, like functions and user-defined types.

An identifier in C must start with a lower or uppercase letter or the underscore character `_`. Typically variables starting with underscores are used internally by system libraries, so it’s dangerous to name your own variables this way. Subsequent characters in an identifier can be letters, digits, or underscores. So for example `a`, `____a___a_a_11727_a`, `AlbertEinstein`, `aAaAaAaAaAAAAAa`, and `______` are all legal identifiers in C, but `$foo` and `01` are not.

The basic principle of variable naming is that a variable name is a substitute for the programmer’s memory. It is generally best to give identifiers names that are easy to read and describe what the variable is used for. Such variables are called **self-documenting**. None of the variable names in the preceding list are any good by this standard. Better names would be `total_input_characters`, `dialedWrongNumber`, or `stepsRemaining`. Non-descriptive single-character names are acceptable for certain conventional uses, such as the use of `i` and `j` for loop iteration variables, or `c` for an input character. Such names should only be used when the scope of the variable is small, so that it’s easy to see all the places where it is used at the same time.

C identifiers are case-sensitive, so `aardvark`, `AArDvARK`, and `AARDVARK` are all different variables. Because it is hard to remember how you capitalized something before, it is important to pick a standard convention and stick to it. The traditional convention in C goes like this:

*   Ordinary variables and functions are lowercased or camel-cased: `count`, `countOfInputBits`.
*   User-defined types (and in some conventions global variables) are capitalized: `Stack`, `TotalBytesAllocated`.
*   Constants created with `#define` or `enum` are written in all-caps: `MAXIMUM_STACK_SIZE`, `BUFFER_LIMIT`.

### 4.5.3 Using variables

Ignoring [pointers](#pointers) for the moment, there are essentially two things you can do to a variable. You can assign a value to it using the `=` operator, as in:

        x = 2;      /* assign 2 to x */
        y = 3;      /* assign 3 to y */

or you can use its value in an expression:

        x = y+1;    /* assign y+1 to x */

The assignment operator is an ordinary operator, and assignment expressions can be used in larger expressions:

        x = (y=2)*3; /* sets y to 2 and x to 6 */

This feature is usually only used in certain standard idioms, since it’s confusing otherwise.

There are also shorthand operators for expressions of the form _variable_ `=` _variable_ _operator_ _expression_. For example, writing `x += y` is equivalent to writing `x = x + y`, `x /= y` is the same as `x = x / y`, etc.

For the special case of adding or subtracting 1, you can abbreviate still further with the `++` and `--` operators. These come in two versions, depending on whether you want the result of the expression (if used in a larger expression) to be the value of the variable before or after the variable is incremented:

        x = 0;
        y = x++;    /* sets x to 1 and y to 0 (the old value) */
        y = ++x;    /* sets x to 2 and y to 2 (the new value) */
        y = x--;    /* sets x to 1 and y to 2 (the old value) */
        y = --x;    /* sets x to 0 and y to 0 (the new value) */

The intuition is that if the `++` comes before the variable, the increment happens before the value of the variable is read (a **preincrement**; if it comes after, it happens after the value is read (a **postincrement**). This is confusing enough that it is best not to use the value of preincrement or postincrement operations except in certain standard idioms. But using `x++` or `++x` by itself as a substitute for `x = x+1` is perfectly acceptable style.[8](#fn8)

### 4.5.4 Initialization

It is a serious error to use the value of a variable that has never been assigned to, because you will get whatever junk is sitting in memory at the address allocated to the variable, and this might be some arbitrary leftover value from a previous function call that doesn’t even represent the same type.[9](#fn9)

Fortunately, C provides a way to guarantee that a variable is initialized as soon as it is declared. Many of the examples in the notes do not use this mechanism, because of bad habits learned by the instructor using early versions of C that imposed tighter constraints on initialization. But initializing variables is a good habit to get in the practice of doing.

For variables with simple types (that is, not [arrays](#arrays), [structs](#structs), or [unions](#unions)), an initializer looks like an assignment:

        int sum = 0;
        int n = 100;
        int nSquared = n*n;
        double gradeSchoolPi = 3.14;
        const char * const greeting = "Hi!";
        const int greetingLength = strlen(greeting);

For ordinary local variables, the initializer value can be any expression, including expressions that call other functions. There is an exception for variables allocated when the program starts (which includes global variables outside functions and `static` variables inside functions), which can only be initialized to constant expressions.

The last two examples show how initializers can set the values of variables that are declared to be [`const`](#const) (the variable `greeting` is both constant itself, because of `const greeting`, and points to data that is also constant, because it is of type `const char`). This is the only way to set the values of such variables without cheating, because the compiler will complain if you try to do an ordinary assignment to a variable declared to be constant.

For fixed-size [arrays](#arrays) and [structs](#structs), it is possible to supply an initializer for each component, by enclosing the initializer values in braces, separated by commas. For example:

        int threeNumbers[3] = { 1, 2, 3 };
    
        struct numericTitle {
            int number;
            const char *name;
        };
    
        struct numericTitle s = { 7, "Samurai" };
        struct numericTitle n = { 3, "Ninjas" };

### 4.5.5 Storage class qualifiers

It is possible to specify additional information about how a variable can be used using **storage class qualifiers**, which usually go before the type of a variable in a declaration.

#### 4.5.5.1 Scope and extent

Most variables that you will use in C are either parameters to [functions](#functions) or local variables inside functions. These have **local scope**, meaning the variable names can only be used in the function in which they are declared, and **automatic extent**, meaning the space for the variable is allocated, typically on the stack, when the function is called, and reclaimed when the function exits. (If the function calls itself, you get another copy of all the local variables; see [recursion](#recursion).)

On _very rare_ occasions you might want to have a variable that survives the entire execution of a program (has **static extent**) or that is visible throughout the program (has **global scope**). C provides a mechanism for doing this _that you shold never use under normal circumstances_. Pretty much the only time you are going to want to have a variable with static extent is if you are keeping track of some piece of information that (a) you only need one instance of, (b) you need to survive between function calls, and (c) it would be annoying to pass around as an extra argument to any function that uses it. An example would be the internal data structures used by [`malloc`](#malloc), or the count variable in the function below:

    /* returns the number of times this function has previously been called */
    /* this can be used to generate unique numerical identifiers */
    unsigned long long
    ticketMachine(void)
    {
        static unsigned long long count = 0;
    
        return count++;
    }

To declare a local variable with static extent, use the `static` qualifier as in the above example. To declare a global variable with static extent, declare it outside a function. In both cases you should provide an [initializer](#initializers) for the variable.

##### 4.5.5.1.1 Additional qualifiers for global variables

It is possible to put some additional constraints on the visibility of global variables. By default, a global variable will be visible everywhere, but functions files other than the one in which it is defined won’t necessarily know what type it has. This latter problem can be fixed using an `extern` declaration, which says that there is a variable somewhere else of a particular type that we are declaring (but not defining, so no space is allocated). In contrast, the `static` keyword (on a global variable) specifies that it will only be visible in the current file, even if some other file includes a declaration of a global variable of the same name.

Here are three variable declarations that illustrate how this works:

        unsigned short Global = 5;    /* global variable, can be used anywhere */
    
        extern float GlobalFloat;     /* this global variable, defined somewhere else, has type float */
    
        static char Character = 'c';  /* global variable, can only be used by functions in this file */

(Note the convention of putting capital letters on global variables to distinguish them from local variables.)

Typically, an `extern` definition would appear in a header file so that it can be included in any function that uses the variable, while an ordinary global variable definition would appear in a C file so it only occurs once.

### 4.5.6 Marking variables as constant

The **const** qualifier declares a variable to be constant:

        const int three = 3;   /* this will always be 3 */

It is an error to apply any sort of assignment (`=`, `+=`, `++`, etc.) to a variable qualified as `const`.

#### 4.5.6.1 Pointers to `const`

A [pointer](#pointers) to a region that should not be modified should be declared with `const` type:

        const char *string = "You cannot modify this string.";

The `const` in the declaration above applies to the characters that `string` points to: `string` is not `const` itself, but is instead a _pointer to `const`_. It is still possible to make `string` point somewhere else, say by doing an assignment:

        string = "You cannot modify this string either."

If you want to make it so that you can’t assign to `string`, put `const` right before the variable name:

        /* prevent assigning to string as well */
        const char * const string = "You cannot modify this string.";

Now `string` is a `const` pointer to `const`: you can neither modify `string` nor the values it points to.

Note that `const` only restricts what you can do using this particular variable name. If you can get at the memory that something points to by some other means, say through another pointer, you may be able to change the values in these memory locations anyway:

        int x = 5;
        const int *p = &x;
        int *q;
    
        *p = 1; /* will cause an error at compile time */
        x = 3;  /* also changes *p, but will not cause an error */

4.6 Input and output
--------------------

Input and output from C programs is typically done through the **standard I/O library**, whose functions etc. are declared in `stdio.h`. A detailed descriptions of the functions in this library is given in Appendix B of Kernighan and Ritchie. We’ll talk about some of the more useful functions and about how input-output (I/O) works on Unix-like operating systems in general.

### 4.6.1 Character streams

The standard I/O library works on **character streams**, objects that act like long sequences of incoming or outgoing characters. What a stream is connected to is often not apparent to a program that uses it; an output stream might go to a terminal, to a file, or even to another program (appearing there as an input stream).

Three standard streams are available to all programs: these are `stdin` (standard input), `stdout` (standard output), and `stderr` (standard error). Standard I/O functions that do not take a stream as an argument will generally either read from `stdin` or write to `stdout`. The `stderr` stream is used for error messages. It is kept separate from `stdout` so that you can see these messages even if you redirect output to a file:

    $ ls no-such-file > /tmp/output
    ls: no-such-file: No such file or directory

### 4.6.2 Reading and writing single characters

To read a single character from `stdin`, use `getchar`:

        int c;
    
        c = getchar();

The `getchar` routine will return the special value `EOF` (usually -1; short for _end of file_) if there are no more characters to read, which can happen when you hit the end of a file or when the user types the end-of-file key control-D to the terminal. Note that the return value of `getchar` is declared to be an `int` since `EOF` lies outside the normal character range.

To write a single character to `stdout`, use `putchar`:

        putchar('!');

Even though `putchar` can only write single bytes, it takes an `int` as an argument. Any value outside the range 0..255 will be truncated to its last byte, as in the usual conversion from `int` to `unsigned char`.

Both `getchar` and `putchar` are wrappers for more general routines `getc` and `putc` that allow you to specify which stream you are using. To illustrate `getc` and `putc`, here’s how we might define `getchar` and `putchar` if they didn’t exist already:

    int
    getchar2(void)
    {
        return getc(stdin);
    }
    
    int
    putchar2(int c)
    {
        return putc(c, stdout);
    }

Note that `putc`, `putchar2` as defined above, and the original `putchar` all return an `int` rather than `void`; this is so that they can signal whether the write succeeded. If the write succeeded, `putchar` or `putc` will return the value written. If the write failed (say because the disk was full), then `putc` or `putchar` will return `EOF`.

Here’s another example of using `putc` to make a new function `putcerr` that writes a character to `stderr`:

    int
    putcerr(int c)
    {
        return putc(c, stderr);
    }

A rather odd feature of the C standard I/O library is that if you don’t like the character you just got, you can put it back using the `ungetc` function. The limitations on `ungetc` are that (a) you can only push one character back, and (b) that character can’t be `EOF`. The `ungetc` function is provided because it makes certain high-level input tasks easier; for example, if you want to parse a number written as a sequence of digits, you need to be able to read characters until you hit the first non-digit. But if the non-digit is going to be used elsewhere in your program, you don’t want to eat it. The solution is to put it back using `ungetc`.

Here’s a function that uses `ungetc` to peek at the next character on `stdin` without consuming it:

    /* return the next character from stdin without consuming it */
    int
    peekchar(void)
    {
        int c;
    
        c = getchar();
        if(c != EOF) ungetc(c, stdin);      /* puts it back */
        
        return c;
    }

### 4.6.3 Formatted I/O

Reading and writing data one character at a time can be painful. The C standard I/O library provides several convenient routines for reading and writing formatted data. The most commonly used one is `printf`, which takes as arguments a format string followed by zero or more values that are filled in to the format string according to patterns appearing in it.

Here are some typical `printf` statements:

        printf("Hello\n");          /* print "Hello" followed by a newline */
        printf("%c", c);            /* equivalent to putchar(c) */
        printf("%d", n);            /* print n (an int) formatted in decimal */
        printf("%u", n);            /* print n (an unsigned int) formatted in decimal */
        printf("%o", n);            /* print n (an unsigned int) formatted in octal */
        printf("%x", n);            /* print n (an unsigned int) formatted in hexadecimal */
        printf("%f", x);            /* print x (a float or double) */
    
        /* print total (an int) and average (a double) on two lines with labels */
        printf("Total: %d\nAverage: %f\n", total, average);

For a full list of formatting codes see Table B-1 in Kernighan and Ritchie, or run `man 3 printf`.

The inverse of `printf` is `scanf`. The `scanf` function reads formatted data from `stdin` according to the format string passed as its first argument and stuffs the results into variables whose _addresses_ are given by the later arguments. This requires prefixing each such argument with the `&` operator, which takes the address of a variable.

Format strings for `scanf` are close enough to format strings for `printf` that you can usually copy them over directly. However, because `scanf` arguments don’t go through argument promotion (where all small integer types are converted to `int` and `float`s are converted to `double`), you have to be much more careful about specifying the type of the argument correctly. For example, while `printf("%f", x)` will work whether `x` is a `float` or a `double`, `scanf("%f", &x)` will work only if `x` is a `float`, which means that `scanf("%lf", &x)` is needed if `x` is in fact a `double`.

Some examples:

        scanf("%c", &c);            /* like c = getchar(); c must be a char; will NOT put EOF in c */
        scanf("%d", &n);            /* read an int formatted in decimal */
        scanf("%u", &n);            /* read an unsigned int formatted in decimal */
        scanf("%o", &n);            /* read an unsigned int formatted in octal */
        scanf("%x", &n);            /* read an unsigned int formatted in hexadecimal */
        scanf("%f", &x);            /* read a float */
        scanf("%lf", &x);           /* read a double */
    
        /* read total (an int) and average (a float) on two lines with labels */
        /* (will also work if input is missing newlines or uses other whitespace, see below) */
        scanf("Total: %d\nAverage: %f\n", &total, &average);

For a full list of formatting codes, run `man 3 scanf`.

The `scanf` routine usually eats whitespace (spaces, tabs, newlines, etc.) in its input whenever it sees a conversion specification or a whitespace character in its format string. The one exception is that a `%c` conversion specifier will not eat whitespace and will instead return the next character whether it is whitespace or not. Non-whitespace characters that are not part of conversion specifications must match exactly. To detect if `scanf` parsed everything successfully, look at its return value; it returns the number of values it filled in, or `EOF` if it hits end-of-file before filling in any values.

The `printf` and `scanf` routines are wrappers for `fprintf` and `fscanf`, which take a stream as their first argument, e.g.:

        fprintf(stderr, "BUILDING ON FIRE, %d%% BURNT!!!\n", percentage);

This sends the output to the standard error output handle `stderr`. Note the use of “%%” to print a single percent in the output.

### 4.6.4 Rolling your own I/O routines

Since we can write our own functions in C, if we don’t like what the standard routines do, we can build our own on top of them. For example, here’s a function that reads in integer values without leading minus signs and returns the result. It uses the `peekchar` routine we defined above, as well as the `isdigit` routine declared in `ctype.h`.

    /* read an integer written in decimal notation from stdin until the first
     * non-digit and return it.  Returns 0 if there are no digits. */
    int
    readNumber(void)
    {
        int accumulator;    /* the number so far */
        int c;              /* next character */
    
        accumulator = 0;
    
        while((c = peekchar()) != EOF && isdigit(c)) {
            c = getchar();                  /* consume it */
            accumulator *= 10;              /* shift previous digits over */
            accumulator += (c - '0');       /* add decimal value of new digit */
        }
    
        return accumulator;
    }

Here’s another implementation that does _almost_ the same thing:

    int
    readNumber2(void)
    {
        int n;
    
        if(scanf("%u", &n) == 1) {
            return n;
        } else {
            return 0;
        }
    }

The difference is that `readNumber2` will consume any whitespace before the first digit, which may or may not be what we want.

### 4.6.5 Recursive descent parsing

More complex routines can be used to parse more complex input. For example, here’s a routine that uses `readNumber` to parse simple arithmetic expressions, where each expression is either a number or of the form `(`_expression_`+`_expression_`)` or `(`_expression_`*`_expression_`)`. The return value is the value of the expression after adding together or multiplying all of its subexpressions. (A complete program including this routine and the others defined earlier that it uses can be found [examples/IO/calc.c](examples/IO/calc.c).

    #define EXPRESSION_ERROR (-1)
    
    /* read an expression from stdin and return its value */
    /* returns EXPRESSION_ERROR on error */
    int
    readExpression(void)
    {
        int e1;             /* value of first sub-expression */
        int e2;             /* value of second sub-expression */
        int c;
        int op;             /* operation: '+' or '*' */
    
        c = peekchar();
    
        if(c == '(') {
            c = getchar();
    
            e1 = readExpression();
            op = getchar();
            e2 = readExpression();
    
            c = getchar();  /* this had better be ')' */
            if(c != ')') return EXPRESSION_ERROR;
    
            /* else */
            switch(op) {
            case '*':
                return e1*e2;
                break;
            case '+':
                return e1+e2;
                break;
            default:
                return EXPRESSION_ERROR;
                break;
            }
        } else if(isdigit(c)) {
            return readNumber();
        } else {
            return EXPRESSION_ERROR;
        }
    }

Because this routine calls itself recursively as it works its way down through the input, it is an example of a [recursive descent parser](http://en.wikipedia.org/wiki/Recursive_descent_parser "WikiPedia"). Parsers for more complicated languages like C are usually not written by hand like this, but are instead constructed mechanically using a [parser generator](http://en.wikipedia.org/wiki/Parser_generator "WikiPedia").

### 4.6.6 File I/O

Reading and writing files is done by creating new streams attached to the files. The function that does this is `fopen`. It takes two arguments: a filename, and a flag that controls whether the file is opened for reading or writing. The return value of `fopen` has type `FILE *` and can be used in `putc`, `getc`, `fprintf`, etc. just like `stdin`, `stdout`, or `stderr`. When you are done using a stream, you should close it using `fclose`.

Here’s a program that reads a list of numbers from a file whose name is given as `argv[1]` and prints their sum:

    #include <stdio.h>
    #include <stdlib.h>
    
    /*
     * Sum integers in a file.
     *
     * 2018-01-24 Includes bug fixes contributed by Zhe Hua.
     */
    
    int
    main(int argc, char **argv)
    {
        FILE *f;
        int x;
        int sum;
    
        if(argc != 2) {
            fprintf(stderr, "Usage: %s filename\n", argv[0]);
            exit(1);
        }
    
        f = fopen(argv[1], "r");
        if(f == 0) {
            /* perror is a standard C library routine */
            /* that prints a message about the last failed library routine */
            /* prepended by its argument */
            perror(argv[1]);
            exit(2);
        }
    
        /* else everything is ok */
        sum = 0;
        while(fscanf(f, "%d", &x) == 1) {
            sum += x;
        }
    
        printf("%d\n", sum);
    
        /* not strictly necessary but it's polite */
        fclose(f);
    
        return 0;
    }

[examples/IO/sum.c](examples/IO/sum.c)

To write to a file, open it with `fopen(filename, "w")`. Note that as soon as you call `fopen` with the `"w"` flag, any previous contents of the file are erased. If you want to append to the end of an existing file, use `"a"` instead. You can also add `+` onto the flag if you want to read and write the same file (this will probably involve using `fseek`).

Some operating systems (Windows) make a distinction between text and binary files. For text files, use the same arguments as above. For binary files, add a `b`, e.g. `fopen(filename, "wb")` to write a binary file.

    /* leave a greeting in the current directory */
    
    #include <stdio.h>
    #include <stdlib.h>
    
    #define FILENAME "hello.txt"
    #define MESSAGE "hello world"
    
    int
    main(int argc, char **argv)
    {
        FILE *f;
    
        f = fopen(FILENAME, "w");
        if(f == 0) {
            perror(FILENAME);
            exit(1);
        }
    
        /* unlike puts, fputs doesn't add a newline */
        fputs(MESSAGE, f);
        putc('\n', f);
    
        fclose(f);
    
        return 0;
    }

[examples/IO/helloFile.c](examples/IO/helloFile.c)

4.7 Statements and control structures
-------------------------------------

The bodies of C functions (including the `main` function) are made up of **statements**. These can either be **simple statements** that do not contain other statements, or **compound statements** that have other statements inside them. **Control structures** are compound statements like if/then/else, while, for, and do..while that control how or whether their component statements are executed.

### 4.7.1 Simple statements

The simplest kind of statement in C is an expression (followed by a semicolon, the terminator for all simple statements). Its value is computed and discarded. Examples:

        x = 2;              /* an assignment statement */
        x = 2+3;            /* another assignment statement */
        2+3;                /* has no effect---will be discarded by smart compilers */
        puts("hi");         /* a statement containing a function call */
        root2 = sqrt(2);    /* an assignment statement with a function call */

Most statements in a typical C program are simple statements of this form.

Other examples of simple statements are the jump statements `return`, `break`, `continue`, and `goto`. A `return` statement specifies the return value for a function (if there is one), and when executed it causes the function to exit immediately. The `break` and `continue` statements jump immediately to the end of a loop (or `switch`; see below) or the next iteration of a loop; we’ll talk about these more when we talk about loops. The `goto` statement jumps to another location in the same function, and exists for the rare occasions when it is needed. Using it in most circumstances is a sin.

### 4.7.2 Compound statements

Compound statements come in two varieties: conditionals and loops.

#### 4.7.2.1 Conditionals

These are compound statements that test some condition and execute one or another block depending on the outcome of the condition. The simplest is the `if` statement:

        if(houseIsOnFire) {
            /* ouch! */
            scream();
            runAway();
        }

The **body** of the `if` statement is executed only if the expression in parentheses at the top evaluates to true (which in C means any value that is not 0).

The braces are not strictly required, and are used only to group one or more statements into a single statement. If there is only one statement in the body, the braces can be omitted:

        if(programmerIsLazy) omitBraces();

This style is recommended only for very simple bodies. Omitting the braces makes it harder to add more statements later without errors.

        if(underAttack)
            launchCounterAttack();   /* executed only when attacked */
            hideInBunker();          /* ### DO NOT INDENT LIKE THIS ### executed always */

In the example above, the lack of braces means that the `hideInBunker()` statement is _not_ part of the `if` statement, despite the misleading indentation. This sort of thing is why I generally always put in braces in an `if`.

An `if` statement may have an `else` clause, whose body is executed if the test is false (i.e. equal to 0).

        if(happy) {
            smile();
        } else {
            frown();
        }

A common idiom is to have a chain of `if` and `else if` branches that test several conditions:

        if(temperature < 0) {
            puts("brrr");
        } else if(temperature < 100) {
            puts("hooray");
        } else {
            puts("ouch!");
        }

This can be inefficient if there are a lot of cases, since the tests are applied sequentially. For tests of the form _<expression>_ `==` _<small constant>_, the `switch` statement may provide a faster alternative. Here’s a typical `switch` statement:

        /* print plural of cow, maybe using the obsolete dual number construction */
        switch(numberOfCows) {
        case 1:
            puts("cow");
            break;
        case 2:
            puts("cowen");
            break;
        default:
            puts("cows");
            break;
        }

This prints the string “cow” if there is one cow, “cowen” if there are two cowen, and “cows” if there are any other number of cows. The `switch` statement evaluates its argument and jumps to the matching `case` label, or to the `default` label if none of the cases match. Cases must be constant integer values.

The `break` statements inside the block jump to the end of the block. Without them, executing the `switch` with `numberOfCows` equal to 1 would print all three lines. This can be useful in some circumstances where the same code should be used for more than one case:

        switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            type = VOWEL;
            break;
        default:
            type = CONSONANT;
            break;
        }

or when a case “falls through” to the next:

        switch(countdownStart) {
        case 3:
            puts("3");
        case 2:
            puts("2");
        case 1:
            puts("1")
        case 0:
            puts("KABLOOIE!");
            break;
        default:
            puts("I can't count that high!");
            break;
        }

Note that it is customary to include a `break` on the last case even though it has no effect; this avoids problems later if a new case is added. It is also customary to include a `default` case even if the other cases supposedly exhaust all the possible values, as a check against bad or unanticipated inputs.

        switch(oliveSize) {
        case JUMBO:
            eatOlives(SLOWLY);
            break;
        case COLLOSSAL:
            eatOlives(QUICKLY);
            break;
        case SUPER_COLLOSSAL:
            eatOlives(ABSURDLY);
            break;
        default:
            /* unknown size! */
            abort();
            break;
        }

Though `switch` statements are better than deeply nested if/else-if constructions, it is often even better to organize the different cases as data rather than code. We’ll see examples of this when we talk about [function pointers](#functionPointers).

Nothing in the C standards prevents the `case` labels from being buried inside other compound statements. One rather hideous application of this fact is [Duff’s device](http://en.wikipedia.org/wiki/Duff%27s_device "WikiPedia").

#### 4.7.2.2 Loops

There are three kinds of loops in C.

##### 4.7.2.2.1 The while loop

A `while` loop tests if a condition is true, and if so, executes its body. It then tests the condition is true again, and keeps executing the body as long as it is. Here’s a program that deletes every occurrence of the letter `e` from its input.

    #include <stdio.h>
    
    int
    main(int argc, char **argv)
    {
        int c;
    
        while((c = getchar()) != EOF) {
            switch(c) {
            case 'e':
            case 'E':
                break;
            default:
                putchar(c);
                break;
            }
        }
    
        return 0;
    }

Note that the expression inside the `while` argument both assigns the return value of `getchar` to `c` and tests to see if it is equal to `EOF` (which is returned when no more input characters are available). This is a very common idiom in C programs. Note also that even though `c` holds a single character, it is declared as an `int`. The reason is that `EOF` (a constant defined in `stdio.h`) is outside the normal character range, and if you assign it to a variable of type `char` it will be quietly truncated into something else. Because C doesn’t provide any sort of exception mechanism for signalling unusual outcomes of function calls, designers of library functions often have to resort to extending the output of a function to include an extra value or two to signal failure; we’ll see this a lot when the null pointer shows up in the chapter on [pointers](#pointers).

##### 4.7.2.2.2 The do..while loop

The `do`..`while` statement is like the `while` statement except the test is done at the end of the loop instead of the beginning. This means that the body of the loop is always executed at least once.

Here’s a loop that does a random walk until it gets back to 0 (if ever). If we changed the `do`..`while` loop to a `while` loop, it would never take the first step, because `pos` starts at 0.

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    
    int
    main(int argc, char **argv)
    {
        int pos = 0;       /* position of random walk */
    
        srandom(time(0));  /* initialize random number generator */
    
        do {
            pos += random() & 0x1 ? +1 : -1;
            printf("%d\n", pos);
        } while(pos != 0);
    
        return 0;
    }

[examples/statements/randomWalk.c](examples/statements/randomWalk.c)

The `do`..`while` loop is used much less often in practice than the `while` loop.

It is theoretically possible to convert a `do`..`while` loop to a `while` loop by making an extra copy of the body in front of the loop, but this is not recommended since it’s almost always a bad idea to duplicate code.

##### 4.7.2.2.3 The for loop

The `for` loop is a form of [syntactic sugar](http://en.wikipedia.org/wiki/Syntactic_sugar) that is used when a loop iterates over a sequence of values stored in some variable (or variables). Its argument consists of three expressions: the first initializes the variable and is called once when the statement is first reached. The second is the test to see if the body of the loop should be executed; it has the same function as the test in a `while` loop. The third sets the variable to its next value. Some examples:

        /* count from 0 to 9 */
        for(i = 0; i < 10; i++) {
            printf("%d\n", i);
        }
        
        /* and back from 10 to 0 */
        for(i = 10; i >= 0; i--) {
            printf("%d\n", i);
        }
    
        /* this loop uses some functions to move around */
        for(c = firstCustomer(); c != END_OF_CUSTOMERS; c = customerAfter(c)) {
            helpCustomer(c);
        }
    
        /* this loop prints powers of 2 that are less than n*/
        for(i = 1; i < n; i *= 2) {
            printf("%d\n", i);
        }
    
        /* this loop does the same thing with two variables by using the comma operator */
        for(i = 0, power = 1; power < n; i++, power *= 2) {
            printf("2^%d = %d\n", i, power);
        }
    
        /* Here are some nested loops that print a times table */
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                printf("%d*%d=%d ", i, j, i*j);
            }
            putchar('\n');
        }

A `for` loop can always be rewritten as a `while` loop.

        for(i = 0; i < 10; i++) {
            printf("%d\n", i);
        }
    
        /* is exactly the same as */
    
        i = 0;
        while(i < 10) {
            printf("%d\n", i);
            i++;
        }

##### 4.7.2.2.4 Loops with break, continue, and goto

The `break` statement immediately exits the innermmost enclosing loop or `switch` statement.

        for(i = 0; i < n; i++) {
            openDoorNumber(i);
            if(boobyTrapped()) {
                break;
            }
        }

The `continue` statement skips to the next iteration. Here is a program with a loop that iterates through all the integers from -10 through 10, skipping 0:

    #include <stdio.h>
    
    /* print a table of inverses */
    #define MAXN (10)
    
    int
    main(int argc, char **argv)
    {
        int n;
    
        for(n = -MAXN; n <= MAXN; n++) {
            if(n == 0) continue;
            printf("1.0/%3d = %+f\n", n, 1.0/n);
        }
    
        return 0;
    }

[examples/statements/inverses.c](examples/statements/inverses.c)

Occasionally, one would like to break out of more than one nested loop. The way to do this is with a `goto` statement.

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                doSomethingTimeConsumingWith(i, j);
                if(checkWatch() == OUT_OF_TIME) {
                    goto giveUp;
                }
            }
        }
    giveUp:
        puts("done");

The target for the `goto` is a **label**, which is just an identifier followed by a colon and a statement (the empty statement `;` is ok).

The `goto` statement can be used to jump anywhere within the same function body, but breaking out of nested loops is widely considered to be its only genuinely acceptable use in normal code.

#### 4.7.2.3 Choosing where to put a loop exit

Choosing where to put a loop exit is usually pretty obvious: you want it after any code that you want to execute at least once, and before any code that you want to execute only if the termination test fails.

If you know in advance what values you are going to be iterating over, you will most likely be using a `for` loop:

    for(i = 0; i < n; i++) {
        a[i] = 0;
    }

Most of the rest of the time, you will want a `while` loop:

    while(!done()) {
        doSomething();
    }

The `do`..`while` loop comes up mostly when you want to try something, then try again if it failed:

    do {
        result = fetchWebPage(url);
    } while(result == 0);

Finally, leaving a loop in the middle using `break` can be handy if you have something extra to do before trying again:

    for(;;) {
        result = fetchWebPage(url);
        if(result != 0) {
            break;
        }
        /* else */
        fprintf(stderr, "fetchWebPage failed with error code %03d\n", result);
        sleep(retryDelay);  /* wait before trying again */
    }

(Note the empty `for` loop header means to loop forever; `while(1)` also works.)

4.8 Functions
-------------

A **function**, **procedure**, or **subroutine** encapsulates some complex computation as a single operation. Typically, when we **call** a function, we pass as **arguments** all the information this function needs, and any effect it has will be reflected in either its **return value** or (in some cases) in changes to values pointed to by the arguments. Inside the function, the arguments are copied into local variables, which can be used just like any other local variable—they can even be assigned to without affecting the original argument.

### 4.8.1 Function definitions

A typical function definition looks like this:

    /* Returns the square of the distance between two points separated by 
       dx in the x direction and dy in the y direction. */
    int
    distSquared(int dx, int dy)
    {
        return dx*dx + dy*dy;
    }

[examples/functions/distSquaredNoHeader.c](examples/functions/distSquaredNoHeader.c)

The part outside the braces is called the **function declaration**; the braces and their contents is the **function body**.

Like most complex declarations in C, once you delete the type names the declaration looks like how the function is used: the name of the function comes before the parentheses and the arguments inside. The `int`s scattered about specify the type of the return value of the function (before the function name) and of the parameters (inside the parentheses after the function name); these are used by the compiler to determine how to pass values in and out of the function and (usually for more complex types, since numerical types will often convert automatically) to detect type mismatches.

If you want to define a function that doesn’t return anything, declare its return type as `void`. You should also declare a parameter list of `void` if the function takes no arguments.

    /* Prints "hi" to stdout */
    void
    helloWorld(void)
    {
        puts("hi");
    }

[examples/functions/helloWorld.c](examples/functions/helloWorld.c)

It is not strictly speaking an error to omit the second `void` here. Putting `void` in for the parameters tells the compiler to enforce that no arguments are passed in. If we had instead declared `helloWorld` as

    /* Prints "hi" to stdout */
    void
    helloWorld()    /* DANGER! */
    {
        puts("hi");
    }

it would be possible to call it as

        helloWorld("this is a bogus argument");

without causing an error. The reason is that a function declaration with no arguments means that the function can take an unspecified number of arguments, and it’s up to the user to make sure they pass in the right ones. There are good historical reasons for what may seem like obvious lack of sense in the design of the language here, and fixing this bug would break most C code written before 1989. But you shouldn’t ever write a function declaration with an empty argument list, since you want the compiler to know when something goes wrong.

### 4.8.2 When to write a function

As with any kind of abstraction, there are two goals to making a function:

*   **Encapsulation:** If you have some task to carry out that is simple do describe from the outside but messy to understand from the inside, wrapping it in a function lets somebody carry out this task without having to know the details. This is also useful if you want to change the implementation later.
*   **Code re-use:** If you find yourself writing the same lines of code in several places (or worse, are tempted to copy a block of code to several places), you should probably put this code in a function (or perhaps more than one function, if there is no succinct way to describe what this block of code is doing).

Both of these goals may be trumped by the goal of making your code understandable. If you can’t describe what a function is doing in a single, simple sentence, this is a sign that maybe you need to restructure your code. Having a function that does more than one thing (or does different thing depending on its arguments) is likely to lead to confusion. So, for example, this is not a good function definition:

    /*** ### UGLY CODE AHEAD ### ***/
    
    /*
     * If getMaximum is true, return maximum of x and y,
     * else return minimum.
     */
    int
    computeMaximumOrMinimum(int x, int y, int getMaximum)
    {
        if(x > y) {
            if(getMaximum) {
                return x;
            } else {
                return y;
            }
        } else {
            if(getMaximum) {
                return y;
            } else {
                return x;
            }
        }
    }

Better would be to write two functions:

    /* return the maximum of x and y */
    int
    maximum(int x, int y)
    {
        if(x > y) {
            return x;
        } else {
            return y;
        }
    }
    
    /* return the minimum of x and y */
    int
    minimum(int x, int y)
    {
        if(x < y) {
            return x;
        } else {
            return y;
        }
    }

At the same time, it’s possible for a function to be too simple. Suppose I write the function

    /* print x to stdout followed by a newline */
    void
    printIntWithNewline(int x)
    {
        printf("%d\n", x);
    }

It’s pretty clear from the name what this function does. But since anybody who has been using C for a while has seen `printf("%d\n", ...)` over and over again, it’s usually more clear to expand out the definition:

        printIntWithNewline(2+5);   /* this could do anything */
        printf("%d\n", 2+7);        /* this does exactly what it says */

As with all caveats, this caveat comes with its own caveat: what might justify a function like this is if you want to be able to do some kind of specialized formatting that should be consistent for all values of a particular form. So you might write a `printDistance` function like the above as a stub for a fancier function that might use different units at different scales or something.

A similar issue will come up with [non-syntactic macros](#nonSyntacticMacros), which also tend to fail the “does this make my code more or less understandable” test. Usually it is a bad idea to try to replace common C idioms.

### 4.8.3 Calling a function

A function call consists of the function followed by its arguments (if any) inside parentheses, separated by comments. For a function with no arguments, call it with nothing between the parentheses. A function call that returns a value can be used in an expression just like a variable. A call to a `void` function can only be used as an expression by itself:

        totalDistance += distSquared(x1 - x2, y1 - y2);
        helloWorld();
        greetings += helloWorld();  /* ERROR */

### 4.8.4 The return statement

To return a value from a function, write a `return` statement, e.g.

        return 172;

The argument to `return` can be any expression. Unlike the expression in, say, an `if` statement, you do not need to wrap it in parentheses. If a function is declared `void`, you can do a `return` with no expression, or just let control reach the end of the function.

Executing a `return` statement immediately terminates the function. This can be used like `break` to get out of loops early.

    /* returns 1 if n is prime, 0 otherwise */
    int
    isPrime(int n)
    {
        int i;
    
        if (n < 2) return 0;   /* special case for 0, 1, negative n */
     
        for(i = 2; i < n; i++) {
            if (n % i == 0) {
                /* found a factor */
                return 0;
            }
        }
    
        /* no factors */
        return 1;
    }

[examples/functions/isPrime.c](examples/functions/isPrime.c)

### 4.8.5 Function declarations and modules

By default, functions have **global scope**: they can be used anywhere in your program, even in other files. If a file doesn’t contain a declaration for a function `someFunc` before it is used, the compiler will assume that it is declared like `int someFunc()` (i.e., return type `int` and unknown arguments). This can produce infuriating complaints later when the compiler hits the real declaration and insists that your function `someFunc` should be returning an `int` and you are a bonehead for declaring it otherwise.

The solution to such insulting compiler behavior errors is to either (a) move the function declaration before any functions that use it; or (b) put in a declaration without a body before any functions that use it, in addition to the declaration that appears in the function definition. (Note that this violates the **no separate but equal** rule, but the compiler should tell you when you make a mistake.) Option (b) is generally preferred, and is the only option when the function is used in a different file.

To make sure that all declarations of a function are consistent, the usual practice is to put them in an include file. For example, if `distSquared` is used in a lot of places, we might put it in its own file `distSquared.c`:

    #include "distSquared.h"
    
    int
    distSquared(int dx, int dy)
    {
        return dx*dx + dy*dy;
    }

[examples/functions/distSquared.c](examples/functions/distSquared.c)

The file `distSquared.c` above uses `#include` to include a copy of the following header file `distSquared.h`:

    /* Returns the square of the distance between two points separated by 
       dx in the x direction and dy in the y direction. */
    int distSquared(int dx, int dy);

[examples/functions/distSquared.h](examples/functions/distSquared.h)

Note that the declaration in `distSquared.h` doesn’t have a body. Instead, it’s terminated by a semicolon, like a variable declaration. It’s also worth noting that we moved the documenting comment to `distSquared.h`: the idea is that `distSquared.h` is the public face of this (very small one-function) module, and so the explanation of how to use the function should be there.

The reason `distSquared.c` includes `distSquared.h` is to get the compiler to verify that the declarations in the two files match. But to use the `distSquared` function, we also put `#include "distSquared.h"` at the top of the file that uses it:

    #include "distSquared.h"
    
    #define THRESHOLD (100)
    
    int
    tooClose(int x1, int y1, int x2, int y2)
    {
        return distSquared(x1 - x2, y1 - y2) < THRESHOLD;
    }

[examples/functions/tooClose.c](examples/functions/tooClose.c)

The `#include` on line 1 uses double quotes instead of angle brackets; this tells the compiler to look for `distSquared.h` in the current directory instead of the system include directory (typically `/usr/include`).

### 4.8.6 Static functions

By default, all functions are global; they can be used in any file of your program whether or not a declaration appears in a header file. To restrict access to the current file, declare a function `static`, like this:

    static void
    helloHelper(void)
    {
        puts("hi!");
    }
    
    void
    hello(int repetitions)
    {
        int i;
    
        for(i = 0; i < repetitions; i++) {
            helloHelper();
        }
    }

[examples/functions/staticHello.c](examples/functions/staticHello.c)

The function `hello` will be visible everywhere. The function `helloHelper` will only be visible in the current file.

It’s generally good practice to declare a function static unless you intend to make it available, since not doing so can cause **namespace conflicts**, where the presence of two functions with the same name either prevent the program from linking or—even worse—cause the wrong function to be called. The latter can happen with library functions, since C allows the programmer to override library functions by defining a new function with the same name. Early on in my career as a C programmer, I once had a program fail in a spectacularly incomprehensible way because I’d written a `select` function without realizing that `select` is a core library function in Unix.

### 4.8.7 Local variables

A function may contain definitions of **local variables**, which are visible only inside the function and which survive only until the function returns. These may be declared at the start of any block (group of statements enclosed by braces), but it is conventional to declare all of them at the outermost block of the function.

    /* Given n, compute n! = 1*2*...*n */
    /* Warning: will overflow on 32-bit machines if n > 12 */
    int
    factorial(int n)
    {
        int i;
        int product;
    
        if(n < 2) return n;
        /* else */
    
        product = 1;
    
        for(i = 2; i <= n; i++) {
            product *= i;
        }
    
        return product;
    }

[examples/functions/factorial.c](examples/functions/factorial.c)

### 4.8.8 Mechanics of function calls

Several things happen under the hood when a function is called. Since a function can be called from several different places, the CPU needs to store its previous state to know where to go back. It also needs to allocate space for function arguments and local variables.

Some of this information will be stored in **registers**, memory locations built into the CPU itself, but most will go on the **stack**, a region of memory that on typical machines grows downward, even though the most recent additions to the stack are called the “top” of the stack. The location of the top of the stack is stored in the CPU in a special register called the **stack pointer**.

So a typical function call looks like this internally:

1.  The current **instruction pointer** or **program counter** value, which gives the address of the next line of machine code to be executed, is pushed onto the stack.
2.  Any arguments to the function are copied either into specially designated registers or onto new locations on the stack. The exact rules for how to do this vary from one CPU architecture to the next, but a typical convention might be that the first few arguments are copied into registers and the rest (if any) go on the stack.
3.  The instruction pointer is set to the first instruction in the code for the function.
4.  The code for the function allocates additional space on the stack to hold its local variables (if any) and to save copies of the values of any registers it wants to use (so that it can restore their contents before returning to its caller).
5.  The function body is executed until it hits a `return` statement.
6.  Returning from the function is the reverse of invoking it: any saved registers are restored from the stack, the return value is copied to a standard register, and the values of the instruction pointer and stack pointer are restored to what they were before the function call.

From the programmer’s perspective, the important point is that both the arguments and the local variables inside a function are stored in freshly-allocated locations that are thrown away after the function exits. So after a function call the state of the CPU is restored to its previous state, except for the return value. Any arguments that are passed to a function are passed as copies, so changing the values of the function arguments inside the function has no effect on the caller. Any information stored in local variables is lost.

Under very rare circumstances, it may be useful to have a variable local to a function that persists from one function call to the next. You can do so by declaring the variable `static`. For example, here is a function that counts how many times it has been called:

    /* return the number of times the function has been called */
    int
    counter(void)
    {
        static count = 0;
    
        return ++count;
    }

[examples/functions/staticCounter.c](examples/functions/staticCounter.c)

Static local variables are stored outside the stack with global variables, and have unbounded extent. But they are only visible inside the function that declares them. This makes them slightly less dangerous than global variables—there is no fear that some foolish bit of code elsewhere will quietly change their value—but it is still the case that they usually aren’t what you want. It is also likely that operations on static variables will be slightly slower than operations on ordinary (“automatic”) variables, since making them persistent means that they have to be stored in (slow) main memory instead of (fast) registers.

4.9 Pointers
------------

Pointers provided an abstraction for memory addresses. A pointer value specifies a location, but also has a type associated with it at compile time that allows the compiler to keep track of what is stored at that memory address. C uses pointers for a variety of tasks that are handled more abstractly in other programming languages, like returning extra values from functions or constructing arrays.

### 4.9.1 Memory and addresses

Memory in a typical modern computer is divided into two classes: a small number of **registers**, which live on the CPU chip and perform specialized functions like keeping track of the location of the next machine code instruction to execute or the current stack frame, and **main memory**, which (mostly) lives outside the CPU chip and which stores the code and data of a running program. When the CPU wants to fetch a value from a particular location in main memory, it must supply an address: a 32-bit or 64-bit unsigned integer on typical current architectures, referring to one of up to 232 or 264 distinct 8-bit locations in the memory. These integers can be manipulated like any other integer; in C, they appear as **pointers**, a family of types that can be passed as arguments, stored in variables, returned from functions, etc.

### 4.9.2 Pointer variables

A **pointer variable** is a variable that holds a pointer, just like an `int` variable is a variable that holds an `int`.

#### 4.9.2.1 Declaring a pointer variable

The convention is C is that the declaration of a complex type looks like its use. To declare a pointer-valued variable, write a declaration for the thing that it points to, but include a `*` before the variable name:

        int *pointerToInt;
        double *pointerToDouble;
        char *pointerToChar;
        char **pointerToPointerToChar;

These declarations create four pointer variables, named `pointerToInt`, `pointerToDouble`, `pointerToChar`, and `pointerToPointerToChar`. On a typical 64-bit machine, each will be allocated 8 bytes, enough to represent an address in memory.

The contents of these variables are initially arbitrary. To use them safely, you will need to compute the address of something and assign it to the variable.

#### 4.9.2.2 Assigning to pointer variables

Declaring a pointer-valued variable allocates space to hold the pointer but _not_ to hold anything it points to. Like any other variable in C, a pointer-valued variable will initially contain garbage—in this case, the address of a location that might or might not contain something important. To initialize a pointer variable, you have to assign to it the address of something that already exists. Typically this is done using the `&` (**address-of**) operator:

        int n;              /* an int variable */
        int *p;             /* a pointer to an int */
    
        p = &n;             /* p now points to n */

#### 4.9.2.3 Using a pointer

Pointer variables can be used in two ways. The simplest way is to get their value as with any other variable. This value will be an address, which can be stored in another pointer variable of the same type.

        int n;              /* an int variable */
        int *p;             /* a pointer to an int */
        int *q;             /* another pointer to an int */
    
        p = &n;             /* p now points to n */
        q = p;              /* q now points to n as well */

But more often you will want to work on the value stored at the location pointed to. You can do this by using the `*` (**dereference**) operator, which acts as an inverse of the address-of operator:

        int n;              /* an int variable */
        int *p;             /* a pointer to an int */
    
        p = &n;             /* p now points to n */
    
        *p = 2;             /* sets n to 2 */
        *p = *p + *p;       /* sets n to 4 */

The `*` operator binds very tightly, so you can usually use `*p` anywhere you could use the variable it points to without worrying about parentheses. However, a few operators, such as the `--` and `++` operators and the `.` operator used to unpack [structs](#structs), bind tighter. These require parentheses if you want the `*` to take precedence.

        (*p)++;             /* increment the value pointed to by p */
        *p++;               /* WARNING: increments p itself */

#### 4.9.2.4 Printing pointers

You can print a pointer value using `printf` with the `%p` format specifier. To do so, you should convert the pointer to the [generic pointer type](#voidPointers) `void *` first using a cast, although on machines that don’t have different representations for different pointer types, this may not be necessary.

Here is a short program that prints out some pointer values:

    #include <stdio.h>
    #include <stdlib.h>
    
    int G = 0;   /* a global variable, stored in BSS segment */
    
    int
    main(int argc, char **argv)
    {
        static int s;  /* static local variable, stored in BSS segment */
        int a;         /* automatic variable, stored on stack */
        int *p;        /* pointer variable for malloc below */
    
        /* obtain a block big enough for one int from the heap */
        p = malloc(sizeof(int));
    
        printf("&G   = %p\n", (void *) &G);
        printf("&s   = %p\n", (void *) &s);
        printf("&a   = %p\n", (void *) &a);
        printf("&p   = %p\n", (void *) &p);
        printf("p    = %p\n", (void *) p);
        printf("main = %p\n", (void *) main);
    
        free(p);
    
        return 0;
    }

[examples/pointers/lookingAtPointers.c](examples/pointers/lookingAtPointers.c)

When I run this on a Mac OS X 10.6 machine after compiling with `gcc`, the output is:

    &G   = 0x100001078
    &s   = 0x10000107c
    &a   = 0x7fff5fbff2bc
    &p   = 0x7fff5fbff2b0
    p    = 0x100100080
    main = 0x100000e18

The interesting thing here is that we can see how the compiler chooses to allocate space for variables based on their storage classes. The global variable `G` and the static local variable `s` both persist between function calls, so they get placed in the BSS segment (see [.bss](http://en.wikipedia.org/wiki/.bss "WikiPedia")) that starts somewhere around `0x100000000`, typically after the code segment containing the actual code of the program. Local variables `a` and `p` are allocated on the stack, which grows down from somewhere near the top of the address space. The block returned from `malloc` that `p` points to is allocated off the heap, a region of memory that may also grow over time and starts after the BSS segment. Finally, `main` appears at 0x100000e18; this is in the code segment, which is a bit lower in memory than all the global variables.

### 4.9.3 The null pointer

The special value `0`, known as the **null pointer**, may be assigned to a pointer of any type. It may or may not be represented by the actual address `0`, but it will act like `0` in all contexts where an integer value is expected (e.g., it has the value false in an `if` or `while` statement). Null pointers are often used to indicate missing data or failed functions. Attempting to dereference a null pointer can have catastrophic effects, so it’s important to be aware of when you might be supplied with one.

### 4.9.4 Pointers and functions

A simple application of pointers is to get around C’s limit on having only one return value from a function. Because C arguments are copied, assigning a value to an argument inside a function has no effect on the outside. So the `doubler` function below doesn’t do much:

    #include <stdio.h>
    
    /* doesn't work */
    void
    doubler(int x)
    {
        x *= 2;
    }
    
    int
    main(int argc, char **argv)
    {
        int y;
    
        y = 1;
    
        doubler(y);                 /* no effect on y */
    
        printf("%d\n", y);          /* prints 1 */
    
        return 0;
    }

[examples/pointers/badDoubler.c](examples/pointers/badDoubler.c)

However, if instead of passing the value of `y` into `doubler` we pass a pointer to `y`, then the `doubler` function can reach out of its own stack frame to manipulate `y` itself:

    #include <stdio.h>
    
    void
    doubler(int *x)
    {
        *x *= 2;
    }
    
    int
    main(int argc, char **argv)
    {
        int y;
    
        y = 1;
    
        doubler(&y);                /* sets y to 2 */
    
        printf("%d\n", y);          /* prints 2 */
    
        return 0;
    }

[examples/pointers/goodDoubler.c](examples/pointers/goodDoubler.c)

Generally, if you pass the value of a variable into a function (with no `&`), you can be assured that the function can’t modify your original variable. When you pass a pointer, you should assume that the function can and will change the variable’s value. If you want to write a function that takes a pointer argument but promises not to modify the target of the pointer, use `const`, like this:

    void
    printPointerTarget(const int *p)
    {
        printf("%d\n", *p);
    }

The `const` qualifier tells the compiler that the target of the pointer shouldn’t be modified. This will cause it to return an error if you try to assign to it anyway:

    void
    printPointerTarget(const int *p)
    {
        *p = 5;  /* produces compile-time error */
        printf("%d\n", *p);
    }

Passing `const` pointers is mostly used when passing large structures to functions, where copying a 32-bit pointer is cheaper than copying the thing it points to.

If you really want to modify the target anyway, C lets you “cast away `const`”:

    void
    printPointerTarget(const int *p)
    {
        *((int *) p) = 5;  /* no compile-time error */
        printf("%d\n", *p);
    }

There is usually no good reason to do this. The one exception might be if the target of the pointer represents an [abstract data type](#abstractDataTypes), and you want to modify its representation during some operation to optimize things somehow in a way that will not be visible outside the abstraction barrier, making it appear to leave the target constant.

Note that while it is safe to pass pointers down into functions, it is very dangerous to pass pointers up. The reason is that the space used to hold any local variable of the function will be reclaimed when the function exits, but the pointer will still point to the same location, _even though something else may now be stored there_. So this function is very dangerous:

    int *
    dangerous(void)
    {
        int n;
    
        return &n;          /* NO! */
    }
    
    ...
    
        *dangerous() = 12;  /* writes 12 to some unknown location */

An exception is when you can guarantee that the location pointed to will survive even after the function exits, e.g. when the location is dynamically allocated using `malloc` (see below) or when the local variable is declared `static`:

    int *
    returnStatic(void)
    {
        static int n;
    
        return &n;
    }
    
    ...
    
        *returnStatic() = 12;       /* writes 12 to the hidden static variable */

Usually returning a pointer to a `static` local variable is not good practice, since the point of making a variable local is to keep outsiders from getting at it. If you find yourself tempted to do this, a better approach is to allocate a new block using `malloc` (see below) and return a pointer to that. The downside of the `malloc` method is that the caller has to promise to call `free` on the block later, or you will get a storage leak.

### 4.9.5 Pointer arithmetic and arrays

Because pointers are just numerical values, one can do arithmetic on them. Specifically, it is permitted to

*   Add an integer to a pointer or subtract an integer from a pointer. The effect of `p+n` where `p` is a pointer and `n` is an integer is to compute the address equal to `p` plus `n` times the size of whatever `p` points to (this is why `int *` pointers and `char *` pointers aren’t the same).
*   Subtract one pointer from another. The two pointers must have the same type (e.g. both `int *` or both `char *`). The result is a signed integer value of type [`ptrdiff_t`](#sizeTypes), equal to the numerical difference between the addresses divided by the size of the objects pointed to.
*   Compare two pointers using `==`, `!=`, `<`, `>`, `<=`, or `>=`.
*   Increment or decrement a pointer using `++` or `--`.

#### 4.9.5.1 Arrays

The main application of pointer arithmetic in C is in **arrays**. An array is a block of memory that holds one or more objects of a given type. It is declared by giving the type of object the array holds followed by the array name and the size in square brackets:

        int a[50];          /* array of 50 ints */
        char *cp[100];      /* array of 100 pointers to char */

Declaring an array allocates enough space to hold the specified number of objects (e.g. 200 bytes for `a` above and 400 for `cp`—note that a `char *` is an address, so it is much bigger than a `char`). The number inside the square brackets must be a constant whose value can be determined at compile time.

The array name acts like a constant pointer to the zeroth element of the array. It is thus possible to set or read the zeroth element using `*a`. But because the array name is constant, you can’t assign to it:

       1     *a = 12;            /* sets zeroth element to 12 */
       2 
       3     a = &n;             /* #### DOESN'T WORK #### */

More common is to use square brackets to refer to a particular element of the array. The expression `a[n]` is defined to be equivalent to `*(a+n)`; the **index** `n` (an integer) is added to the base of the array (a pointer), to get to the location of the `n`\-th element of `a`. The implicit `*` then dereferences this location so that you can read its value (in a normal expression) or assign to it (on the left-hand side of an assignment operator). The effect is to allow you to use `a[n]` just as you would any other variable of type `int` (or whatever type `a` was declared as).

Note that C doesn’t do any sort of bounds checking. Given the declaration `int a[50];`, only indices from `a[0]` to `a[49]` can be used safely. However, the compiler will not blink at `a[-12]` or `a[10000]`. If you read from such a location you will get garbage data; if you write to it, you will overwrite god-knows-what, possibly trashing some other variable somewhere else in your program or some critical part of the stack (like the location to jump to when you return from a function). It is up to you as a programmer to avoid such **buffer overruns**, which can lead to very mysterious (and in the case of code that gets input from a network, security-damaging) bugs. The [valgrind](#valgrind) program can help detect such overruns in some cases.

Another curious feature of the definition of `a[n]` as identical to `*(a+n)` is that it doesn’t actually matter which of the array name or the index goes inside the braces. So all of `a[0]`, `*a`, and `0[a]` refer to the zeroth entry in `a`. Unless you are deliberately trying to obfuscate your code, it’s best to write what you mean.

#### 4.9.5.2 Arrays and functions

Because array names act like pointers, they can be passed into functions that expect pointers as their arguments. For example, here is a function that computes the sum of all the values in an array `a` of size `n`:

    /* compute the sum of the first n elements of array a */
    int
    sumArray(int n, const int *a)
    {
        int i;
        int sum;
    
        sum = 0;
        for(i = 0; i < n; i++) {
            sum += a[i];
        }
    
        return sum;
    }

[examples/pointers/sumArray.c](examples/pointers/sumArray.c)

Note the use of `const` to promise that `sumArray` won’t modify the contents of `a`.

Another way to write the function header is to declare `a` as an array of unknown size:

    /* return the sum of the values in a, an array of size n */
    int
    sumArray(int n, const int a[])
    {
        ...
    }

This has _exactly_ the same meaning to the compiler as the previous definition. Even though normally the declarations `int a[10]` and `int *a` mean very different things (the first one allocates space to hold 10 `int`s, and prevents assigning a new value to `a`), in a function argument `int a[]` is just [syntactic sugar](http://en.wikipedia.org/wiki/Syntactic_sugar) for `int *a`. You can even modify what `a` points to inside `sumArray` by assigning to it. This will allow you to do things that you usually don’t want to do, like write this hideous routine:

    /* return the sum of the first n values in a */
    int
    sumArray(int n, const int a[])
    {
        const int *an;      /* pointer to first element not in a */
        int sum;
    
        sum = 0;
        an = a+n;
    
        while(a < an) {
            sum += *a++;
        }
    
        return sum;
    }

#### 4.9.5.3 Multidimensional arrays

Arrays can themselves be members of arrays. The result is a multidimensional array, where a value in row `i` and column `j` is accessed by `a[i][j]`.

There are actually two different ways to do this that both support the `a[i][j]` syntax. With [standard C multidimensional arrays](#multidimensionalStandard), the array is an array of one-dimensional arrays, each of which has the same fixed size. With an [array of pointers](#arrayOfPointersToRows), the array is an array of pointers, each of which points to the first element of a one-dimensional array. The standard approach is simpler to set up and avoids some extra time and space complexity, but it breaks down for very large arrays or when the rows of the array may have different lengths. We’ll describe how to do both, as well as a third option that [represents a two-dimensional array directly as a one-dimensional array](#packedTwoDimensionalArray), at the cost of losing the standard `a[i][j]` lookup syntax.

##### 4.9.5.3.1 Using built-in C arrays

Declaration is similar to one-dimensional arrays:

        int a[3][6];    /* declares an array of 3 rows of 6 ints each */

This declaration produces an array of 18 `int` values, packed contiguously in memory. The interpretation is that `a` is an array of 3 objects, each of which is an array of 6 `int`s.

If we imagine the array to contain increasing values like this:

     0  1  2  3  4  5
     6  7  8  9 10 11
    12 13 14 15 16 17

the actual positions in memory will look like this:

     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
     ^                 ^                 ^
    a[0]              a[1]              a[2]

To look up a value, we do the usual array-indexing magic. Suppose we want to find `a[1][4]`. The name `a` acts as a pointer to the base of the array.The name `a[1]` says to skip ahead 1 times the size of the things pointed to by `a`, which are arrays of 6 `int`s each, for a total size of 24 bytes assuming 4-byte `int`s. For `a[1][4]`, we start at `a[1]` and move forward 4 times the size of the thing pointed to by `a[1]`, which is an `int`; this puts us 24+16 bytes from `a`, the position of 10 in the picture above.

It’s useful to understand what is happening in this example, and for small arrays of fixed size there is no particular reason not to use C’s built-in arrays, but as soon as you start dealing with large arrays or arrays whose size is not fixed, you are better off doing something else. (This is true even if you use C99-style [variable-length arrays](#variableLengthArrays).) Two possible approaches that you could try are [using an malloc’d array of pointers to malloc’d rows](#arrayOfPointersToRows), which has the advantage of preserving the `a[i][j]` syntax; and [packing a two-dimensional array into a malloc’d one-dimensonal array](#packedTwoDimensionalArray), which has the advantage of preserving contiguity. Both approaches are described below.

##### 4.9.5.3.2 Using an array of pointers to rows

Here we allocate each row separately using `malloc` and building a master list of pointers to rows, of type `int **`. The downside of this approach is that the array is no longer contiguous (which may affect cache performance) and it requires reading a pointer to find the location of a particular value, instead of just doing address arithmetic starting from the base address of the array. But elements can still be accessed using the `a[i][j]` syntax.

The naive way to do this is to allocate each row with a separate call to `malloc`. But since we know the total size of all of the rows, we can save both time and space by allocating one giant block and partitioning this block into rows ourselves. This may also help with cache performance since the array contents are all stored in one place, although we still have to follow a row pointer.

Note this can work even if the rows have different lengths (for example, if each is a null-terminated string), as long as we are careful to add up the lengths correctly and set the pointers to the right places.

Two examples of this approach are given below. The first builds a two-dimensional array of `int`s for any given number of rows and columns, while the second copies a collection of null-terminated strings into a single `malloc`’d block.

    /* Demo program for malloc'd two-dimensional arrays */
    
    #include <stdio.h>
    #include <stdlib.h>
    
    /* frees a 2d array created by malloc2d */
    void
    free2d(void **a)
    {
        /* free the rows */
        free(a[0]);
    
        /* then free array of pointers */
        free(a);
    }
    
    /* returns a two-dimensional array with numRows rows and 
     * rowSize bytes per row, or 0 on allocation failure.
     * The caller is responsible for freeing the result with free2d. */
    void **
    malloc2d(size_t numRows, size_t rowSize)
    {
        void **a;
        size_t i;
    
        /* a is an array of void * pointers that point to the rows */
        a = malloc(sizeof(void *) * numRows);
        if(a == 0) {
            /* malloc failed */
            return 0;
        }
    
        /* now allocate the actual rows */
        /* the trick here is that we only allocate one big block */
        a[0] = malloc(rowSize * numRows);
        if(a[0] == 0) {
            free(a);
            return 0;
        }
    
        // fill in remaining row pointers
        for(i = 1; i < numRows; i++) {
            // compute offset to start of row i by hand
            a[i] = a[0] + rowSize * i;
        }
    
        return a;
    }
    
    int
    main(int argc, char **argv)
    {
        int rows;
        int cols;
        int **a;
        int i;
        int j;
    
        if(argc != 3) {
            fprintf(stderr, "Usage: %s rows cols\n", argv[0]);
            return 1;
        }
        /* else */
    
        rows = atoi(argv[1]);
        cols = atoi(argv[2]);
    
        /* note that void ** is not converted automatically,
         * so we need an explicit cast */
        a = (int **) malloc2d(rows, cols * sizeof(int));
        if(a == 0) {
            fprintf(stderr, "malloc2d failed, exiting\n");
            return 2;
        }
    
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                a[i][j] = i - j;
            }
        }
    
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                printf("%4d", a[i][j]);
            }
            putchar('\n');
        }
    
        free2d((void **) a);                        /* always clean up */
    
        return 0;
    }

[examples/pointers/malloc2d.c](examples/pointers/malloc2d.c)

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    // given n pointers to strings, pack copies of them
    // into a single malloc'd block that can be accessed 
    // using bracket syntax
    char **
    packStrings(size_t n, char *s[])
    {
      size_t length = 0;
      
      // compute total length including nulls
      for(size_t i = 0; i < n; i++) {
        length += strlen(s[i]) + 1;
      }
      
      // allocate a block big enough for pointers and strings
      char **s2 = malloc(sizeof(char *) * n + length);
      
      // this is a pointer to where the strings are copied
      // after the n pointers
      char *top = (char *) (s2 + n);
      
      // copy the strings and fill in the pointer array
      for(size_t i = 0; i < n; i++) {
        strcpy(top, s[i]);
        s2[i] = top;
        top += strlen(s[i]) + 1;
      }
      
      return s2;
    }
    
    void
    freePackedStrings(char **s)
    {
        free(s);
    }
    
    int
    main(int argc, char **argv)
    {
        // pack argv, then print it out from the copied version
        char **argv2 = packStrings(argc, argv);
    
        for(int i = 0; i < argc; i++) {
            puts(argv2[i]);
        }
    
        freePackedStrings(argv2);
    
        return 0;
    }

[examples/pointers/packStrings.c](examples/pointers/packStrings.c)

##### 4.9.5.3.3 Using a one-dimensional array

A third approach is to store a two-dimensional array in a one-dimensional array, and do the indexing arithmetic ourselves. Since this requires keeping track of the dimensions of the array as well as the contents, it helps to be able to wrap up these values in a `struct` (see [Structs](#structs)), and possibly even hide the details of the construction behind an [abstract data type](#abstractDataTypes). Typically we will provide operations to create an array with given dimensions, to destroy an array (freeing any space we malloc’d), and to obtain a pointer to a particular location in an array, which we can then use to operate on that location.

The advantages of this approach are that the contents of the array are packed contiguously and that address lookup doesn’t require following multiple pointers, which becomes particularly helpful if we generalize to more than two dimensions. We can also enforce bounds checking for safety (although at the cost of some time). The main disadvantage is that we lose access to the `a[i][j]` syntax.

An example of a simple implementation of a two-dimensional array is given below.

    /* Demo program for packed two-dimensional arrays */
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    
    struct flat2d {
        size_t rows;  // number of rows
        size_t cols;  // number of columns
        int data[];   // data, stored at end of struct
    };
    
    // malloc and return flat2d of given dimensions
    // array is not initialized!
    struct flat2d *
    flat2dCreate(size_t rows, size_t cols)
    {
        struct flat2d *a;
    
        a = malloc(sizeof(struct flat2d) + sizeof(int) * rows * cols);
    
        assert(a);
    
        a->rows = rows;
        a->cols = cols;
    
        return a;
    }
    
    // free space used by a
    void
    flat2dDestroy(struct flat2d *a)
    {
        free(a);
    }
    
    // return a pointer to a[i][j]
    // or 0 if i or j is out of bounds
    int *
    flat2dRef(struct flat2d *a, size_t i, size_t j)
    {
        if(i >= a->rows || j >= a->cols) {
            return 0;
        } else {
            return &a->data[i * a->cols + j];
        }
    }
    
    int
    main(int argc, char **argv)
    {
        int rows;
        int cols;
        struct flat2d *a;
        int i;
        int j;
    
        if(argc != 3) {
            fprintf(stderr, "Usage: %s rows cols\n", argv[0]);
            return 1;
        }
        /* else */
    
        rows = atoi(argv[1]);
        cols = atoi(argv[2]);
    
        a = flat2dCreate(rows, cols);
    
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                *flat2dRef(a, i, j) = i - j;
            }
        }
    
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                printf("%4d", *flat2dRef(a, i, j));
            }
            putchar('\n');
        }
    
        flat2dDestroy(a);
    
        return 0;
    }

[examples/pointers/flat2d.c](examples/pointers/flat2d.c)

#### 4.9.5.4 Variable-length arrays

C99 adds the feature of **variable-length arrays**, where the size of the array is determined at run-time. These can only appear as local variables in procedures (_automatic variables_) or in argument lists. In the case of variable-length arrays in argument lists, it is also necessary that the length of the array be computable from previous arguments.

For example, we could make the length of the array explicit in our `sumArray` function:

    /* return the sum of the values in a, an array of size n */
    int
    sumArray(int n, const int a[n])
    {
        int i;
        int sum;
    
        sum = 0;
        for(i = 0; i < n; i++) {
            sum += a[i];
        }
    
        return sum;
    }

This doesn’t accomplish much, because the length of the array is not used. However, it does become useful if we have a two-dimensional array, as otherwise there is no way to compute the length of each row:

    int
    sumMatrix(int rows, int cols, const int m[rows][cols])
    {
        int i;
        int j;
        int sum;
    
        sum = 0;
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                sum += a[i][j];
            }
        }
    
        return sum;
    }

Here the fact that each row of `m` is known to be an array of `cols` many `int`s makes the implicit pointer computation in `a[i][j]` actually work. It is considerably more difficult to to this in ANSI C; the simplest approach is to pack `m` into a one-dimensional array and do the address computation explicitly:

    int
    sumMatrix(int rows, int cols, const int a[])
    {
        int i;
        int j;
        int sum;
    
        sum = 0;
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                sum += a[i*cols + j];
            }
        }
    
        return sum;
    }

Variable-length arrays can sometimes be used for run-time storage allocation, as an alternative to `malloc` and `free` (see below). A variable-length array allocated as a local variable will be deallocated when the containing scope (usually a function body, but maybe just a compound statement marked off by braces) exits. One consequence of this is that you can’t return a variable-length array from a function.

Here is an example of code using this feature:

    /* reverse an array in place */
    void
    reverseArray(int n, int a[n])
    {
        /* algorithm: copy to a new array in reverse order */
        /* then copy back */
    
        int i;
        int copy[n];
    
        for(i = 0; i < n; i++) {
            /* the -1 is needed to that a[0] goes to a[n-1] etc. */
            copy[n-i-1] = a[i];
        }
    
        for(i = 0; i < n; i++) {
            a[i] = copy[i];
        }
    }

##### 4.9.5.4.1 Why you shouldn’t use variable-length arrays

While using variable-length arrays can simplify code in some cases, as a general programming practice it is **extremely dangerous**. The reason is that, unlike allocations through `malloc`, variable-length array allocations are typically allocated on the stack (which is often more constrainted than the heap) and have no way of reporting failure. So if there isn’t enough room for your variable-length array, odds are you won’t find out until a segmentation fault occurs somewhere later in your code when you try to use it.

(As an additional annoyance, `gdb` is confused by two-dimensional variable-length arrays.)

Here’s a safer version of the above routine, using `malloc` and `free`.

    /* reverse an array in place */
    void
    reverseArray(int n, int a[n])
    {
        /* algorithm: copy to a new array in reverse order */
        /* then copy back */
    
        int i;
        int *copy;
    
        copy = (int *) malloc(n * sizeof(int));
        assert(copy);  /* or some other error check */
    
        for(i = 0; i < n; i++) {
            /* the -1 is needed to that a[0] goes to a[n-1] etc. */
            copy[n-i-1] = a[i];
        }
    
        for(i = 0; i < n; i++) {
            a[i] = copy[i];
        }
    
        free(copy);
    }

### 4.9.6 Pointers to void

A special pointer type is `void *`, a “pointer to `void`”. Such pointers are declared in the usual way:

        void *nothing;      /* pointer to nothing */

Unlike ordinary pointers, you can’t dereference a `void *` pointer or do arithmetic on it, because the compiler doesn’t know what type it points to. However, you are allowed to use a `void *` as a kind of “raw address” pointer value that you can store arbitrary pointers in. It is permitted to assign to a `void *` variable from an expression of any pointer type; conversely, a `void *` pointer value can be assigned to a pointer variable of any type. An example is the return value of `malloc` or the argument to `free`, both of which are declared as `void *`. (Note that K&R suggests using an explicit cast for the return value of `malloc`. This has since been acknowledged by the authors to be an error, which arose from the need for a cast prior to the standardization of `void *` in ANSI C.)

        int *block;
    
        block = malloc(sizeof(int) * 12);  /* void * converted to int * before assignment */
        free(block);                       /* int * converted to void * before passing to free */

If you need to use a `void *` pointer as a pointer of a particular type in an expression, you can **cast** it to the appropriate type by prefixing it with a type name in parentheses, like this:

        int a[50];          /* typical array of ints */
        void *p;            /* dangerous void pointer */
    
        a[12] = 17;         /* save that valuable 17 */
        p = a;              /* p now holds base address of a */
    
        printf("%d\n", ((int *) p)[12]);  /* get 17 back */

Usually if you have to start writing casts, it’s a sign that you are doing something wrong, and you run the danger of **violating the type system**—say, by tricking the compiler into treating a block of bits that are supposed to be an `int` as four `char`s. But violating the type system like this will be necessary for some applications, because even the weak type system in C turns out to be too restrictive for writing certain kinds of “generic” code that work on values of arbitrary types.

#### 4.9.6.1 Alignment

One issue with casting pointers to and from `void *` is that you may violate the **alignment restrictions** for a particular kind of pointer on some architectures.

Back in the 8-bit era of the 1970s, a single load or store operation would access a single byte of memory, and because some data (`char`s) are still only one byte wide, C pointers retain the ability to address individual bytes. But present-day memory architectures typically have a wider data path, and the CPU may load or store as many as 8 bytes (64 bits) in a single operation. This makes it natural to organize memory into 4-byte or 8-byte words even though addresses still refer to individual bytes. The effect of the memory architecture is that the address of memory words must be **aligned** to a multiple of the word size: so with 4-byte words, the address `0x1037ef44` (a multiple of 4) could refer to a full word, but `0x1037ef45` (one more than a multiple of 4) could only be used to refer to a byte within a word.

What this means for a C program depends on your particular CPU and compiler. If you try to use something like `0x1037ef45` as an `int *`, one of three things might happen:

1.  The CPU might load the 4 bytes starting at this address, using two accesses to memory to piece together the full `int` out of fragments of words. This is done on Intel architectures, but costs performance.
2.  The CPU might quietly zero out the last two bits of the address, loading from `0x1037ef44` even though you asked for `0x1037ef45`. This happens on some other architectures, notably ARM.
3.  The CPU might issue a run-time exception.

All of these outcomes are bad, and the C standard does not specify what happens if you try to dereference a pointer value that does not satisfy the alignment restrictions of its target type. Fortunately, unless you are doing very nasty things with casts, this is unlikely to come up, because any pointer value you will see in a typical program is likely to arise in one of three ways:

1.  By taking the address of some variable. This pointer will be appropriately aligned, because the compiler allocates space for each variable (including fields within `struct`s) with appropriate alignment.
2.  By computing an offset address using pointer arithmetic either explicitly (`p + n`) or implicitly (`p[n]`). In either case, as long as the base pointer is correctly aligned, the computed pointer will also be correctly aligned.
3.  By obtaining a pointer to an allocated block of memory using `malloc` or a similar function. Here `malloc` is designed to always return blocks with the maximum possible required alignment, just to avoid problems when you use the results elsewhere.

On many compilers, you can use `__alignof(`_type_`)` to get the alignment restriction for a particular type. This was formalized in C11 without the underscores: `alignof`. Usually if your code needs to include `__alignof` or `alignof` something has already gone wrong.

The other place where alignment can create issues is that if you make a [`struct`](#structs) with components with different alignment restrictions, you may end up with some empty space. For example, on a machine that enforces 4-byte alignment for `int`s, building a `struct` that contains a `char` and an `int` will give you something bigger than you might expect:

    #include <stdio.h>
    
    struct ci {
        char c;  /* offset 0 */
                 /* 3 unused bytes go here */
        int i;   /* offset 4 */
    };
    
    struct ic {
        int i;   /* offset 0 */
        char c;  /* offset 4 */
                 /* 3 unused bytes go here */
    };
    
    int
    main(int argc, char **argv)
    {
        printf("sizeof(struct ci) == %lu\n", sizeof(struct ci));
        printf("sizeof(struct ic) == %lu\n", sizeof(struct ic));
    
        return 0;
    }

[examples/alignment/structPacking.c](examples/alignment/structPacking.c)

    $ gcc -Wall -o structPacking structPacking.c
    $ ./structPacking
    sizeof(struct ci) == 8
    sizeof(struct ic) == 8

In both cases, the compiler packs in an extra 3 bytes to make the size of the struct a multiple of the worst alignment of any of its components. If it didn’t do this, you would have trouble as soon as you tried to make an array of these things.

### 4.9.7 Run-time storage allocation using `malloc`

C does not generally permit arrays to be declared with variable sizes. C also doesn’t let local variables outlive the function they are declared in. Both features can be awkward if you want to build data structures at run time that have unpredictable (perhaps even changing) sizes and that are intended to persist longer than the functions that create them. To build such structures, the standard C library provides the `malloc` routine, which returns a otherwise-unused block of space of a given size (in bytes).

Unlike local variables that expire when their function returns, you can use this space for whatever you want for as long as you want. When you are done with it, you should call the `free` routine to give it back. The `malloc` and `free` routines together act as brokers for space on the heap, which `malloc` will grow as needed by asking for more space from the operating system.

To use `malloc`, you must include `stdlib.h` at the top of your program. The declaration for `malloc` is

    void *malloc(size_t);

where `size_t` is an integer type (often `unsigned long`). Calling `malloc` with an argument of _n_ allocates and returns a pointer to the start of a block of _n_ bytes if possible. If the system can’t give you the space you asked for (maybe you asked for more space than it has), `malloc` returns a null pointer. It is good practice to test the return value of `malloc` whenever you call it.

Because the return type of `malloc` is `void *`, its return value can be assigned to any variable with a pointer type. Computing the size of the block you need is your responsibility—and you will be punished for any mistakes with difficult-to-diagnose buffer overrun errors—but this task is made slightly easier by the built-in `sizeof` operator that allows you to compute the size in bytes of any particular data type. A typical call to `malloc` might thus look something like this:

    #include <stdlib.h>
    
    /* allocate and return a new integer array with n elements */
    /* calls abort() if there isn't enough space */
    int *
    makeIntArray(int n)
    {
        int *a;
    
        a = malloc(sizeof(int) * n);
    
        if(a == 0) abort();                 /* die on failure */
    
        return a;
    }

[examples/pointers/makeIntArray.c](examples/pointers/makeIntArray.c)

If you don’t want to do the multiplication yourself, or if you want to guarantee that the allocated data is initialized to zero, you can use `calloc` instead of `malloc`. The `calloc` function is also declared in `stdlib.h` and takes two arguments: the number of things to allocate, and the size of each thing. Here’s a version of `makeIntArray` that uses `calloc`.

    #include <stdlib.h>
    
    /* allocate and return a new integer array with n elements */
    /* initializes array to zero */
    /* calls abort() if there isn't enough space */
    int *
    makeIntArray(int n)
    {
        int *a;
    
        a = calloc(n, sizeof(int));
    
        if(a == 0) abort();                 /* die on failure */
    
        return a;
    }

[examples/pointers/calloc.c](examples/pointers/calloc.c)

If you know that you want to initialize your data to zero (which means all zero bytes, which will translate to a zero or null value for typical C data types), `calloc` can be significantly more efficient than `malloc`. The reason is that zero-value memory pages can often be requested from the operating system without actually allocating space for them until they are written, so allocating huge blocks using `calloc` doesn’t take much more time than allocating small ones. If we used `malloc` and then initialized the blocks by hand, we would have to pay both the time cost of filling in all the initial values and the space cost of allocating pages that we might not actually need. So `calloc` is often a better choice in these cases. However, if you are planning on filling in all the data eventually, `calloc` just shifts the cost to the time when you write to the pages, so the difference mostly just affects whether you pay a big cost up front or spread it out over the execution of your program.

Whichever of `malloc` or `calloc` you use, when you are done with a block, you should return its space to the storage allocator using the `free` routine, also defined in `stdlib.h`. If you don’t do this, your program may quickly run out of space. The `free` routine takes a `void *` as its argument and returns nothing. It is good practice to write a matching **destructor** that de-allocates an object for each **constructor** (like `makeIntArray`) that makes one.

    void
    destroyIntArray(int *a)
    {
        free(a);
    }

It is a serious error to do anything at all with a block after it has been `free`d. This is not necessarily because `free` modifies the contents of the block (although it might), but because when you free a block you are granting the storage allocator permission to hand the same block out in response to a future call to `malloc`, and you don’t want to step on whatever other part of your program is now trying to use that space.

It is also possible to grow or shrink a previously allocated block. This is done using the `realloc` function, which is declared as

    void *realloc(void *oldBlock, size_t newSize);

The `realloc` function returns a pointer to the resized block. It may or may not allocate a new block. If there is room, it may leave the old block in place and return its argument. But it may allocate a new block and copy the contents of the old block, so you should assume that the old pointer has been `free`d.

Here’s a typical use of `realloc` to build an array that grows as large as it needs to be:

    /* read numbers from stdin until there aren't any more */
    /* returns an array of all numbers read, or null on error */
    /* returns the count of numbers read in *count */
    int *
    readNumbers(int *count /* RETVAL */)
    {
        int mycount;        /* number of numbers read */
        int size;           /* size of block allocated so far */
        int *a;             /* block */
        int n;              /* number read */
    
        mycount = 0;
        size = 1;
    
        a = malloc(sizeof(int) * size);     /* allocating zero bytes is tricky */
        if(a == 0) return 0;
    
        while(scanf("%d", &n) == 1) {
            /* is there room? */
            while(mycount >= size) {
                /* double the size to avoid calling realloc for every number read */
                size *= 2;
                a = realloc(a, sizeof(int) * size);
                if(a == 0) return 0;
            }
    
            /* put the new number in */
            a[mycount++] = n;
        }
    
        /* now trim off any excess space */
        a = realloc(a, sizeof(int) * mycount);
        /* note: if a == 0 at this point we'll just return it anyway */
    
        /* save out mycount */
    <