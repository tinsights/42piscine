/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:02:26 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 15:02:28 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 48 || c > 57)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_str_is_numeric("123"));
	printf("%i\n", ft_str_is_numeric("a@"));
	printf("%i\n", ft_str_is_numeric(""));
	printf("%i\n", ft_str_is_numeric("0asd"));
	printf("%i\n", ft_str_is_numeric("`"));
	printf("%i\n", ft_str_is_numeric("{"));
}*/