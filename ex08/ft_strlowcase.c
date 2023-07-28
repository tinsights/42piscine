/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:41:59 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 15:42:04 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 91 && c > 64)
			str[i] = c + 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char c[27] = "Hello. Nice to meet you! :)";
	printf("%s\n", ft_strlowcase(c));
}*/