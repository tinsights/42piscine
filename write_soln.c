/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_soln.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:03:10 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/15 16:03:10 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write_soln(t_sol sol, t_data data)
{
	int	i;
	int	j;

	// print_map(data);
	// printf("%d, %d %d", sol.size, sol.x, sol.y);
	if (data.valid)
	{
		i = 0;
		while (i < data.rows)
		{
			j = 0;
			while (j < data.cols)
			{
				if ((i >= sol.x && i < sol.x+sol.size) &&
					(j >= sol.y && j < sol.y +sol.size))
					write(1, &data.filled, 1);
				else if (data.map[i][j])
					write(1, &data.obstacle, 1);
				else if (!data.map[i][j])
					write(1, &data.empty, 1);
				j++;
			}
			i++;
			write(1, "\n", 1);
		}
	}
}