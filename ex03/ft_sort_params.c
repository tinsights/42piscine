/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:20:09 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 13:20:10 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strcmp(char *s1, char*s2);
void	swap_strings(char **arr, int i, int j);

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
			if (ft_strcmp(argv[i], argv[j]) > 0)
				swap_strings(argv, i, j);
	}
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			write(1, argv[i] + j, 1);
		write(1, "\n", 1);
	}
}

int	ft_strcmp(char *s1, char*s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	swap_strings(char **arr, int i, int j)
{
	char	*temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
