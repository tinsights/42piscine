/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:56:21 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/13 10:56:22 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_all_keys(char *dict, char *input, int len)
{
	while (*input == '0' && len > 1)
	{
		input++;
		len--;
	}
	if ((len < 2)
		|| (len < 3 && input[0] == '1')
		|| (len < 3 && input[1] == '0'))
		return (check_key(dict, input, len));
	else if (len < 3)
		return (check_tens(dict, input));
	else if (len < 4)
		return (check_hundreds(dict, input, len));
	else
		return (check_thousands(dict, input, len));
	return (0);
}

int	check_key(char *dict, char *input, int len)
{
	int		fd;
	int		i;
	char	buff[1];

	fd = open(dict, O_RDONLY);
	i = 0;
	while (read(fd, buff, 1))
	{
		i = 0;
		skip(fd, buff);
		if (input[i] == '0' && len == 1 && (*buff == ' ' || *buff == ':'))
			return (1);
		if (len == 1 && ft_isnumeric(*buff) && *buff != input[i])
			while (read(fd, buff, 1) && *buff != '\n')
				continue ;
		while (input[i] && *buff == input[i])
		{
			read(fd, buff, 1);
			if (++i == len && exact_num_found(fd, buff))
				return (1);
		}
	}
	close(fd);
	return (0);
}

void	skip(int fd, char *buff)
{
	while (*buff == ' ')
		read(fd, buff, 1);
	if (*buff == '-')
		while (*buff != '\n')
			read(fd, buff, 1);
	if (*buff == '+')
		if (read(fd, buff, 1) && !ft_isnumeric(*buff))
			while (*buff != '\n')
				read(fd, buff, 1);
	while (*buff == '0')
		read(fd, buff, 1);
}

int	exact_num_found(int fd, char *buff)
{
	read(fd, buff, 1);
	if (ft_isnumeric(*buff))
		return (0);
	else
		return (1);
}
