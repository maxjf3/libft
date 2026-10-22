NAME = libft.a
$(CC) = cc
MY_SOURCES = ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strchr.c \
				ft_strtrim.c \
				ft_substr.c


MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -g

all: $(MY_OBJECTS)
	@ar crs $(NAME) $(MY_OBJECTS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

debug: $(MY_OBJECTS)
	@cc $(CFLAGS) $(MY_OBJECTS) -o $(NAME) $(DEBUGFLAGS)

clean:
	@rm -f $(MY_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all debug clean re
