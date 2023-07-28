/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:56:52 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/27 10:56:56 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	int		count;
	char	digit[10];

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		nb *= -1;
	}
	if (nb == 0)
		write(1, "0", 1);
	count = 0;
	while (nb > 0)
	{
		digit[9 - count] = nb % 10 + 48;
		nb /= 10;
		count++;
	}
	write(1, digit + 10 - count, count);
}
/*
int	main(void)
{
	ft_putnbr(0);
	// ft_putnbr(42);
	// ft_putnbr(-42);
	// ft_putnbr(123);
	// ft_putnbr(2147483647);
	ft_putnbr(-2147483648);
}
*/