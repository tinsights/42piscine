NAME = bsq
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = srcs
INCDIR = includes
OBJDIR = $(SRCDIR)


SRC = map_converter.c write_soln.c bsq.c main.c

.PHONY: clean fclean re

all: *.o
	cc $(CFLAGS) *.o -o $(NAME)

*.o: $(SRC)
	cc -c $(CFLAGS) $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

