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

t_sol	solve_bsq(int **map, int rnum, int cnum)
{
	int		i;
	int		j;
	int		**sol_matrix;
	t_sol	solution;

	sol_matrix = gen_matrix(rnum, cnum);
	i = -1;
	solution.size = 0;
	while (++i < rnum)
	{
		j = -1;
		while (++j < cnum)
		{
			sol_matrix[i][j] = min_sq(map, sol_matrix, i, j);
			if (sol_matrix[i][j] > solution.size)
			{
				solution.size = sol_matrix[i][j];
				solution.x = i - solution.size + 1;
				solution.y = j - solution.size + 1;
			}
		}
	}
	free_sol(sol_matrix, rnum);
	return (solution);
}

void	free_sol(int **sol_matrix, int rnum)
{
	int	i;

	i = 0;
	while (i < rnum)
	{
		free(sol_matrix[i]);
		i++;
	}
	free(sol_matrix);
}
