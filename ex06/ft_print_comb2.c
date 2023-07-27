/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:27:24 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/27 10:47:53 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	left_char[3];
	char	right_char[2];
	int		left_num;
	int		right_num;

	left_num = 0;
	left_char[2] = ' ';
	while (left_num < 99)
	{
		left_char[0] = left_num / 10 + 48;
		left_char[1] = left_num % 10 + 48;
		right_num = left_num + 1;
		while (right_num <= 99)
		{
			right_char[0] = right_num / 10 + 48;
			right_char[1] = right_num % 10 + 48;
			write(1, left_char, 3);
			write(1, right_char, 2);
			if (left_num != 98)
				write(1, ",", 1);
			right_num++;
		}
		left_num++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// }