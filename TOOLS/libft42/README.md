# Updated libft_42

This project is a custom implementation of essential C Standard Library functions, built from scratch to strengthen low-level programming skills. It includes functions for string manipulation, memory management, linked lists, I/O, and algorithmic utilities.

***This project will be in constant development, as I will add any useful functions that I write for 42 School projects***

## Features

Standard C library functions rewritten from scratch

Memory management, including dynamic allocation and manipulation

String utilities, mimicking functions from <string.h>

Linked list operations

I/O functions, including printf and get_next_line

Sorting algorithms, like radix sort and list sorting

Compatible with C projects, can be compiled as a static library (libft.a)

Function Categories

### 🔤 String Manipulation (<string.h> equivalents)

ft_strlen - Get string length

ft_strdup - Duplicate a string

ft_strcpy - Copy a string

ft_strncpy - Copy n characters of a string

ft_strcat - Concatenate strings

ft_strlcat - Concatenate with size limit

ft_strchr / ft_strrchr - Locate characters in a string

ft_strstr / ft_strnstr - Find substring in a string

ft_strcmp / ft_strncmp - Compare two strings

ft_substr - Extract a substring

ft_strjoin - Join two strings

ft_strtrim - Trim leading and trailing characters

ft_split - Split a string into an array of words

ft_strmapi - Apply function to each character

### 🧠 Memory Management (<stdlib.h> equivalents)

ft_memset - Fill memory with a constant byte

ft_bzero - Zero out memory

ft_memcpy - Copy memory area

ft_memccpy - Copy memory up to a character

ft_memmove - Move memory block

ft_memchr - Locate byte in memory

ft_memcmp - Compare memory areas

ft_calloc - Allocate and zero out memory

### 🔢 Character and String Classification (<ctype.h> equivalents)

ft_isalpha - Check if character is a letter

ft_isdigit - Check if character is a digit

ft_isalnum - Check if character is alphanumeric

ft_isascii - Check if character is ASCII

ft_isprint - Check if character is printable

ft_toupper / ft_tolower - Convert case

ft_islower / ft_isupper - Check case

ft_isspace - Check if character is whitespace

### 🔗 Linked List Operations

ft_lstnew - Create a new linked list node

ft_lstadd_front - Add node to the front

ft_lstadd_back - Add node to the back

ft_lstsize - Get list size

ft_lstlast - Get last node

ft_lstdelone - Delete one node

ft_lstclear - Delete entire list

ft_lstiter - Iterate over list

ft_lstmap - Apply function to list

### 📥 I/O Functions (<stdio.h> equivalents)

ft_putchar_fd - Print character to file descriptor

ft_putstr_fd - Print string to file descriptor

ft_putendl_fd - Print string with newline

ft_putnbr_fd - Print number to file descriptor

ft_printf - Formatted output function

get_next_line - Read a file line by line

### ⚡ Algorithmic Utilities

ft_list_sorting - Sort a linked list

radix_sorting - Implementation of radix sort


## Installation & Usage

**Building the Library**
Clone the repository and compile the library:

``` sh
make
```

This generates libft.a, which can be linked in your projects.

**Using in Your Project**

To use this library, include the header and link the compiled library:

``` c
#include "libft.h"
```

Compile your program with libft.a:

``` sh
gcc my_program.c -L. -lft -o my_program
```

## License

This project follows the 42 School project guidelines.
