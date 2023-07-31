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


int	ft_str_is_alpha(char c)
{
	if (c < 65 || c > 122 || (c > 90 && c < 97))
		return (0);
	return (1);
}

int	ft_str_is_lowercase(char c)
{
	if (c > 122 || c < 97)
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i])
	{
		if (flag && ft_str_is_alpha(str[i]))
		{
			flag = 0;
			if (ft_str_is_lowercase(str[i]))
				str[i] -= 32;
		}
		else if (!flag && ft_str_is_alpha(str[i]))
		{
			if (!(ft_str_is_lowercase(str[i])))
				str[i] += 32;
		}
		else
			flag = 1;
		i++;
	}
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char	c[] = "!@#!@#as;z;cXc/.=-qw)";
	printf("%s\n", ft_strcapitalize(c));
}
