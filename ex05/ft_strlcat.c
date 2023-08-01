/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:59:03 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 07:59:04 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;
	unsigned int	maxcopy;

	length = 0;
	while (*dest)
	{
		dest++;
		length++;
	}
	i = 0;
	if (size <= length)
		maxcopy = 0;
	else
		maxcopy = size - length - 1;
	while (src[i] != '\0' && i < maxcopy)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length + maxcopy);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	c[] = " meet you! happy to be here.";
	char	d[120] = "hello world. nice to";
	printf("%i\n", ft_strlcat(d, c, 31));
	printf("%s\n", d);
}*/