/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:12:08 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 15:12:11 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 65 || c > 90)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_str_is_uppercase("DEF"));
	printf("%i\n", ft_str_is_uppercase("a@"));
	printf("%i\n", ft_str_is_uppercase(""));
	printf("%i\n", ft_str_is_uppercase("["));
	printf("%i\n", ft_str_is_uppercase("`"));
	printf("%i\n", ft_str_is_uppercase("{"));
}
*/