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

int		ft_strlen(char *str);
int		check_all_keys(char* dict, char *input, int len);
int		check_if_key_exists(char* dict, char *input, int len);
void 	print_words(char* dict, char *input, int len);
void 	print_line(char* dict, char *input, int len);
int		pow_ten(char *str, int len);
int		ft_isnumeric(char c);

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*input;
	char	*dict;
	int		len;
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	dict = "numbers.dict";
	input = argv[1];
	if (argc ==  3)
	{
		dict = argv[1];
		input = argv[2];
	}
	len = ft_strlen(input);
	if (!len)
	{
		write(1, "Error\n", 6);
		return(-1);
	}
	if (check_all_keys(dict, input, len))
		print_words(dict, input, len);
	else
		write(1, "Dict Error\n", 11);
}

// TODO:
// WRITE A RECURSIVE FIND FUNCTION
// THAT TAKES IN THE SAME INPUT, LEN
// CHECKS TAHT ALL THE REQUIRED KEYS EXITS IN THE DICT
// RETUNRS 1 IF FINE,
// IF ANY OF THE KEYS ARE MISSING,
// RETURNS 0, THEN NO PRINTING OCCURS,
// ONLY ERROR MESSAGE

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

int pow_ten(char *str, int len)
{
	int	i;

	// printf("%s\n", str);
	i = 1;
	while (i < len)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}


void	print_line(char* dict, char *input, int len)
{
	int fd = open(dict, O_RDONLY);
	int i = 0;
	char	*buff = malloc(1);


	while (read(fd, buff, 1))
	{
		// if len == 1
		// the first number we see
		// must be the number we are lookin for
		// otherwise, forget about it
		if (len == 1 && ft_isnumeric(*buff) && *buff != input[i])
			while(read(fd, buff, 1) && *buff !='\n');
		if (input[i] && *buff == input[i])
		{
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
							if (!spacecounter)
								while(spacecounter-- > 0)
									write(1, " ", 1);
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

int ft_isnumeric(char c)
{
	return (c >=48 && c <= 57);
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
