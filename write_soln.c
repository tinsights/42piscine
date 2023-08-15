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
	int	i;
	int	j;

	print_map(data);
	i = 0;
	printf("%d, %d %d", sol.size, sol.x, sol.y);
	while (i < data.rows)
	{
		j = 0;
		while (j < data.cols)
		{
			if ((i >= sol.x && i < sol.x+sol.size) &&
				(j >= sol.y && j < sol.y +sol.size))
				write(1, &data.filled, 1);
			else if (data.map[i][j])
				write(1, &data.obstacle, 1);
			else if (!data.map[i][j])
				write(1, &data.empty, 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

// void	write_soln(t_sol sol, t_data data)
// {
// 	int		fd;
// 	char	buff[1];

// 	print_map(data);
// 	// i need the mapfile name to be stored in data

// 	fd = open("testmap", O_RDWR);
// 	// skip first line
// 	while(read(fd, buff, 1) && *buff != '\n')
// 		continue ;
// 	int i = 0;
// 	int j = 0;
// 	while(i < sol.x)
// 	{
// 		read(fd, buff, 1);
// 		if (*buff == '\n')
// 			i++;
// 	}
// 	i = 0;
// 	while (i < sol.size)
// 	{
// 		j = 0;
// 		while (j < sol.y)
// 		{
// 			read(fd, buff, 1);
// 			j++;
// 		}
// 		j = 0;
// 		while (j < sol.size)
// 		{
// 			write(fd, &data.filled, 1);
// 			j++;
// 		}
// 		while(read(fd, buff, 1) && *buff != '\n')
// 			continue;
// 		i++;
// 	}

// 	printf("\nsize=%d x=%d y=%d", sol.size, sol.x, sol.y);
// }
