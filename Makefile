NAME = libft.a

MY_SOURCES = main.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -g

all: $(MY_OBJECTS)
	@cc $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

debug: $(MY_OBJECTS)
	@cc $(CFLAGS) $(MY_OBJECTS) -o $(NAME) $(DEBUGFLAGS)

clean:
	@rm -f $(MY_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all debug clean re
