/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:19:40 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 13:19:41 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	length;

	if (argc)
	{
		length = 0;
		while (argv[0][length])
			length++;
		write(1, argv[0], length);
		write(1, "\n", 1);
	}
	return (0);
}
