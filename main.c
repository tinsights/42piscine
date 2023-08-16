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

int	readfile(char *file)
{
	int		fd;
	t_data	data;
	t_sol	sol;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Map Error\n", 10);
		close(fd);
		return (0);
	}
	data.valid = 1;
	data.map = NULL;
	map_converter(file, &data);
	if (data.valid)
	{
		sol = solve_bsq(data.map, data.rows, data.cols);
		write_soln(sol, data);
	}
	else
		write(1, "Map Error\n", 10);
	if (data.map)
		free(data.map);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			readfile(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
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
