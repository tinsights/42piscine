/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:27:07 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 13:28:50 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i++])
		dest[i - 1] = src[i - 1];
	dest[i - 1] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*c = "hello!";
	char	d[12] = "hello, world";
	ft_strcpy(d, c);
	printf("%s", d);
}
*/