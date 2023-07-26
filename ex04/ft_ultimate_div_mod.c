/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:21:52 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/26 21:27:32 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int*b)
{
	int	result;
	int	remainder;

	result = *a / *b;
	remainder = *a % *b;
	*a = result;
	*b = remainder;
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 10;
	int b = 3;
	printf("%i divided by %i gives ", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("%i with a remainder of %i\n", a, b);
}*/
