This project has been created as part of the 42 curriculum by mjardin.


**Description:**

The goal of the project is to recreate true functions and functions that didnt exits.

# Instructions:

To compile the libft you can write "Make" in the console.
To use it you have to get libft.a, libft.h and a main.c in your file and include "libft.h" in the files that use the functions of the libft.
Compile the libft.a with your main.c and your other files.
Exemple : cc -Wall -Werror -Wextra main.c libft.a

And now you can use your libft functions in your files.

Descriptions of the functions


|Memory functions|Description|Return value|
|:-------|:---------|:---------|
|ft_memchr| The  memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c.  Both c and the bytes  of  the  memory area pointed to by s are interpreted as unsigned char.|The  memchr() and memrchr() functions return a pointer to the matching byte or NULL if the character does not occur in the given memory area.|
|ft_memcmp|The memcmp() function returns an integer less than, equal  to,  or  greater than  zero  if  the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2. For a nonzero return value, the sign is determined by the sign of the  dif‐ ference between the first pair of bytes (interpreted as unsigned char) that differ in s1 and s2. If n is zero, the return value is zero.| The memcmp() function returns an integer less than, equal  to,  or  greater than  zero  if  the  first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2. For a nonzero return value, the sign is determined by the sign of the  difference between the first pair of bytes (interpreted as unsigned char) that differ in s1 and s2. If n is zero, the return value is zero.|
|ft_memcpy| The  memcpy()  function  copies n bytes from memory area src to memory area dest.  The memory areas must not overlap.  Use memmove(3) if the memory areas do overlap.|The memcpy() function returns a pointer to dest.|
|ft_memmove|The  memmove()  function copies n bytes from memory area src to memory area dest.  The memory areas may overlap: copying  takes  place  as  though  the bytes  in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied  from  the  temporary  array  to dest.|The memmove() function returns a pointer to dest.|
|ft_memset|The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.| The memset() function returns a pointer to the memory area s.|


|String functions|Description|Return value|
|:-------|:---------|:---------|
|ft_strchr|The  strchr()  function  returns  a  pointer to the first occurrence of the character c in the string s. The strrchr() function returns a pointer to  the  last  occurrence  of  the character c in the string s. The  strchrnul() function is like strchr() except that if c is not found in s, then it returns a pointer to the null byte at the end of s, rather  than NULL. Here  "character"  means  "byte";  these functions do not work with wide or multibyte characters.| The strchr() and strrchr() functions return a pointer to the matched  character  or NULL if the character is not found.  The terminating null byte is considered part of the string, so that if c is  specified  as  '\0',  these functions return a pointer to the terminator.|
|ft_strdup|The  strdup()  function returns a pointer to a new string which is a duplicate of the string s.  Memory for the new  string  is  obtained  with  malloc(3), and can be freed with free(3).| On  success,  the  strdup()  function  returns  a pointer to the duplicated string.  It returns NULL if insufficient memory was available,  with  errno set to indicate the cause of the error.|
|ft_striteri||
|ft_strjoin|||
|ft_strlcat| The strlcat() function appends the NUL-terminated string src to the end of
dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.| if strlcat() traverses size characters without finding a NUL, the length of the string is considered to be size and the destination string will not be NUL-terminated (since there was no space for the NUL). This keeps strlcat() from running off the end of a string.  In practice this should not happen (as it means that either size is incorrect or that dst is not a proper “C” string).  The check exists to prevent potential security problems in incorrect code.|
|ft_strlcpy|||
|ft_strlen||||
|ft_strmapi|||
|ft_strncmp|||
|ft_strnstr|||
|ft_strrchr|||
|ft_strtrim|||

**Resources:**
