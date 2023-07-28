/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:08:34 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 15:08:36 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c > 122 || c < 97)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_str_is_lowercase("123"));
	printf("%i\n", ft_str_is_lowercase("aBc"));
	printf("%i\n", ft_str_is_lowercase(""));
	printf("%i\n", ft_str_is_lowercase("asd"));
	printf("%i\n", ft_str_is_lowercase("ABC"));
	printf("%i\n", ft_str_is_lowercase("{"));
}*/