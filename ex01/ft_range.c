/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:22:37 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 14:22:38 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	length;
	int	*arr;

	length = max - min;
	if (length <= 0)
		return (NULL);
	arr = malloc(sizeof(int) * length);
	while (min < max)
		*arr++ = min++;
	return (arr - length);
}

/*
#include <stdio.h>
int	main(void)
{
	int *t = ft_range(1, 7);
	for (int i = 0; i < 5; i++)
		printf("%i, ", t[i]);
	free(t);
}
*/