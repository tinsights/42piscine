/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:05:42 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 11:05:46 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb > 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_iterative_factorial(-1));
	printf("%i\n", ft_iterative_factorial(0));
	printf("%i\n", ft_iterative_factorial(3));
	printf("%i\n", ft_iterative_factorial(4));
	printf("%i\n", ft_iterative_factorial(5));
}
*/