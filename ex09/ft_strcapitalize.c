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

int	ft_str_is_alphanum(char c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char c)
{
	if (c > 122 || c < 97)
		return (0);
	return (1);
}

int	ft_str_is_uppercase(char c)
{
	if (c < 65 || c > 90)
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
		if (flag && ft_str_is_alphanum(str[i]))
		{
			flag = 0;
			if (ft_str_is_lowercase(str[i]))
				str[i] -= 32;
		}
		else if (!flag && ft_str_is_alphanum(str[i]))
		{
			if (ft_str_is_uppercase(str[i]))
				str[i] += 32;
		}
		else if (!(ft_str_is_alphanum(str[i])))
			flag = 1;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char str[100] = "hello, nice to meet you :) aasd+c2394/;.cz;c.z;1a";
	printf("%s\n", ft_strcapitalize(str));
}
*/