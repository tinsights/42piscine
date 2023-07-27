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
	int		copy;
	int		count;

	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (nb > 0)
	{
		copy = nb;
		count = 0;
		while (copy > 9)
		{
			copy /= 10;
			count++;
		}

		digit = copy + 48;
		write(1, &digit, 1);
		while (count > 0)
		{
			copy *= 10;
			count--;
		}
		nb -= copy;
	}
}
// int	main(void)
// {
// 	ft(-42);
// }
