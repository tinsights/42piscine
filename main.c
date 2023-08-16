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

void	free_map(t_data data)
{
	int	i;

	if (data.map)
	{
		i = -1;
		while (++i < data.rows)
			free(data.map[i]);
		free(data.map);
	}
}

int	readfile(char *file)
{
	int		fd;
	t_data	data;
	t_sol	sol;
	char	buff[1];

	fd = open(file, O_RDONLY);
	if (fd == -1 || read(fd, buff, 1) == -1)
	{
		write(1, "Map Error\n", 10);
		return (0);
	}
	close(fd);
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
	free_map(data);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		readfile(read_from_stdin());
	else
	{
		while (i < argc)
		{
			readfile(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
}
