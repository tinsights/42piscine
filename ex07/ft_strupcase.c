/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:18:16 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 15:18:17 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 123 && c > 96)
			str[i] = c - 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char c[27] = "Hello. Nice to meet you! :)";
	printf("%s\n", ft_strupcase(c));
}*/