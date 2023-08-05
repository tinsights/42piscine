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
int	solve_row(int *row, int box, int lv, int rv);
int is_valid(int *row, int lv, int rv);

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
	if (!solve_row(row, 4, left_view, right_view))
		printf("ERROR\n");

	return (0);
}

int is_valid_row(int *row, int lv, int rv)
{
	int count;
	int peak;

	count = 0;
	peak = 0;
	for (int i = 0; i < 4; i++)
	{
		if (row[i] > peak)
		{
			count++;
			peak = row[i];
		}
	}
	if (count != lv)
		return (0);
	// printf("for the row ");
	// for (int j = 0; j < 4; j++)
	// 	printf("%i, ", row[j]);
	// printf("\n");
	// printf("lv limit is %i and currently %i boxes can be seen\n", lv, count);
	count = 0;
	peak = 0;
	for (int i = 3; i >= 0; i--)
	{
		if (row[i] > peak)
		{
			count++;
			peak = row[i];
		}
	}
	if (count != rv)
		return (0);
	// printf("for the row ");
	// for (int j = 0; j < 4; j++)
	// 	printf("%i, ", row[j]);
	// printf("\n");
	// printf("rv limit is %i and currently %i boxes can be seen\n", rv, count);
	return (1);
}

int	solve_row(int *row, int box, int lv, int rv)
{
	if (box == 0)
	{
		if (is_valid_row(row, lv, rv))
		{
			printf("~~~~~~SOLUTION FOUND!!~~~~~~.\n");
			printf("Row: ");
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
				if (is_valid(row, lv, rv))
				{
					// printf("Valid Box Placed.\nRow: ");
					// for (int j = 0; j < 4; j++)
					// 	printf("%i, ", row[j]);
					// printf("\n");
					if (!solve_row(row, box - 1, lv, rv))
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

int is_valid(int *row, int lv, int rv)
{
	int count;
	int peak;

	count = 0;
	peak = 0;
	for (int i = 0; i < 4; i++)
	{
		if (row[i] > peak)
		{
			count++;
			peak = row[i];
		}
	}
	if (count > lv)
		return (0);
	// printf("for the row ");
	// for (int j = 0; j < 4; j++)
	// 	printf("%i, ", row[j]);
	// printf("\n");
	// printf("lv limit is %i and currently %i boxes can be seen\n", lv, count);
	count = 0;
	peak = 0;
	for (int i = 3; i >= 0; i--)
	{
		if (row[i] > peak)
		{
			count++;
			peak = row[i];
		}
	}
	if (count > rv)
		return (0);
	// printf("for the row ");
	// for (int j = 0; j < 4; j++)
	// 	printf("%i, ", row[j]);
	// printf("\n");
	// printf("rv limit is %i and currently %i boxes can be seen\n", rv, count);
	return (1);
}