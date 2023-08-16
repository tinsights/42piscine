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
char	*read_from_stdin(void);
int		checkFirstLine(t_data *data);


t_data	map_converter(char *file)
{
	char	buff[1];
	int		fd;
	int		i;
	int		j;
	t_data	data;

	// populate t_data struct
	// return 0 if invalid, 1 if valid
	if(read_map(file, &data))
	{
		fd = open(file, O_RDONLY); // assume opens fine
		// skip first line, already read.
		while (read(fd, buff, 1) && *buff != '\n')
			continue ;
		i = 0;
		j = 0;
		while (read(fd, buff, 1) && i < data.rows)
		{
			if (*buff == data.empty)
				data.map[i][j] = 0;
			else if (*buff == data.obstacle)
				data.map[i][j] = 1;
			j++;
			if (*buff == '\n')
			{
				i++;
				j = 0;
			}
		}
	}
	return (data);
}

int	read_map(char *file, t_data *data)
{
	char	*firstline;
	char	buff[1];
	int		i;
	int		fd;

	// read length of first line to get rows, empty, filled
	i = 0;
	fd = open(file, O_RDONLY); // assume opens fine
	while(read(fd, buff, 1) && *buff != '\n')
		i++;
	close(fd);
	firstline = malloc(sizeof(char) * i);
	firstline[i] = '\0';

	fd = open(file, O_RDONLY); // assume opens fine
		read(fd, firstline, i + 1);

	// TODO validate that firstline has no repeating chars
	// IF INVALID SET DATA.VALID to 0;
	data->empty = firstline[i-3];
	data->obstacle = firstline[i-2];
	data->filled = firstline[i-1];
	if (!checkFirstLine(data))
		return (0);
	data->rows = 0;
	i = 0;
	// does atoi to the digits seen in the first row
	while (firstline[i] != data->empty)
	{
		data->rows *= 10;
		data->rows += firstline[i] - 48;
		i++;
	}
	data->cols = 0;
	while(read(fd, buff, 1) && *buff != '\n')
		data->cols++;
	close(fd);
	data->map = malloc(sizeof(int *) * data->rows);
	i = -1;
	while(++i < data->rows)
		data->map[i] = malloc(sizeof(int) * data->cols);
	return (data->valid);
}

char	*valid_args(int argc, char **argv)
{
	char	*file;
	int		fd;

	if (argc == 1)
		return (read_from_stdin());
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Map Error", 9);
		close(fd);
		return (0);
	}
	else
		return (file);
}

char	*read_from_stdin(void)
{
	int		fd;
	char	buff[1];

	fd = open("tempmap", O_WRONLY | O_TRUNC);
	while(read(0, buff, 1))
		write(fd, buff, 1);
	close(fd);
	return ("tempmap");
}

int	checkFirstLine(t_data *data)
{
	if (data->empty == data->filled
		|| data->filled == data->obstacle
		|| data->empty == data->obstacle)
		data->valid = 0;
	return (data->valid);
}
