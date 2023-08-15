/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_soln.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:03:10 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/15 16:03:10 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write_soln(t_sol sol, t_data data)
{
	int		fd;
	char	buff[1];
	print_map(data);
	// i need the mapfile name to be stored in data

	fd = open("testmap", O_RDWR);
	// skip first line
	while(read(fd, buff, 1) && *buff != '\n')
		continue ;
	int i = 0;
	int j = 0;
	while(i < sol.x)
	{
		read(fd, buff, 1);
		if (*buff == '\n')
			i++;
	}
	i = 0;
	while (i < sol.size)
	{
		j = 0;
		while (j < sol.y)
		{
			read(fd, buff, 1);
			j++;
		}
		j = 0;
		while (j < sol.size)
		{
			write(fd, &data.filled, 1);
			j++;
		}
		while(read(fd, buff, 1) && *buff != '\n')
			continue;
		i++;
	}

	printf("\nsize=%d x=%d y=%d", sol.size, sol.x, sol.y);
}