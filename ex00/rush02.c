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
int	find_and_print(char *input, int len);
int multiple_of_ten_pow(char *str);
void not_sure_what_to_call_this(char *input, int len);

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (-1);
	}

	char	*input = argv[1];
	int		len = ft_strlen(input);
	if (!len)
	{
		write(1, "Error\n", 6);
		return(-1);
	}
	not_sure_what_to_call_this(input, len);
}


void not_sure_what_to_call_this(char *input, int len)
{
	while (*input == '0' && len > 1)
	{
		input++;
		len--;
	}
	if ((len < 2)
		|| (len < 3 && input[0] == '1')
		|| (len < 3 && input[1] == '0'))
		find_and_print(input, len);
	else if (len < 3)
	{
		char *single = malloc(1);
		char *tens = malloc(2);

		single[0] = input[1];
		tens[0] = input[0];
		tens[1] = '0';
		find_and_print(tens, 2);
		find_and_print(single, 1);

		free(single);
		free(tens);
	}
	else if (len < 4)
	{
		char *single = malloc(1);
		char *hundreds = malloc(len);

		for (int i = 1; i <= len; i++)
			hundreds[i] = '0';

		single[0] = input[0];
		hundreds[0] = '1';
		find_and_print(single, 1);
		find_and_print(hundreds, len);
		free(single);
		free(hundreds);
		if (!multiple_of_ten_pow(input))
			not_sure_what_to_call_this(input + 1, len - 1);
	}
	else
	{
		// printf("div: %i\n", (len - 1) / 3 + 1);
		// printf("mod: %i\n", (len - 1) % 3 + 1);
		int bytes_to_print = (len - 1) % 3 + 1;
		char *thous = malloc(len - bytes_to_print);
		char *hundreds = malloc(bytes_to_print);
		for (int i = 0; i < bytes_to_print; i++)
			hundreds[i] = input[i];
		// printf("%i\n", bytes_to_print);
		// printf("%s\n", hundreds);
		thous[0] = '1';
		for (int i = 1; i <= len - bytes_to_print; i ++)
			thous[i] = '0';

		not_sure_what_to_call_this(hundreds, bytes_to_print);
		find_and_print(thous, len - bytes_to_print + 1);
		free(hundreds);
		free(thous);
		if (!multiple_of_ten_pow(input + bytes_to_print - 1))
			not_sure_what_to_call_this(input + bytes_to_print, len - bytes_to_print);
	}
}

int multiple_of_ten_pow(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}


int	find_and_print(char *input, int len)
{
	int fd = open("numbers.dict", O_RDONLY);
	int i = 0;
	int found = 0;
	char	*buff = malloc(1);


	while (read(fd, buff, 1))
	{
		if (input[i] && *buff == input[i])
		{
			i++;
			if (i == len)
			{
				while(read(fd, buff, 1) && *buff != '\n')
					if (!(*buff == ':' || *buff ==' '))
						write(1, buff, 1);
				write(1, "\n", 1);
				found = 1;
				break;
			}
		}
		else
			i = 0;
	}
	close(fd);
	if (!found)
		write(1, "not found\n", 9);
	free(buff);
	return (0);
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
