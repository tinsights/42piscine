/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:06:11 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 11:06:12 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		nb = 1;
	result = nb;
	while (power-- > 1)
		result *= nb;
	return (result);
}

/*
#include "stdio.h"
int	main(void)
{
	printf("%i\n", ft_iterative_power(2, 2));
	printf("%i\n", ft_iterative_power(-2, 3));
	printf("%i\n", ft_iterative_power(-2, 4));
	printf("%i\n", ft_iterative_power(2, 0));
	printf("%i\n", ft_iterative_power(0, 0));
	printf("%i\n", ft_iterative_power(-2, 0));
}
*/