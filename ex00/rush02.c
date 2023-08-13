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

int	main(int argc, char **argv)
{
	int		len;
	char	*input;
	char	*dict;

	dict = valid_dict(argc, argv);
	len = 0;
	if (dict)
	{
		input = argv[argc - 1];
		if (valid_input(input))
		{
			len = num_len(input);
			if (!len)
				write(1, "Error", 5);
			else if (check_all_keys(dict, clean_num(input, len), len))
				print_words(dict, clean_num(input, len), len);
			else
				write(1, "Dict Error", 10);
		}
		else
			write(1, "Error", 5);
	}
	write(1, "\n", 1);
	return (0);
}

char	*valid_dict(int argc, char **argv)
{
	char	*dict;
	int		fd;

	if (argc != 2 && argc != 3)
	{
		write(1, "Error", 5);
		return (0);
	}
	else if (argc == 2)
		dict = "numbers.dict";
	else if (argc == 3)
		dict = argv[1];
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error", 10);
		close(fd);
		return ('\0');
	}
	else
		return (dict);
}
