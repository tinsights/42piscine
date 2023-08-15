/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:07:37 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/14 16:07:38 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_data	map_converter(char *map)
{
	char	buff[1];
	int		fd;
	int		i;
	int		j;
	t_data	output;

	// populate t_data struct
	read_map(map, &output);
	fd = open(map, O_RDONLY); // assume opens fine
	// skip first line, already read.
	while (read(fd, buff, 1) && *buff != '\n')
		continue ;
	i = 0;
	j = 0;
	while (read(fd, buff, 1) && i < output.rows)
	{
		if (*buff == output.empty)
			output.map[i][j] = 0;
		else if (*buff == output.obstacle)
			output.map[i][j] = 1;
		j++;
		if (*buff == '\n')
		{
			i++;
			j = 0;
		}
	}
	return (output);
}

void	read_map(char *map, t_data *metadata)
{	
	char	*firstline;
	char	buff[1];
	int		i;
	int		fd;

	// read length of first line to get rows, empty, filled
	i = 0;
	fd = open(map, O_RDONLY); // assume opens fine
	while(read(fd, buff, 1) && *buff != '\n')
		i++;
	close(fd);
	firstline = malloc(sizeof(char) * i);
	firstline[i] = '\0';

	fd = open(map, O_RDONLY); // assume opens fine
		read(fd, firstline, i + 1);

	// TODO validate that firstline has no repeating chars
	metadata->empty = firstline[i-3];
	metadata->obstacle = firstline[i-2];
	metadata->filled = firstline[i-1];
	metadata->rows = 0;
	i = 0;
	// does atoi to the digits seen in the first row
	while (firstline[i] != metadata->empty)
	{
		metadata->rows *= 10;
		metadata->rows += firstline[i] - 48;
		i++;
	}
	metadata->cols = 0;
	while(read(fd, buff, 1) && *buff != '\n')
		metadata->cols++;
	close(fd);
	metadata->map = malloc(sizeof(int *) * metadata->rows);
	i = -1;
	while(++i < metadata->rows)
		metadata->map[i] = malloc(sizeof(int) * metadata->cols);
}

char	*valid_args(int argc, char **argv)
{
	char	*map;
	int		fd;

	if (argc != 2)
	{
		write(1, "Error", 5);
		return (0);
	}
	map = argv[1];
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Map Error", 9);
		close(fd);
		return (0);
	}
	else
		return (map);
}
