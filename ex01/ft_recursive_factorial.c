/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:05:57 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 11:05:59 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb > 0)
		return (nb * ft_recursive_factorial(nb - 1));
	return (0);
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