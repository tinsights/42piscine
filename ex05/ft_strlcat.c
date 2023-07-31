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
	while (*dest++)
		length++;
	dest -= 1;
	i = 0;
	while (src[i] != '\0' && i++ < size - length - 1)
		dest[i - 1] = src[i - 1];
	dest[i] = '\0';
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c[] = "world. nice to meet you! happy to be here.";
	char	d[20] = "hello ";
	printf("%i\n", ft_strlcat(d, c, 20));
	printf("%s", d);
}
*/