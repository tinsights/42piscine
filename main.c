/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:59:32 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/15 15:59:33 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	char	*map;
	t_data	data;
	t_sol sol;

	map = valid_args(argc, argv);
	if (map)
	{
		data = map_converter(map);
		sol = solve_bsq(data.map, data.rows, data.cols);
		write_soln(sol, data);
		free (data.map);
	}

	write(1, "\n", 1);
}


void	print_map(t_data data)
{		
	int	i;
	int j;

	i = 0;
	j = 0;
	while(i < data.rows)
	{
		j = 0;
		while (j < data.cols)
		{
			printf("%i", data.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}