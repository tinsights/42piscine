/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:45:56 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 15:45:58 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i])
	{
		if (flag)
		{
			if (str[i] > 96 && str[i] < 123)
				str[i] -= 32;
			flag = 0;
			i++;
			continue ;
		}
		if (str[i] > 64 && str[i] < 91)
			str[i] += 32;
		if (str[i] == 32)
			flag = 1;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c[27] = "HELLO. nICe to MEET you! :)";
	printf("%s\n", ft_strcapitalize(c));
}
*/