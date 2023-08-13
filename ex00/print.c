/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:23:32 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/13 20:23:33 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_doubles(char *dict, char *input)
{
	char	single[1];
	char	tens[2];

	single[0] = input[1];
	tens[0] = input[0];
	tens[1] = '0';
	print_line(dict, tens, 2);
	write(1, "-", 1);
	print_line(dict, single, 1);
}

void	print_hundreds(char *dict, char *input, int len)
{
	char	multiple[1];
	char	*hundreds;
	int		idx;

	hundreds = malloc(len);
	multiple[0] = input[0];
	hundreds[0] = '1';
	idx = 0;
	while (++idx <= len)
		hundreds[idx] = '0';
	print_line(dict, multiple, 1);
	write(1, " ", 1);
	print_line(dict, hundreds, len);
	free(hundreds);
	if (!pow_ten(input, len))
	{
		write(1, " and ", 5);
		print_words(dict, input + 1, len - 1);
	}
}

void	recurse_print(char *dict, char *input, int len)
{
	int		bytes_to_print;
	char	*thous;
	char	*hundreds;
	int		idx;

	bytes_to_print = (len - 1) % 3 + 1;
	thous = malloc(len - bytes_to_print);
	hundreds = malloc(bytes_to_print);
	idx = -1;
	while (++idx < bytes_to_print)
		hundreds[idx] = input[idx];
	thous[0] = '1';
	idx = 0;
	while (++idx <= len - bytes_to_print)
		thous[idx] = '0';
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
