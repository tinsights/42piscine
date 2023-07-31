/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:58:11 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 07:58:12 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*original;

	original = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (original);
}

/*
#include <stdio.h>
int	main(void)
{
	char dest[12] = "tell me why ";
	char src[] = "aint nothing but a heartache";
	printf("%s\n", ft_strcat(dest, src));
}
*/