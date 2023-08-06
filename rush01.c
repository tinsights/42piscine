/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:03:34 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/05 12:47:59 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	solve_row(int **board, int box, int row, int **udlr);

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	valid_arg(char *str)
{
	int	count_nums;

	if (ft_strlen(str) != 31)
		return (0);
	count_nums = 0;
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			count_nums++;
		else if (*str != 32)
			return (0);
		str++;
	}
	return (count_nums == 16);
}

int	read_arguments(int argc, char **argv, int **udlr_limits)
{
	int	i;

	if (argc != 2 || !valid_arg(argv[1]))
		return (0);
	i = -1;
	while (++i < 4)
	{
		udlr_limits[0][i] = argv[1][2 * i] - 48;
		udlr_limits[1][i] = argv[1][8 + 2 * i] - 48;
		udlr_limits[2][i] = argv[1][16 + 2 * i] - 48;
		udlr_limits[3][i] = argv[1][24 + 2 * i] - 48;
	}
	return (1);
}

void	print_result(int **board)
{
	int		i;
	int		j;
	char	box;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			box = board[i][j] + 48;
			write(1, &box, 1);
			if (j < 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	*board[4];
	int	*udlr_limits[4];
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		board[i] = malloc(4 * 4);
		udlr_limits[i] = malloc(4 * 4);
		j = -1;
		while (++j < 4)
			board[i][j] = 0;
	}
	if (!read_arguments(argc, argv, udlr_limits))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (solve_row(board, 4, 0, udlr_limits))
		print_result(board);
	else
		write(1, "Error\n", 6);
	return (0);
}
