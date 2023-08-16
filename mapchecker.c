/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:06:16 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/16 16:06:18 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_first_line(t_data *data)
{
	if (data->empty == data->filled
		|| data->filled == data->obstacle
		|| data->empty == data->obstacle)
		data->valid = 0;
	return (data->valid);
}

int	check_map_validity(t_data *data, char *file)
{
	int		fd;

	fd = process_first_line(file, data);
	if (data->valid)
		check_rows_and_cols(fd, data);
	close(fd);
	return (data->valid);
}

void	check_rows_and_cols(int fd, t_data *data)
{
	int		i;
	int		j;
	char	buff[1];

	i = 0;
	j = 0;
	data->cols = 0;
	while (read(fd, buff, 1))
	{
		if (*buff == '\n')
		{
			if (i == 0)
				data->cols = j;
			else if (--j != data->cols)
				data->valid = 0;
			i++;
			j = 0;
		}
		else if (*buff != data->obstacle
			&& *buff != data->empty)
			data->valid = 0;
		j++;
	}
	if (data->rows != i || !data->rows || !data->cols)
		data->valid = 0;
}

int	process_first_line(char *file, t_data *data)
{
	int		len;
	char	buff[1];
	int		fd;
	char	*firstline;

	len = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buff, 1) && *buff != '\n')
		len++;
	close(fd);
	if (len < 4)
		data->valid = 0;
	if (data->valid)
	{
		firstline = malloc(sizeof(char) * len + 1);
		fd = open(file, O_RDONLY);
		read(fd, firstline, len + 1);
		data->empty = firstline[len - 3];
		data->obstacle = firstline[len - 2];
		data->filled = firstline[len - 1];
		check_first_line(data);
		first_line_atoi(data, firstline);
		free(firstline);
	}
	return (fd);
}

void	first_line_atoi(t_data *data, char *firstline)
{
	int	i;

	data->rows = 0;
	i = 0;
	while (firstline[i] != data->empty)
	{
		if (firstline[i] >= '0' && firstline[i] <= '9')
		{
			data->rows *= 10;
			data->rows += firstline[i] - 48;
		}
		else
			data->valid = 0;
		i++;
	}
}
