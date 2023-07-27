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
	int		copy;
	int		count;
	char	digit;

	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (nb > 0)
	{
		copy = nb;
		count = 1;
		while (copy > 9)
		{
			copy /= 10;
			count *= 10;
		}
		digit = copy + 48;
		write(1, &digit, 1);
		nb -= copy * count;
	}
}

// int	main(void)
// {
// 	ft_putnbr(-42);
// 	ft_putnbr(123);	
// }
