/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:57:58 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 07:58:01 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char*s2, unsigned int n)
{
	unsigned int	counter;

	counter = 1;
	while (*s1 && *s2 && counter < n && *s1 == *s2)
	{
		s1++;
		s2++;
		counter++;
	}
	return (*s1 - *s2);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%i\n", ft_strncmp("hello", "world", 5));
	printf("%i\n", strncmp("hello", "world", 5));
	printf("%i\n", ft_strncmp("hello", "hello", 5));
	printf("%i\n", strncmp("hello", "hello", 5));
	printf("%i\n", ft_strncmp("hello, world", "hello", 5));
	printf("%i\n", strncmp("hello, world", "hello", 5));
	printf("%i\n", ft_strncmp("hello, world", "wello", 5));
	printf("%i\n", strncmp("hello, world", "wello", 5));
}
*/