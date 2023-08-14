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

typedef struct sol
{
	int	x;
	int	y;
	int	size;
}	t_sol;

int	**gen_matrix(int rnum, int cnum)
{
	int	i;
	int	**matrix;

	i = -1;
	matrix = (int **)malloc(sizeof(int *) * rnum);
	while (++i < rnum)
		matrix[i] = (int *)malloc(sizeof(int) * cnum);
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

int	min_sq(int **map, int x, int y)
{
	int	topleft;
	int	top;
	int	left;

	topleft = 0;
	top = 0;
	left = 0;
	if (x - 1 > 0 && y - 1 > 0)
		topleft = map[x - 1][y - 1];
	if (x - 1 > 0)
		top = map[x - 1][y];
	if (y - 1 > 0)
		left = map[x][y - 1];
	return (min(top, left, topleft));
}

int	populate_bsq(int **map, int **sol_matrix, int rnum, int cnum)
{
	int	maxsize;
	int	i;
	int	j;

	i = 0;
	maxsize = 0;
	sol_matrix = gen_matrix(rnum, cnum);
	while (i < rnum)
	{
		j = 0;
		while (j < cnum)
		{
			sol_matrix[i][j] = min_sq(map, i, j) + 1;
			if (sol_matrix[i][j] > maxsize)
				maxsize = sol_matrix[i][j];
		}
		i++;
	}
}

t_sol	solve_bsq(int **map, int rnum, int cnum)
{
	int		i;
	int		j;
	int		**sol_matrix;
	int		maxsize;
	t_sol	solution;

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
		}
		i++;
	}
}
