/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:39 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/11 15:42:40 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str, int size);
void	ft_putnbr(int nb);

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str, par->size);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy, par->size);
		write(1, "\n", 1);
		par++;
	}
}

void	ft_putstr(char *str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		write(1, str + i, 1);
}

void	ft_putnbr(int nb)
{
	int		count;
	char	digit[10];

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		nb *= -1;
	}
	if (nb == 0)
		write(1, "0", 1);
	count = 0;
	while (nb > 0)
	{
		digit[9 - count] = nb % 10 + 48;
		nb /= 10;
		count++;
	}
	write(1, digit + 10 - count, count);
}

/**/
#include "ft_stock_str.h"
#include <stdlib.h>

char				*ft_strdup(char *src);
int					ft_strlen(char *str);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			i;

	result = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (NULL);
	result[ac].str = 0;
	i = -1;
	while (++i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = *(av + i);
		result[i].copy = ft_strdup(av[i]);
	}
	return (result);
}

char	*ft_strdup(char *src)
{
	int		idx;
	char	*copy;

	idx = 0;
	while (src[idx])
		idx++;
	copy = malloc(idx + 1);
	if (!copy)
		return (0);
	idx = 0;
	while (src[idx])
	{
		copy[idx] = src[idx];
		idx++;
	}
	copy[idx] = '\0';
	return (copy);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
int main (void)
{
	char	*av[3] = {"hey", "world", "howdy!!"};
	t_stock_str *result = ft_strs_to_tab(3, av);
	ft_show_tab(result);
	for (int i = 0; i < 3; i++)
		free(result[i].copy);
	free(result);
}
/**/