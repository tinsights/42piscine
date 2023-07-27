/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:16:51 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/27 11:16:54 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialise_array(char *arr, int size)
{
	int		i;

	i = 9 - size;
	while (i < 9)
	{
		arr[i] = 48;
		i++;
	}
}

void	increment_last_and_print(char *arr, int size, int pointer)
{
	arr[8]++;
	write(1, arr + 9 - size, size);
	if (!(pointer == 9 - size && arr[pointer] == 58 - size && arr[8] == '9'))
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	comb[9];
	int		i;
	int		j;

	initialise_array(comb, n);
	i = 7;
	while (i >= 9 - n)
	{
		while (comb[8] < 57)
			increment_last_and_print(comb, n, i);
		if (comb[i] < 58 - (9 - i))
		{
			comb[i]++;
			j = i + 1;
			while (j < 8)
			{
				comb[j] = comb[j - 1] + 1;
				j++;
			}
			comb[8] = comb[7];
			continue ;
		}
		i--;
	}
}
// int	main(void)
// {
// 	ft_print_combn(2);
// }