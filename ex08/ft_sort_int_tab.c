/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:13:39 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/26 22:40:41 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	runs;
	int	ptr;

	runs = 0;
	while (runs < size)
	{
		ptr = 0;
		while (ptr < size - runs - 1)
		{
			if (tab[ptr] > tab[ptr + 1])
			{
				temp = tab[ptr + 1];
				tab[ptr + 1] = tab[ptr];
				tab[ptr] = temp;
			}
			ptr++;
		}
		runs++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	arr[5] = {5, 3, 4, 1, 2};
	int	i = 0;
	while (i < 5)
        {
                printf("%i\n", arr[i]);
                i++;
        }
	ft_sort_int_tab(arr, 5);
	i = 0;
	while (i < 5)
	{
		printf("%i\n", arr[i]);
		i++;
	}
}*/
