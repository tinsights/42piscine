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

int	main(int argc, char **argv)
{
	char		*map;
	t_data	output;
	t_sol sol;

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
				printf("%i", output.map[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
	sol = solve_bsq(output.map, output.rows, output.cols);
	printf("\nsize=%d x=%d y=%d", sol.size, sol.x, sol.y);
	free (output.map);
	write(1, "\n", 1);
}
