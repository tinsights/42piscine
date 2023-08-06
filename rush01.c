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

int solve_board(int **board, int size, int **udlr);
int	solve_row(int **board, int size, int row, int **udlr);
int is_valid_row(int *row, int lv, int rv);
int is_valid_board(int **board, int **udlr, int curr_row);

int ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return length;
}

int valid_arg(char *str)
{
	int count_nums;

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

int	main(int argc, char **argv)
{
	int	*board[4];
	int *udlr_limits[4];
	int left_limits[4];
	int	right_limits[4];
	int top_limits[4];
	int down_limits[4];

	// initialise row
	for (int i = 0; i < 4; i++)
	{
		board[i] = malloc(4 * 4);
		udlr_limits[i] = malloc(4 * 4);
		for (int j = 0; j < 4; j++)
			board[i][j] = 0;
	}
	// ------ ERROR CHECKING ------

	// check for the right number of arguments.
	// check that string provided has right length
	// TODO: adjust for final form
	if (argc != 2 || !valid_arg(argv[1]))
	{
		write(1, "ERROR\n", 6);
		return (-1);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			udlr_limits[0][i] = argv[1][2*i] - 48;
			udlr_limits[1][i] = argv[1][8 + 2*i] - 48;
			udlr_limits[2][i] = argv[1][16 + 2*i] - 48;
			udlr_limits[3][i] = argv[1][24 + 2*i] - 48;
		}
	}

	// -------- SOLVING --------
	


	// let's try to print out all possible solutions:
	// we will start by placing the tallest available box
	// this box will go to the first available square
	// starting from the left
	// which is the square of left_view.
	solve_board(board, 4, udlr_limits);


	return (0);
}

int solve_board(int **board, int size, int **udlr)
{
	for (int i = 0; i < size; i++)
	{	
		solve_row(board, size, i, udlr);
	}
}

int check_dup(int **board, int row, int col, int box)
{
	for (int i = 0; i < 4; i++)
	{
		if (board[row][i] == box)
			return (0);
		if (board[i][col] == box)
			return (0);
	}
	return (1);
}

int	solve_row(int **board, int box, int r, int **udlr)
{
	int *row = board[r];
	int lv = udlr[2][r];
	int rv = udlr[3][r];
	if (box == 0)
	{
		if (is_valid_row(row, lv, rv) && is_valid_board(board, udlr, r))
		{
			// printf("~~~~~~SOLUTION FOUND!!~~~~~~.\n");
			// printf("Row: ");
			for (int j = 0; j < 4; j++)
				printf("%i, ", row[j]);
			printf("\n");
			return (1);
		}
		return (0);
	}
	int tries = 0;
	while (tries < box)
	{
		for (int i = 0; i < 4; i++)
		{
			// printf("Box: %i, col: %i\n", box, i+1);
			if (!row[i])
			{
				row[i] = box;
				if (is_valid_row(row, lv, rv) >= 0)
				{
					// printf("Valid Box Placed.\nRow: ");
					// for (int j = 0; j < 4; j++)
					// 	printf("%i, ", row[j]);
					// printf("\n");
					if (!solve_row(board, box - 1, r, udlr))
						row[i] = 0;
					else
						return (1);
				}
				else
				{
					// printf("invalid box placement\n");
					row[i] = 0;
				}
			}
		}
		tries++;
		// printf("%i try for box %i\n", tries, box);
	}
	return (0);
}

int is_valid_board(int **board, int **udlr, int curr_row)
{
	// check for vertical duplicates
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row <= curr_row; row++)
		{
			if (!board[row][col])
				continue ;
			for (int i = row + 1; i <= curr_row; i++)
			{
				if (board[row][col] == board[i][col])
					return (0);
			}
		}
	}
	// check that
	return (1);
}

// int is_valid_col(int **board, int col, int up_limit, int down_limit)
// {
// 	int top_count;
// 	int down_count;
// 	int peak;

// 	top_count = 0;
// 	peak = 0;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (board[i][col] > peak)
// 		{
// 			top_count++;
// 			peak = board[i][col];
// 		}
// 	}
// 	if (top_count > up_limit)
// 		return (-1);
// 	down_count = 0;
// 	peak = 0;
// 	for (int i = 3; i >= 0; i--)
// 	{
// 		if (board[i][col] > peak)
// 		{
// 			down_count++;
// 			peak = board[i][col];
// 		}
// 	}
// 	if (down_count > down_limit)
// 		return (-1);
// 	return (top_count == up_limit && down_count == down_limit);
// }

int is_valid_row(int *row, int l_limit, int r_limit)
{
	int left_count;
	int right_count;
	int peak;

	left_count = 0;
	peak = 0;
	for (int i = 0; i < 4; i++)
	{
		if (row[i] > peak)
		{
			left_count++;
			peak = row[i];
		}
	}
	if (left_count > l_limit)
		return (-1);
	right_count = 0;
	peak = 0;
	for (int i = 3; i >= 0; i--)
	{
		if (row[i] > peak)
		{
			right_count++;
			peak = row[i];
		}
	}
	if (right_count > r_limit)
		return (-1);
	// returns -1 if limits burst
	// returns 1 if matches exactly
	// returns 0 if limits not burst
	return (left_count == l_limit && right_count == r_limit);
}