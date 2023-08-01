/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:42:17 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/31 18:42:18 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

long	print_digit(long copy, int length, char *base)
{
	long	power;

	power = 1;
	while (copy >= length)
	{
		copy /= length;
		power *= length;
	}
	write(1, base + copy, 1);
	return (copy * power);
}

int	invalid(char *base)
{
	int length;

	length = 0;
	while (base[length])
	{
		// TODO: double for loop to check for same char twice
		length++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		length;
	int		num_of_digits;
	long	copy;

	if invalid(base)
		return ;
	copy = nbr;
	if (copy < 0)
	{
		write(1, "-", 1);
		copy = -1 * copy;
	}
	length = 0;
	num_of_digits = 1;
	while(base[length])
		length++;
	while(nbr /= length)
		num_of_digits ++;
	while (num_of_digits-- > 0)
		copy -= print_digit(copy, length, base);
	return ;
}

// int	main(void)
// {
// 	ft_putnbr_base(30, "0123456789abcdef");
// }