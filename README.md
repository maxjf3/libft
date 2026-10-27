This project has been created as part of the 42 curriculum by mjardin.


# Description

The goal of the project is to recreate true functions and functions that didnt exits and compile it in a lib .a that can be used in others projects.

# Instructions

To compile the libft you can write "Make" in the console.
To use it you have to get libft.a, libft.h and a main.c in your file and include "libft.h" in the files that use the functions of the libft.
Compile the libft.a with your main.c and your other files.
Exemple : cc -Wall -Werror -Wextra main.c libft.a

And now you can use your libft functions in your files.

Descriptions of the functions

| Function | Description | Return Value |
|:---------|:------------|:-------------|
| `ft_atoi` | Converts a string to an integer. | Converted integer (`int`). |
| `ft_bzero` | Sets the first `n` bytes of memory to zero. | `void`. |
| `ft_calloc` | Allocates memory and initializes all bytes to zero. | Pointer to allocated memory, or `NULL` on failure. |
| `ft_isalnum` | Checks whether a character is alphanumeric. | Non-zero if true, `0` otherwise. |
| `ft_isalpha` | Checks whether a character is alphabetic. | Non-zero if true, `0` otherwise. |
| `ft_isascii` | Checks whether a value belongs to the ASCII range (0–127). | Non-zero if true, `0` otherwise. |
| `ft_isdigit` | Checks whether a character is a digit (`0`–`9`). | Non-zero if true, `0` otherwise. |
| `ft_isprint` | Checks whether a character is printable. | Non-zero if true, `0` otherwise. |
| `ft_itoa` | Converts an integer to a string. | Pointer to the allocated string, or `NULL` on failure. |
| `ft_lstadd_back` | Adds a node to the end of a linked list. | `void`. |
| `ft_lstadd_front` | Adds a node to the beginning of a linked list. | `void`. |
| `ft_lstclear` | Deletes and frees all nodes in a linked list. | `void`. |
| `ft_lstdelone` | Deletes and frees a single node. | `void`. |
| `ft_lstiter` | Applies a function to each node's content. | `void`. |
| `ft_lstlast` | Returns the last node of a linked list. | Pointer to the last node, or `NULL` if empty. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. | Pointer to the new list, or `NULL` on failure. |
| `ft_lstnew` | Creates a new linked-list node. | Pointer to the new node, or `NULL` on failure. |
| `ft_lstsize` | Counts the nodes in a linked list. | Number of nodes. |
| `ft_memchr` | Searches for a byte in a memory area. | Pointer to the byte found, or `NULL` if not found. |
| `ft_memcmp` | Compares two memory areas byte by byte. | Negative, zero, or positive integer. |
| `ft_memcpy` | Copies `n` bytes between non-overlapping memory areas. | Pointer to the destination. |
| `ft_memmove` | Copies `n` bytes, allowing overlapping memory areas. | Pointer to the destination. |
| `ft_memset` | Fills a memory area with a specified byte value. | Pointer to the memory area. |
| `ft_putchar_fd` | Writes a character to a file descriptor. | `void`. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. | `void`. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. | `void`. |
| `ft_putstr_fd` | Writes a string to a file descriptor. | `void`. |
| `ft_split` | Splits a string into an array of substrings using a delimiter. | NULL-terminated array of strings, or `NULL` on failure. |
| `ft_strchr` | Finds the first occurrence of a character in a string. | Pointer to the character found, or `NULL` if not found. |
| `ft_strdup` | Duplicates a string into newly allocated memory. | Pointer to the copy, or `NULL` on failure. |
| `ft_striteri` | Applies a function to each character using its index and address. | `void`. |
| `ft_strjoin` | Concatenates two strings into a new string. | Pointer to the new string, or `NULL` on failure. |
| `ft_strlcat` | Appends a string to another within a specified buffer size. | Length of the string it tried to create. |
| `ft_strlcpy` | Copies a string while respecting the destination buffer size. | Length of the source string. |
| `ft_strlen` | Calculates the length of a string, excluding the terminating null character. | String length (`size_t`). |
| `ft_strmapi` | Creates a new string by applying a function to each character and its index. | Pointer to the new string, or `NULL` on failure. |
| `ft_strncmp` | Compares up to `n` characters of two strings. | Negative, zero, or positive integer. |
| `ft_strnstr` | Searches for a substring within a specified length. | Pointer to the substring found, or `NULL` if not found. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. | Pointer to the character found, or `NULL` if not found. |
| `ft_strtrim` | Removes specified characters from the beginning and end of a string. | Pointer to the trimmed string, or `NULL` on failure. |
| `ft_substr` | Extracts a substring starting at a given index. | Pointer to the new string, or `NULL` on failure. |
| `ft_tolower` | Converts an uppercase ASCII letter to lowercase. | Converted character, or original value. |
| `ft_toupper` | Converts a lowercase ASCII letter to uppercase. | Converted character, or original value. |


# Resources

I used a lot Koor.fr in the first section to understand better the goal of the functions. I also used the man for the others functions. I used chatgpt 1 time to understand the function ft_memmove.c and but it didnt gave me the code. I had some help from a stud for ft_itoa.c and i used the francinette, libfttester and Tripouille to tests my functions, Chatgpt also generated me some main to test my functions.
