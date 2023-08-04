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
	while (!(ft_is_prime(nb)))
		nb++;
	return (nb);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	limit;

	if (nb <= 1 || (nb % 2 == 0 && nb != 2))
		return (0);
	i = 2;
	limit = nb / 2;
	while (++i <= limit)
		if (nb % i == 0)
			return (0);
	return (1);
}

/*
#include <stdio.h>
int	main(void)
{
	for (int i = 0; i < 100; i++)
		printf("the next greatest prime after %i is %i\n", i, ft_find_next_prime(i));	
}
*/