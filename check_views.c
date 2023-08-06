/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:52:21 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/06 14:52:23 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_from_top(int **board, int col)
{
	int	top_count;
	int	peak;
	int	i;

	top_count = 0;
	peak = 0;
	i = -1;
	while (++i < SIZE)
	{
		if (board[i][col] > peak)
		{
			top_count++;
			peak = board[i][col];
		}
	}
	return (top_count);
}

int	check_from_bottom(int **board, int col)
{
	int	down_count;
	int	peak;
	int	i;

	down_count = 0;
	peak = 0;
	i = SIZE;
	while (--i >= 0)
	{
		if (board[i][col] > peak)
		{
			down_count++;
			peak = board[i][col];
		}
	}
	return (down_count);
}

int	check_from_left(int *row)
{
	int	left_count;
	int	peak;
	int	i;

	left_count = 0;
	peak = 0;
	i = -1;
	while (++i < SIZE)
	{
		if (row[i] > peak)
		{
			left_count++;
			peak = row[i];
		}
	}
	return (left_count);
}

int	check_from_right(int *row)
{
	int	right_count;
	int	peak;
	int	i;

	right_count = 0;
	peak = 0;
	i = SIZE;
	while (--i >= 0)
	{
		if (row[i] > peak)
		{
			right_count++;
			peak = row[i];
		}
	}
	return (right_count);
}
