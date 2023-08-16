NAME = bsq
DIR = $(shell pwd)
SOURCES = \
		$(DIR)/main.c \
		$(DIR)/bsq.c \
		$(DIR)/map_converter.c \
		$(DIR)/write_soln.c

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
