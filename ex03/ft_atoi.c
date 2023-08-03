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

int	ft_isspace(char c);

int	ft_atoi(char *str)
{
	int		polarity;
	long	nb;

	nb = 0;
	polarity = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			polarity *= -1;
	while (*str > 47 && *str < 58)
		nb = nb * 10 + *str++ - 48;
	return ((int)(polarity * nb));
}

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_atoi("   \t+---2147483648"));
	printf("%i\n", ft_atoi("  \r +---1325632167"));
	printf("%i\n", ft_atoi(" \v   -+-123"));
	printf("%i\n", ft_atoi("  \t  -+-0123"));
	printf("%i\n", ft_atoi("---+-+-412a3"));
	printf("%i\n", ft_atoi("---+ -+-412a3"));
	printf("%i\n", ft_atoi("---+-+-41 2a3"));
}
*/