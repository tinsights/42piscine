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

char	*atohex(char *hex, char c)
{
	int		i;

	hex[0] = (unsigned char)c / 0x10;
    hex[1] = (unsigned char)c % 0x10;
	i = 0;
	while (i < 2)
	{
		if (hex[i] <= 9)
			hex[i] += 48;
		else
			hex[i] += 87;
		i++;
	}
	return (hex);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	**ptr;
	char 	*c;
	char	hex[2];
	int		rows;

	ptr = &addr;
	c = (char *) ptr;
	rows = 1 + size / 16;
	while(rows > 0)
	{
		for (int i = 7; i >= 0; i--)
			write(1, atohex(hex,*(c+i)), 2);
		write(1, ": ", 2);
		for (int i = 0; i < 16; i++)
		{
			write(1, atohex(hex, *(char *) (addr + i)), 2);
			if (i % 2 == 1)
				write(1, " ", 1);
		}
		for (int i = 0; i < 16; i++)
			write(1, (char *) (addr + i), 1);
		write(1, "\n", 1);
		addr += 16;
		rows--;
	}
}

int	main(void)
{
	char *c = "Lorem ipsum dolor sit amet, consectetur cras amet.";

	ft_print_memory(c, 50);
}