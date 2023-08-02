/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:58:42 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 07:58:43 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (to_find[i] && str[i])
			{
				if (str[i] != to_find[i])
					break ;
				i++;
			}
			if (to_find[i] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%s\n", ft_strstr("hellloo, world", "world"));
	printf("%s\n", strstr("hellloo, world", "world"));
	printf("%s\n", ft_strstr("hellloo, world", "h"));
	printf("%s\n", strstr("hellloo, world", "h"));
	//printf("%s\n", ft_strstr("hellloo, world", "rldez"));
	printf("%s\n", strstr("hellloo, world", ""));
	// printf("%s\n", ft_strstr("hellloo, world", "worldw"));
	// printf("%s\n", strstr("hellloo, world", "worldw"));
	printf("%s\n", strstr("hellloo, world", "llo"));
	printf("%s\n", ft_strstr("hellloo, world", "llo"));
	printf("%s\n", ft_strstr("hellloo, world", ""));
	// printf("%s\n", ft_strstr("", "asd"));
}
*/