/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:42:02 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 16:42:03 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
			if ((i == 1 && j == 1) || (i == x && j == y && y != 1 && x != 1))
				ft_putchar('A');
			else if ((i == 1 && j == y) || (i == x && j == 1))
				ft_putchar('C');
			else if ((i == x || i == 1) || (j == 1 || j == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
