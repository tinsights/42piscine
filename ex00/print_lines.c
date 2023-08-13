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

void print_words(char* dict, char *input, int len)
{
	int zerocount = 0;
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
	{
		char *single = malloc(1);
		char *tens = malloc(2);

		single[0] = input[1];
		tens[0] = input[0];
		tens[1] = '0';

		print_line(dict, tens, 2);
		write(1, "-", 1);
		print_line(dict, single, 1);
		free(single);
		free(tens);
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

		print_line(dict, multiple, 1);
		write(1, " ", 1);
		print_line(dict, hundreds, len);
		free(multiple);
		free(hundreds);
		if (!pow_ten(input, len))
		{
			write(1, " and ", 5);
			print_words(dict, input + 1, len - 1);
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

		print_words(dict, hundreds, bytes_to_print);
		write(1, " ", 1);
		print_line(dict, thous, len - bytes_to_print + 1);
		free(hundreds);
		free(thous);
		if (!pow_ten(input + bytes_to_print - 1, len - bytes_to_print + 1))
		{
			write(1, ", ", 2);
			print_words(dict, input + bytes_to_print, len - bytes_to_print);
		}
	}
}

void	print_line(char* dict, char *input, int len)
{
	int fd = open(dict, O_RDONLY);
	int i = 0;
	char	*buff = malloc(1);
	int 	flag = 0;


	while (read(fd, buff, 1))
	{
		if (!flag)
		{
			// skip all leading whitespace
			while(*buff == ' ')
				read(fd, buff, 1);
			// skip if minus sign
			if (*buff == '-')
				while(*buff != '\n')
					read(fd, buff, 1);
			// if its a plus sign
			// next byte needs to be a number
			// if it is not a number, skip whole line
			if (*buff == '+')
				if (read(fd, buff, 1) && !ft_isnumeric(*buff))
					while(*buff != '\n')
						read(fd, buff, 1);
			// if it is a 0
			// skip all leading 0s,
			while (*buff == '0')
				read(fd, buff, 1);
			// if we hit a ':'
		}
		if (input[i] == '0' && len == 1 && (*buff == ' ' || *buff == ':'))
		{
			while(*buff != ':' && read(fd, buff, 1))
				continue ;
			while(read(fd, buff, 1) && *buff ==  ' ')
				continue ;
			write(1, buff, 1);
			int spacecounter = 0;
			while(read(fd, buff, 1) && *buff != '\n')
			{
				if (*buff == ' ')
					spacecounter++;
				else
				{
					if (spacecounter)
						while(spacecounter > 0)
						{
							write(1, " ", 1);
							spacecounter--;
						}
					write(1, buff, 1);
				}
			}
			break;
		}
		// if len == 1
		// the first number we see
		// must be the number we are lookin for
		// otherwise, forget about it
		if (len == 1 && ft_isnumeric(*buff) && *buff != input[i])
			while(read(fd, buff, 1) && *buff !='\n');
		if (input[i] && *buff == input[i])
		{
			flag = 1;
			i++;
			if (i == len)
			{
				// read the next byte, it can be a space or a ':'
				// but not a number
				read(fd, buff, 1);
				if (ft_isnumeric(*buff))
					i = 0;
				else
				{
					// lets get to the ':'
					while(*buff != ':' && read(fd, buff, 1))
						continue ;
					while(read(fd, buff, 1) && *buff ==  ' ')
						continue ;
					write(1, buff, 1);
					int spacecounter = 0;
					while(read(fd, buff, 1) && *buff != '\n')
					{
						if (*buff == ' ')
							spacecounter++;
						else
						{
							if (spacecounter)
								while(spacecounter > 0)
								{
									write(1, " ", 1);
									spacecounter--;
								}
							write(1, buff, 1);
						}
					}
					break;
				}
			}
		}
		else
			i = 0;
	}
	close(fd);
	free(buff);
}
