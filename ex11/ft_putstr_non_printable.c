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

char	*atohex(char *hex, unsigned char c);

void	ft_putstr_non_printable(char *str)
{
	char	hex[2];

	while (*str)
	{
		if ((*str < 32 || *str > 126))
		{
			write(1, "\\", 1);
			write(1, atohex(hex, *str), 2);
		}
		else
			write(1, str, 1);
		str++;
	}
}

char	*atohex(char *hex, unsigned char c)
{
	int		i;

	hex[0] = c / 0x10;
	hex[1] = c % 0x10;
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

// int	main(void)
// {
// 	char c[5] = "hello";

// 	c[3] = 255;
// 	ft_putstr_non_printable(c);
// }
