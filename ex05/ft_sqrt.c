/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:06:50 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 11:06:52 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 0;
	while (++sqrt <= nb)
		if (sqrt * sqrt >= nb)
			return ((sqrt * sqrt == nb) * sqrt);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	for (int i = -1; i <= 16; i++)
		printf("the sqrt of %i is %i.\n", i, ft_sqrt(i));
}
*/