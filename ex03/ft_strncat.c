/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:58:27 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 07:58:27 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*original;
	unsigned int	count;

	count = 0;
	original = dest;
	while (*dest)
		dest++;
	while (*src && count++ < nb)
		*dest++ = *src++;
	*dest = '\0';
	return (original);
}

/*
#include <stdio.h>
int	main(void)
{
	char dest[100] = "tell me whyyy";
	char src[] = ", aint nothing but a heartache";
	printf("%s\n", ft_strncat(dest, src, 1));
}
*/