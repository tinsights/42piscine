/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:30:32 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/28 14:31:45 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i++ < n)
		dest[i - 1] = src[i - 1];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*c = "hello";
	char	d[100] = "world";
	ft_strncpy(d, c, 50);
	printf("%s", d);
}
*/