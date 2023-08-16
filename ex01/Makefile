DIR = $(shell pwd)/srcs

SOURCES = \
	$(DIR)/ft_putchar.c \
	$(DIR)/ft_putstr.c \
	$(DIR)/ft_strcmp.c \
	$(DIR)/ft_strlen.c \
	$(DIR)/ft_swap.c

OBJECTS = $(patsubst $(DIR)/%.c,%.o,$(SOURCES))

CFLAGS = -Wall -Wextra -Werror -I./includes

NAME = bsq

all: $(NAME) 

$(NAME): $(OBJECTS)
	ar -crs $(NAME) $(addprefix $(DIR)/,$(OBJECTS))

$(OBJECTS): $(SOURCES)
	cc $(CFLAGS) -c $< -o $(addprefix $(DIR)/,$@)

clean:
	rm -f $(addprefix $(DIR)/,$(OBJECTS))

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
