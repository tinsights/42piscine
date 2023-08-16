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

void	map_converter(char *file, t_data *data)
{
	if (read_map(file, data))
		convert_symbols(file, data);
}

void	convert_symbols(char *file, t_data *data)
{
	char	buff[1];
	int		fd;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	while (read(fd, buff, 1) && *buff != '\n')
		continue ;
	i = 0;
	j = 0;
	while (read(fd, buff, 1) && i < data->rows)
	{
		if (*buff == data->empty)
			data->map[i][j] = 0;
		else if (*buff == data->obstacle)
			data->map[i][j] = 1;
		j++;
		if (*buff == '\n')
		{
			i++;
			j = 0;
		}
	}
	close(fd);
}

int	read_map(char *file, t_data *data)
{
	int		i;

	check_map_validity(data, file);
	if (data->valid)
	{
		data->map = malloc(sizeof(int *) * data->rows);
		i = -1;
		while (++i < data->rows)
			data->map[i] = malloc(sizeof(int) * data->cols);
	}
	return (data->valid);
}

char	*read_from_stdin(void)
{
	int		fd;
	char	buff[1];

	fd = open("tempmap", O_WRONLY | O_TRUNC);
	while (read(0, buff, 1))
		write(fd, buff, 1);
	close(fd);
	return ("tempmap");
}
