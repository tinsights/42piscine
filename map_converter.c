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
	int			fd;
	t_data	output;

	map = valid_args(argc, argv);
	if (map)
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
	write(1, "\n", 1);
}

t_data	map_converter(char *map)
{
	int 	**matrix;
	int		rowNums;
	int		colNums;
	char	buff[1];
	char	firstline[4];
	int		fd;
	int		i;
	int		j;
	t_data	output;


	i = 0;
	fd = open(map, O_RDONLY); // assume opens fine
	while(read(fd, buff, 1) && *buff != '\n' && i < 4)
	{
		firstline[i] = *buff;
		i++;
	}
	// TODO" validate that firstline has no repeating chars

	rowNums = firstline[0] - 48;
	colNums = 0;
	while(read(fd, buff, 1) && *buff != '\n')
		colNums++;

	printf("%s\n", firstline);
	printf("%i, %i\n", rowNums, colNums);
	close(fd);
	matrix = malloc(sizeof(int *) * rowNums);

	i = 0;
	while(i < rowNums)
	{
		matrix[i] = malloc(sizeof(int) * colNums);
		j = 0;
		while (j < colNums)
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
	while (read(fd, buff, 1) && i < rowNums)
	{
		if (*buff == firstline[1])
			matrix[i][j] = 0;
		else if (*buff == firstline[2])
			matrix[i][j] = 1;
		j++;
		if (*buff == '\n')
		{
			i++;
			j = 0;
		}
	}

	// i = 0;
	// j = 0;
	// while(i < rowNums)
	// {
	// 	j = 0;
	// 	while (j < colNums)
	// 	{
	// 		printf("%i, ", matrix[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }

	// i = 0;
	// while (i < rowNums)
	// {
	// 	free(matrix[i]);
	// 	i++;
	// }
	// free(matrix);


	output.map = matrix;
	output.rows = rowNums;
	output.cols = colNums;
	output.empty = firstline[1];
	output.obstacle = firstline[2];
	output.filled = firstline[3];
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