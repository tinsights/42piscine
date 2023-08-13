NAME = rush-02

SOURCES = rush02.c \
	helpers.c \
	check.c \
	dictionary_check.c \
	print.c \
	print_lines.c 

OBJECTS = $(SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJECTS)
	cc -o $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	cc -c $(SOURCES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
