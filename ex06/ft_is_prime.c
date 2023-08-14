/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:07:05 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 11:07:06 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb / i)
		if (nb % i++ == 0)
			return (0);
	return (1);
}

/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{	
	int	i = INT_MAX;
	if (ft_is_prime(i))
		printf("%i is prime.\n", i);
}
*/