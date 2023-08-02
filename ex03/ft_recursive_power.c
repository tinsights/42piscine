/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:06:28 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 11:06:29 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (!power)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
#include "stdio.h"
int	main(void)
{
	printf("%i\n", ft_recursive_power(2, 2));
	printf("%i\n", ft_recursive_power(-2, 3));
	printf("%i\n", ft_recursive_power(-2, 4));
	printf("%i\n", ft_recursive_power(2, 0));
	printf("%i\n", ft_recursive_power(0, 0));
	printf("%i\n", ft_recursive_power(-2, 0));
}
*/