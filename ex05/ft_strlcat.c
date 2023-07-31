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
	int				length;

	length = 0;
	while (*dest)
	{
		dest++;
		length++;
	}
	i = 0;
	while (src[i] != '\0' && i < size - length - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i + length);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	c[] = "world. nice to meet you! happy to be here.";
	char	d[70] = "hello ";
	printf("%i\n", ft_strlcat(d, c, 70));
	printf("%s\n", d);
}
*/