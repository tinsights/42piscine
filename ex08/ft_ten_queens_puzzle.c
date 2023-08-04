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

void place_queen(int *board);

int	ft_ten_queens_puzzle(void)
{
	int board[10][10];
	int queens = 3;
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			board[i][j] = 1;

	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < queens; c++)
		{
			place_queen(board[r]);
			place_queen(board[c]);
		}
	}
	return (0);
}

void place_queen(int *board)
{

}

int	main(void)
{
	ft_ten_queens_puzzle();
}