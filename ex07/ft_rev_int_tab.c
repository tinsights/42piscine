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

	if (size <= 1)
		return ;
	temp = *tab;
	*tab = *(tab + (size - 1));
	*(tab + (size - 1)) = temp;
	ft_rev_int_tab(tab + 1, size - 2);

}
/*
#include <stdio.h>
int	main(void)
{
	int	arr[] = {1, 2};
	int	i  = 0;
	while (i < 2)
	{
		printf("%i\n", arr[i]);
		i++;
	}
	ft_rev_int_tab(arr, 2);
	i = 0;
	while (i < 2)
	{
		printf("%i\n", arr[i]);
		i++;
	}

}
*/