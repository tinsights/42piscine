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
void	solve_row(int *row, int box, int lv, int rv);

int ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return length;
}

int	main(int argc, char **argv)
{
	int	row[4];
	int left_view;
	int	right_view;

	// ------ ERROR CHECKING ------

	// check for the right number of arguments.
	// check that string provided has right length
	// TODO: adjust for final form
	if (argc != 2 || ft_strlen(argv[1]) != 3)
	{
		write(1, "ERROR\n", 6);
		return (-1);
	}
	else
	{
		// TODO: check that it is a number
		left_view = argv[1][0] - 48;
		right_view = argv[1][2] - 48;
		// for the case of n boxes,
		// the maximum view sum is n + 1
		// the minimum view sum is n - 1.. i think
		if (left_view + right_view > 5
			|| left_view + right_view < 3)
		{
			write(1, "ERROR\n", 6);
			return (-2);
		}
	}


	// -------- SOLVING --------
	
	// initialise row
	for (int i = 0; i < 4; i++)
		row[i] = 0;
	// let's try to print out all possible solutions:
	// we will start by placing the tallest available box
	// this box will go to the first available square
	// starting from the left
	// which is the square of left_view.
	solve_row(row, 4, left_view, right_view);

	return (0);
}

void	solve_row(int *row, int box, int lv, int rv)
{
	if (box == 0)
	{
		printf("Solution found.\n");
		printf("Row: ");
		for (int j = 0; j < 4; j++)
			printf("%i, ", row[j]);
		printf("\n");
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		// printf("Box: %i, col: %i\n", box, i+1);
		if (!row[i] && (box <= i + lv))
		{
			row[i] = box;
			solve_row(row, box - 1, lv, rv);
		}
	}
}
