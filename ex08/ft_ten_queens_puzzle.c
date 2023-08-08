/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:02:55 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/03 17:02:57 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	valid(char *sequence, int curr_col)
{
	int		i;
	char	curr_q;

	i = -1;
	curr_q = sequence[curr_col];
	while (++i < curr_col)
	{
		if (curr_q == sequence[i]
			|| curr_q == sequence[i] + (curr_col - i)
			|| curr_q == sequence[i] - (curr_col - i))
			return (0);
	}
	return (1);
}

int	set_and_check(char *sequence, int col)
{
	int		count;
	char	row;

	if (col == 10)
	{
		write(1, sequence, 10);
		write(1, "\n", 1);
		return (1);
	}
	count = 0;
	row = '0';
	while (row <= '9')
	{
		sequence[col] = row;
		if (valid(sequence, col))
		{
			count += set_and_check(sequence, col + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	sequence[10];

	return (set_and_check(sequence, 0));
}

/*
int	main(void)
{
	printf("----------\n");
	printf("%i\n" ,ft_ten_queens_puzzle());
}
*/