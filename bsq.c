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

#include "bsq.h"

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
	return (topleft);
}

int	min_sq(int **map, int **sol_matrix, int x, int y)
{
	int	topleft;
	int	top;
	int	left;

	if (map[x][y])
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
	return (min(top, left, topleft) + 1);
}

// int	populate_bsq(int **map, int **sol_matrix, int rnum, int cnum)
// {
// 	int	maxsize;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	maxsize = 0;
// 	while (i < rnum)
// 	{
// 		j = 0;
// 		while (j < cnum)
// 		{
// 			sol_matrix[i][j] = min_sq(map, sol_matrix, i, j);
// 			if (sol_matrix[i][j] > maxsize)
// 				maxsize = sol_matrix[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (maxsize);
// }

t_sol	solve_bsq(int **map, int rnum, int cnum)
{
	int		i;
	int		j;
	int		**sol_matrix;
	t_sol	solution;

	sol_matrix = gen_matrix(rnum, cnum);
	i = 0;
	solution.size = 0;
	while (i < rnum)
	{
		j = 0;
		while (j < cnum)
		{
			sol_matrix[i][j] = min_sq(map, sol_matrix, i, j);
			if (sol_matrix[i][j] > solution.size)
			{
				solution.size = sol_matrix[i][j];
				solution.x = i - solution.size + 1;
				solution.y = j - solution.size + 1;
			}
			j++;
		}
		i++;
	}
	return (solution);
}

// print_arr(sol_matrix, rnum,cnum);
// 	printf("\n%d %d %d", solution.size, solution.x, solution.y);
// int	main()
// {
// 	int	arr[4][5] = {
// 					{1, 1, 1, 0, 0},
// 					{1, 1, 1, 0, 0},
// 					{1, 1, 1, 0, 0},
// 					{0, 0, 0, 0, 0},
// 					};
// 	t_sol sol = solve_bsq(arr, 4, 5);
// 	printf("\n%d %d %d", sol.size, sol.x, sol.y);
// }
