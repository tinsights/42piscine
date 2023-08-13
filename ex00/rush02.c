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

#include "rush02.h"

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
		write(1, "Error", 5);
		return (-1);
	}
	dict = "numbers.dict";
	input = argv[argc - 1];
	if (argc ==  3)
		dict = argv[1];
	int fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error", 10);
		close(fd);
		return (-1);
	}
	len = ft_strlen(input);
	if (!len)
	{
		write(1, "Error", 5);
		return(-1);
	}
	if (check_all_keys(dict, input, len))
		print_words(dict, input, len);
	else
		write(1, "Dict Error", 10);
	write(1, "\n", 1);
	return (0);
}
