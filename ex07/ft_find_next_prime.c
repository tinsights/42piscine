/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:07:19 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 11:07:20 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	if (!(ft_is_prime(nb)))
		return (ft_find_next_prime(nb + 1));
	return (nb);
}

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
int	main(void)
{
	for (int i = 200000; i < 9999999; i++)
		printf("the next prime after %i is %i\n", i, ft_find_next_prime(i));	
}
*/