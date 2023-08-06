/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:50:07 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/06 14:50:08 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_from_top(int **board, int col);
int	check_from_bottom(int **board, int col);
int	check_from_left(int *row, int l_limit);
int	check_from_right(int *row, int r_limit);

int	no_vertical_duplicates(int **board, int curr_row)
{
	int	col;
	int	row;
	int	i;

	col = -1;
	while (++col < 4)
	{
		row = -1;
		while (++row < curr_row)
		{
			if (!board[row][col])
				continue ;
			i = row;
			while (++i <= curr_row)
			{
				if (board[row][col] == board[i][col])
					return (0);
			}
		}
	}
	return (1);
}

int	is_valid_row(int *row, int l_limit, int r_limit)
{
	int	left_count;
	int	right_count;

	left_count = check_from_left(row, l_limit);
	if (left_count > l_limit)
		return (-1);
	right_count = check_from_right(row, r_limit);
	if (right_count > r_limit)
		return (-1);
	return (left_count == l_limit && right_count == r_limit);
}

int	is_valid_col(int **board, int col, int **udlr)
{
	int	top_count;
	int	down_count;

	top_count = check_from_top(board, col);
	if (top_count > udlr[0][col])
		return (0);
	down_count = check_from_bottom(board, col);
	if (down_count > udlr[1][col])
		return (0);
	return (top_count == udlr[0][col] && down_count == udlr[1][col]);
}

int	is_valid_board(int **board, int **udlr)
{
	int	col;

	col = -1;
	while (++col < 4)
		if (!is_valid_col(board, col, udlr))
			return (0);
	return (1);
}

int	solve_row(int **board, int box, int r, int **udlr)
{
	int	tries;
	int	count;

	if (r == 4)
		return (is_valid_board(board, udlr));
	if (box == 0 && (is_valid_row(board[r], udlr[2][r], udlr[3][r])
		&& no_vertical_duplicates(board, r)))
		return ((solve_row(board, 4, r + 1, udlr)));
	tries = -1;
	while (++tries < box)
	{
		count = -1;
		while (++count < 4)
		{
			if (!board[r][count])
			{
				board[r][count] = box;
				if (is_valid_row(board[r], udlr[2][r], udlr[3][r]) >= 0)
					if (solve_row(board, box - 1, r, udlr))
						return (1);
				board[r][count] = 0;
			}
		}
	}
	return (0);
}
