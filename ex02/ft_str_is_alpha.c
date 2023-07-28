/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:50:31 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 14:51:16 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 65 || c > 122 || (c > 90 && c < 97))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_str_is_alpha("abcDEF"));
	printf("%i\n", ft_str_is_alpha("a@"));
	printf("%i\n", ft_str_is_alpha(""));
	printf("%i\n", ft_str_is_alpha("["));
	printf("%i\n", ft_str_is_alpha("`"));
	printf("%i\n", ft_str_is_alpha("{"));
}
*/