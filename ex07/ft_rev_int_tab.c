/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:46:34 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/26 22:10:45 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	num_swaps;

	num_swaps = size / 2;
	while (num_swaps >= 0)
	{
		temp = *(tab + num_swaps);
		*(tab + num_swaps) = *(tab + size - 1 - num_swaps);
		*(tab + size - 1 - num_swaps) = temp;
		num_swaps--;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	arr[5] = {3, 6, 9, 12, 15};
	int	i  = 0;
	while (i < 5)
	{
		printf("%i\n", arr[i]);
		i++;
	}
	ft_rev_int_tab(arr, 5);
	i = 0;
	while (i < 5)
	{
		printf("%i\n", arr[i]);
		i++;
	}

}
*/