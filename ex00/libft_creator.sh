rm -f libft.a
cc -c -Wall -Werror -Wextra ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_swap.c
ar -crs libft.a *.o
rm -f *ft_putchar.o ft_putstr.o ft_strlen.o ft_strcmp.o ft_swap.o