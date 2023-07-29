/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:54:22 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 12:58:28 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y)
{
	int	i;
	int	j;

	j = 1;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			// if corner, print o
			if ((i == 1 && j == 1) ||
				(i == x && j == 1) || 
				(i == 1 && j == y) ||
				(i == x && j == y))
				write (1, "o", 1);
			// else (not a corner and) if first or last column
			else if ((j != 1 || j != y) && (i == x || i == 1))
				write (1, "|", 1);
			// else (not a corner and) if first or last row
			else if (j == 1 || j == y)
				write (1, "-", 1);
			// inner box
			else
				write (1, " ", 1);
			i++;
		}
		write (1, "\n", 1);
		j++;
	}
}


int	main(void)
{
	rush(6, 5);
}
