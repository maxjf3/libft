NAME = libft.a
$(CC) = cc
MY_SOURCES = ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c

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
