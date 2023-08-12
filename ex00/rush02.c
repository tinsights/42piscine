/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:59:50 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/12 13:59:52 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_strlen(char *str);

#include <stdio.h>


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	int fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Open Error\n", 11);
		return (1);
	}

	char	*buff = malloc(1);
	char	*input = argv[1];
	int		len = ft_strlen(input);
	if (!len)
	{
		write(1, "Error\n", 6);
		return(-1);
	}

	int i = 0;


	while (read(fd, buff, 1) && i < len)
	{
		if (*buff == input[i])
		{
			write(1, buff, 1);
			while(read(fd, buff, 1) && *buff != '\n')
				write(1, buff, 1);
			write(1, "\n", 1);
			i++;
		}
	}

	if (close(fd) < 0)
	{
		write(1, "Close Error\n", 12);
		return(1);
	}
}

int ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		length++;
		str++;
	}
	return (length);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}