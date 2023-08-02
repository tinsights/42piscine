/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:22:23 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 14:22:28 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		idx;
	char	*copy;

	idx = 0;
	while (src[idx])
		idx++;
	copy = malloc(idx);
	idx = 0;
	while (*src)
		copy[idx++] = *src++;
	copy[idx] = '\0';
	return (copy);
}

/*
#include <stdio.h>
int	main(void)
{
	char *s = ft_stdup("Hello, world");
	printf("%s\n", s);
	free(s);
}
*/