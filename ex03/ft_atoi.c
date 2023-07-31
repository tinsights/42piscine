/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:41:13 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/31 18:42:06 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	polarity;
	int	nb;

	nb = 0;
	polarity = 1;
	while (*str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			polarity *= -1;
		str++;
	}
	while (*str > 47 && *str < 58)
		nb = nb * 10 + *str++ - 48;
	return (polarity * nb);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_atoi("-123"));
	printf("%i\n", ft_atoi("    -+-123"));
	printf("%i\n", ft_atoi("    -+-123"));
	printf("%i\n", ft_atoi("---+-+-412a3"));
	printf("%i\n", ft_atoi("---+ -+-412a3"));
}
*/