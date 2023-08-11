/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:17:40 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/11 15:18:17 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char				*ft_strdup(char *src);
int					ft_strlen(char *str);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

/*
int main (void)
{
	char	*av[3] = {"hello", "world", "howdy"};
	t_stock_str *result = ft_strs_to_tab(3, av);
	for (int i = 0; i < 3; i++)
		free(result[i].copy);
	free(result);
}
*/
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
		result[i].str = *av + i;
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
	copy = malloc(idx);
	idx = 0;
	while (*src)
		copy[idx++] = *src++;
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
