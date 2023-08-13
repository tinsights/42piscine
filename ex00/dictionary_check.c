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

int check_all_keys(char* dict, char *input, int len)
{
	while (*input == '0' && len > 1)
	{
		input++;
		len--;
	}
	if ((len < 2)
		|| (len < 3 && input[0] == '1')
		|| (len < 3 && input[1] == '0'))
			return check_if_key_exists(dict, input, len);
	else if (len < 3)
	{
		char *single = malloc(1);
		char *tens = malloc(2);

		single[0] = input[1];
		tens[0] = input[0];
		tens[1] = '0';

		if (check_if_key_exists(dict, tens, 2)
		 	&& check_if_key_exists(dict, single, 1))
		{
			free(single);
			free(tens);
			return (1);
		}
		else
		{
			free(single);
			free(tens);
			return (0);
		}
	}
	else if (len < 4)
	{
		char *multiple = malloc(1);
		char *hundreds = malloc(len);

		multiple[0] = input[0];
		hundreds[0] = '1';
		// this can only be hundreds,
		// i only need to print the multiple of
		// and then print "hundreds"
		for (int i = 1; i <= len; i++)
			hundreds[i] = '0';

		if (check_if_key_exists(dict, multiple, 1) && check_if_key_exists(dict, hundreds, len))
		{
			free(multiple);
			free(hundreds);
			if (!pow_ten(input, len))
				return check_all_keys(dict, input + 1, len - 1);
			else
				return (1);
		}
	}
	else
	{
		int bytes_to_print = (len - 1) % 3 + 1;
		char *thous = malloc(len - bytes_to_print);
		char *hundreds = malloc(bytes_to_print);
		for (int i = 0; i < bytes_to_print; i++)
			hundreds[i] = input[i];
		thous[0] = '1';
		for (int i = 1; i <= len - bytes_to_print; i ++)
			thous[i] = '0';

		if (check_if_key_exists(dict, thous, len - bytes_to_print + 1)
			&& check_all_keys(dict, hundreds, bytes_to_print))
		{
			free(hundreds);
			free(thous);
			if (!pow_ten(input + bytes_to_print - 1, len - bytes_to_print + 1))
				return check_all_keys(dict, input + bytes_to_print, len - bytes_to_print);
			else
				return (1);
		}
	}
	// should this line ever be hit?
	return (0);
}

int	check_if_key_exists(char* dict, char *input, int len)
{
	int fd = open(dict, O_RDONLY);
	int i = 0;
	char	*buff = malloc(1);


	while (read(fd, buff, 1))
	{
		if (len == 1 && ft_isnumeric(*buff) && *buff != input[i])
			while(read(fd, buff, 1) && *buff !='\n');
		if (input[i] && *buff == input[i])
		{
			i++;
			if (i == len)
			{

				read(fd, buff, 1);
				if (ft_isnumeric(*buff))
					i = 0;
				else
					return (1);
			}
		}
		else
			i = 0;
	}
	close(fd);
	free(buff);
	return (0);
}
