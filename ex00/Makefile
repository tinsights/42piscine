NAME = rush-02

SOURCES = rush02.c \
	helpers.c \
	check.c \
	dictionary_check.c \
	print.c \
	print_lines.c 

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJECTS): $(SOURCES)
	cc $(CFLAGS) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
