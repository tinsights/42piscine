/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwijaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:00:08 by cwijaya           #+#    #+#             */
/*   Updated: 2023/08/14 15:00:10 by cwijaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

typedef struct sol
{
	int	x;
	int	y;
	int	size;
}	t_sol;

// void	print_arr(int **arr, int rnum, int cnum)
// {
// 	int	j;
// 	int i = 0;
// 	while (i < rnum)
// 	{
// 		j = 0;
// 		while (j < cnum)
// 		{
// 			printf("%d ",arr[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 		printf("\n");
// }

int	**gen_matrix(int rnum, int cnum)
{
	int	i;
	int	**matrix;

	i = -1;
	matrix = (int **)malloc(sizeof(int *) * rnum);
	while (++i < rnum)
		matrix[i] = (int *)malloc(sizeof(int) * cnum);
	return (matrix);
}

int	min(int top, int left, int topleft)
{
	if (top <= left && top <= topleft)
		return (top);
	else if (left <= top && left <= topleft)
		return (left);
	else if (topleft <= top && topleft <= left)
		return (topleft);
}

int	min_sq(int map[4][5], int **sol_matrix, int x, int y)
{
	int	topleft;
	int	top;
	int	left;

	if (!map[x][y])
		return (0);
	topleft = 0;
	top = 0;
	left = 0;
	if (x - 1 >= 0 && y - 1 >= 0)
		topleft = sol_matrix[x - 1][y - 1];
	if (x - 1 >= 0)
		top = sol_matrix[x - 1][y];
	if (y - 1 >= 0)
		left = sol_matrix[x][y - 1];
	return (min(top, left, topleft));
}

int	populate_bsq(int map[4][5], int **sol_matrix, int rnum, int cnum)
{
	int	maxsize;
	int	i;
	int	j;

	i = 0;
	maxsize = 0;
	while (i < rnum)
	{
		j = 0;
		while (j < cnum)
		{
			sol_matrix[i][j] = min_sq(map, sol_matrix, i, j) + 1;
			print_arr(sol_matrix, rnum, cnum);
			if (sol_matrix[i][j] > maxsize)
				maxsize = sol_matrix[i][j];
			j++;
		}
		i++;
	}
	return (maxsize);
}

t_sol	solve_bsq(int map[4][5], int rnum, int cnum)
{
	int		i;
	int		j;
	int		**sol_matrix;
	int		maxsize;
	t_sol	solution;

	sol_matrix = gen_matrix(rnum, cnum);
	maxsize = populate_bsq(map, sol_matrix, rnum, cnum);
	i = 0;
	while (i < rnum)
	{
		j = 0;
		while (j < cnum)
		{
			if (sol_matrix[i][j] == maxsize)
			{
				solution.x = i - maxsize + 1;
				solution.y = j - maxsize + 1;
				solution.size = maxsize;
				return (solution);
			}
			j++;
		}
		i++;
	}
}

int	main()
{
	int	arr[4][5] = {
					{1, 1, 1, 0, 0},
					{1, 1, 1, 0, 0},
					{1, 1, 1, 0, 0},
					{0, 0, 0, 0, 0},
					};
	t_sol sol = solve_bsq(arr, 4, 5);
	printf("\n%d %d %d", sol.size, sol.x, sol.y);
}
