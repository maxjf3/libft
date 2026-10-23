NAME = libft.a
$(CC) = cc
MY_SOURCES = ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isalnum.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strrchr.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_split.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strchr.c \
				ft_substr.c \
				main.c


MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -g -lbsd

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar crs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

debug: $(MY_OBJECTS)
	@$(CC) $(CFLAGS) $(MY_OBJECTS) $(DEBUGFLAGS)

clean:
	@rm -f $(MY_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all debug clean re
