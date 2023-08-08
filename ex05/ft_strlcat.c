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
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] && dest_length < size)
		dest_length++;
	while (src[src_length])
		src_length++;
	i = 0;
	if (dest_length < size)
	{
		while (src[i] != '\0' && dest_length + 1 < size)
		{
			dest[dest_length] = src[i];
			dest_length++;
			i++;
		}
		dest[dest_length] = '\0';
	}
	return (dest_length + src_length - i);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	d[50] = "hello world. nice to";
	char	d1[50] = "hello world. nice to";
	char	src[100] = " meet you! happy to be here.";

	printf("%i || ", ft_strlcat(d, src, 49));
	printf("%s\n", d);
	printf("src: %s\n", src);
	printf("%li || ", strlcat(d1, src, 49));
	printf("%s\n", d1);
	printf("src: %s\n", src);
}
*/