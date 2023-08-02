/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:20:00 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 13:20:01 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	length;

	while (argc > 1)
	{
		length = 0;
		while (argv[argc - 1][length])
			length++;
		write(1, argv[argc - 1], length);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
