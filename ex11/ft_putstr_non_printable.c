/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:05:54 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/30 13:05:55 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*atohex(char c)
{
	char	*hex;
	int		i;

	hex[0] = c / 16;
	hex[1] = c % 16;
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

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if ((*str < 32 || *str > 126))
		{
			write(1, "\\", 1);
			write(1, atohex(*str), 2);
		}
		else
			write(1, str, 1);
		str++;
	}
}
/*
int	main(void)
{
	char c[5] = "hello";

	c[3] = 127;
	ft_putstr_non_printable(c);
}*/