/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:15:44 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/13 12:13:16 by zng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_words(char *dict, char *input, int len)
{
	int	zerocount;

	zerocount = 0;
	while (*input == '0' && len > 1)
	{	
		zerocount++;
		input++;
		len--;
	}
	if (zerocount > 1)
		write(1, "and ", 4);
	if ((len < 2)
		|| (len < 3 && input[0] == '1')
		|| (len < 3 && input[1] == '0'))
		print_line(dict, input, len);
	else if (len < 3)
		print_doubles(dict, input);
	else if (len < 4)
		print_hundreds(dict, input, len);
	else
		recurse_print(dict, input, len);
}

void	print_line(char *dict, char *input, int len)
{
	int		fd;
	int		i;
	char	buff[1];

	fd = open(dict, O_RDONLY);
	while (read(fd, buff, 1))
	{
		i = 0;
		skip(fd, buff);
		if (input[i] == '0' && len == 1 && (*buff == ' ' || *buff == ':'))
			return (printzero(fd, buff));
		if (len == 1 && ft_isnumeric(*buff) && *buff != input[i])
			skipline(fd, buff);
		while (input[i] && *buff == input[i] && read(fd, buff, 1))
		{
			if (++i == len && !ft_isnumeric(*buff))
				return (printline(fd, buff));
		}
	}
	close(fd);
}

void	printzero(int fd, char *buff)
{
	int	spacecounter;

	while (*buff != ':' && read(fd, buff, 1))
		continue ;
	while (read(fd, buff, 1) && *buff == ' ')
		continue ;
	write(1, buff, 1);
	spacecounter = 0;
	while (read(fd, buff, 1) && *buff != '\n')
	{
		if (*buff == ' ')
			spacecounter++;
		else
		{
			while (spacecounter-- > 0)
				write(1, " ", 1);
			write(1, buff, 1);
		}
	}
}

void	printline(int fd, char *buff)
{
	int	spacecounter;

	while (*buff != ':' && read(fd, buff, 1))
		continue ;
	while (read(fd, buff, 1) && *buff == ' ')
		continue ;
	write(1, buff, 1);
	spacecounter = 0;
	while (read(fd, buff, 1) && *buff != '\n')
	{
		if (*buff == ' ')
			spacecounter++;
		else
		{
			while (spacecounter-- > 0)
				write(1, " ", 1);
			write(1, buff, 1);
		}
	}
}

void	skipline(int fd, char *buff)
{
	while (*buff != '\n')
		read(fd, buff, 1);
}
