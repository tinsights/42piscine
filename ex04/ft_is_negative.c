/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:51:08 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/26 14:54:16 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_is_negative(int n)
{
	int	negative;
	int	positive;

	negative = 78;
	positive = 80;
	if (n < 0)
	{
		write(1, &negative, 1);
	}
	else
	{
		write(1, &positive, 1);
	}
}

int	main(void)
{
	int	a = 1;
	int	b = -2;
	ft_is_negative(a);
	ft_is_negative(b);
}

