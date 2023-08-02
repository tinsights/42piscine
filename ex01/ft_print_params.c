/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:19:50 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 13:19:51 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	length;
	int	i;

	i = 0;
	while (++i < argc)
	{
		length = 0;
		while (argv[i][length])
			length++;
		write(1, argv[i], length);
		write(1, "\n", 1);
	}
	return (0);
}
