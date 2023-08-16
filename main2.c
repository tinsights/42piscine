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

int	readfile(char **map)
{
	int		*fd;
	t_data	data;
	t_sol	sol;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Map Error", 9);
		close(fd);
		return (0);
	}
	// if (is_map_valid(map))
	data = map_converter(map);
	// if (is_data_valid(map))
	sol = solve_bsq(data.map, data.rows, data.cols);
	// if (is_sol_valid(map))
	write_soln(sol, data);
	free (data.map);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*map;
	t_data	data;
	t_sol	sol;
	int		fd;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			readfile(argv[i]);
			// if (is_readfile_valid(*))
			i++;
		}
	}
}


void	print_map(t_data data)
{
	int	i;
	int	j;

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
