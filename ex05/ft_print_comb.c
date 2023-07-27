/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:40:05 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/27 09:54:06 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = 48;
	while (comb[0] <= 55)
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= 56)
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= 57)
			{
				write(1, comb, 3);
				if (comb[0] != 55)
				{
					write(1, ", ", 2);
				}
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
}
*/
