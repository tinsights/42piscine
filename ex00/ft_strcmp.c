/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:57:46 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 07:57:48 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char*s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%i\n", ft_strcmp("hello", "world"));
	printf("%i\n", strcmp("hello", "world"));
	printf("%i\n", ft_strcmp("hello", "hello"));
	printf("%i\n", strcmp("hello", "hello"));
	printf("%i\n", ft_strcmp("hello, world", "hello"));
	printf("%i\n", strcmp("hello, world", "hello"));
	printf("%i\n", ft_strcmp("hello, world", "wello"));
	printf("%i\n", strcmp("hello, world", "wello"));
}
*/