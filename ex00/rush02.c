/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:22:16 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 16:22:17 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	col;
	int	row;

	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			if ((col == 1 && row == 1) || (col == x && row == 1))
				ft_putchar('A');
			else if ((col == 1 && row == y) || (col == x && row == y))
				ft_putchar('C');
			else if ((col == 1 || col == x) || (row == 1 || row == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

/***************************

RUSH 00

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
			if ((i == 1 && j == 1) || (i == x && j == 1)
				|| (i == 1 && j == y) || (i == x && j == y))
				ft_putchar('o');
			else if ((i == x || i == 1))
				ft_putchar('|');
			else if (j == 1 || j == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

**************************

RUSH 01

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
				ft_putchar('/');
			else if ((i == 1 && j == y) || (i == x && j == 1))
				ft_putchar('\\');
			else if ((i == x || i == 1) || (j == 1 || j == y))
				ft_putchar('*');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

**************************

RUSH 03

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
			if ((i == 1 && j == 1) || (i == 1 && j == y))
				ft_putchar('A');
			else if ((i == x && j == 1) || (i == x && j == y))
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

**************************

RUSH 04

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

*/