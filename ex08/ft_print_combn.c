/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:16:51 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/27 11:16:54 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	comb[9];
	int		i;
	int		j;

	i = 9 - n;
	while (i++ < 9)
		comb[i - 1] = 48;
	i = 7;
	while (i-- >= 9 - n)
	{
		while (comb[8]++ < 57)
		{
			write(1, comb + 9 - n, n);
			if (!(i + 1 == 9 - n && comb[i + 1] == 58 - n && comb[8] == '9'))
				write(1, ", ", 2);
		}
		if (comb[i + 1]++ < 58 - (8 - i))
		{
			j = i + 2;
			while (j++ < 8)
				comb[j - 1] = comb[j - 2] + 1;
			comb[8] = comb[7];
			i++;
		}
	}
}
/*int	main(void)
{
	ft_print_combn(2);
}*/