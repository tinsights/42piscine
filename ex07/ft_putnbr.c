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

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (nb > 9)
	{
		digit = nb / 10 + 48;
		write(1, &digit, 1);
		nb -= (digit % 48) * 10;
	}
	digit = nb % 10 + 48;
	write(1, &digit, 1);
}
/*int	main(void)
{
	ft_putnbr(-42);
}
*/