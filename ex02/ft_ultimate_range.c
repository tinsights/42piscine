/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:22:51 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 14:22:52 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	i;

	length = max - min;
	if (length <= 0)
		*range = NULL;
	else
		*range = (int *)malloc(sizeof(int) * length);
	// if null poiner
	// exit and return -1
	if (!range)
		return (-1);
	i = -1;
	while (++i < length)
		(*range)[i] = min++;
	if (*range)
		return (length);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int *t;
	int start = -3;
	int end = 5;
	int i = ft_ultimate_range(&t, start, end);
	printf("%i\n", i);
	for (i = 0; i < (end - start); i++)
		printf("%i, ", t[i]);
	free(t);
}
*/