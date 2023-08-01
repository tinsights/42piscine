/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:54:23 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/30 14:54:25 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*atohex(char *hex, unsigned char c)
{
	hex[0] = *(&"0123456789abcdef"[c / 16]);
	hex[1] = *(&"0123456789abcdef"[c % 16]);
	return (hex);
}

void	init_line(char *line)
{
	int	i;

	i = -1;
	while (++i < 74)
	{
		if (i == 16)
			line[i] = ':';
		else
			line[i] = ' ';
	}
}

void	print_line(char *line, unsigned int size)
{
	if (size >= 16)
		write(1, line, 74);
	else
		write(1, line, 74 - (16 - size));
	write(1, "\n", 1);
}

void	write_if_printable(char *line, char c)
{
	if ((c < 32 || c > 126))
		*line = '.';
	else
		*line = c;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char				line[74];
	unsigned int		i;
	void				*orig;

	orig = addr;
	while (size != 0)
	{
		i = -1;
		init_line(line);
		while (++i < 16)
		{
			if (i % 2 == 0)
				atohex(line + i, *((char *) &addr + 7 - i / 2));
			if (i <= size - 1)
			{
				atohex(line + 18 + 2 * i + i / 2, *(char *)(addr + i));
				write_if_printable(line + i + 58, *(char *)(addr + i));
			}
		}
		print_line(line, size);
		addr += 16;
		size = size - !!(size / 16) * 16 - !(size / 16) * size;
	}
	return (orig);
}
/*
int	main(void)
{
	char *c = "Lorem ipsum dolor sit amet, consectetur cras \nameteris.";

	ft_print_memory(c, 55);
}
*/