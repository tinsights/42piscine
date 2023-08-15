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

char	*valid_args(int argc, char **argv);
t_data	map_converter(char *map);

int	main(int argc, char **argv)
{
	char		*map;
	t_data	output;

	map = valid_args(argc, argv);
	if (map)
	{
		output = map_converter(map);
			int	i = 0;
		int j = 0;
		while(i < output.rows)
		{
			j = 0;
			while (j < output.cols)
			{
				printf("%i, ", output.map[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		free (output.map);
	}
	write(1, "\n", 1);
}

t_data	map_converter(char *map)
{
	int 	**matrix;
	char	buff[1];
	char	*firstline;
	int		fd;
	int		i;
	int		j;
	t_data	output;


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
	output.empty = firstline[i-3];
	output.obstacle = firstline[i-2];
	output.filled = firstline[i-1];
	output.rows = 0;
	i = 0;
	while (firstline[i] != output.empty)
	{
		output.rows *= 10;
		output.rows += firstline[i] - 48;
		i++;
	}
	output.cols = 0;
	while(read(fd, buff, 1) && *buff != '\n')
		output.cols++;

	printf("%i, %i\n", output.rows, output.cols);
	close(fd);
	matrix = malloc(sizeof(int *) * output.rows);

	i = 0;
	while(i < output.rows)
	{
		matrix[i] = malloc(sizeof(int) * output.cols);
		j = 0;
		while (j < output.cols)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}

	fd = open(map, O_RDONLY); // assume opens fine
	while (read(fd, buff, 1) && *buff != '\n')
		continue ;

	i = 0;
	j = 0;
	while (read(fd, buff, 1) && i < output.rows)
	{
		if (*buff == output.empty)
			matrix[i][j] = 0;
		else if (*buff == output.obstacle)
			matrix[i][j] = 1;
		j++;
		if (*buff == '\n')
		{
			i++;
			j = 0;
		}
	}

	output.map = matrix;
	output.cols = output.cols;
	return (output);
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