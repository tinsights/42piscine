/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:09:09 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/14 16:09:10 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_metadata
{
	int 	**map;
	int 	rows;
	int 	cols;
	char	empty;
	char	obstacle;
	char	filled;

}	t_data;

typedef struct s_sol
{
	int	x;
	int	y;
	int	size;
}	t_sol;

t_sol	solve_bsq(int **map, int rnum, int cnum);

# endif
