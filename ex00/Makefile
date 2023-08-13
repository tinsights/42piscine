NAME = rush-02

SOURCES = rush02.c \
	helpers.c \
	check.c \
	dictionary_check.c \
	print.c \
	print_lines.c 

OBJECTS = $(SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	cc -o $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	cc -c $(SOURCES)

clean: $(OBJECTS)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)