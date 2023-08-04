/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:42:27 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/31 18:42:28 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(char *base);
int	is_digit(char c, char *base, int length);
int	ft_isspace(char c);

int	ft_atoi_base(char *str, char *base)
{
	int		polarity;
	long	nb;
	int		length;
	int		digit;

	length = is_valid(base);
	if (length <= 1)
		return (0);
	polarity = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			polarity *= -1;
	nb = 0;
	digit = is_digit(*str, base, length);
	while (*str && digit >= 0)
	{
		nb *= length;
		nb += digit;
		str++;
		digit = is_digit(*str, base, length);
	}
	return ((int)(polarity * nb));
}

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_digit(char c, char *base, int length)
{
	int	i;

	i = -1;
	while (++i < length)
		if (base[i] == c)
			return (i);
	return (-1);
}

int	is_valid(char *base)
{
	int	length;
	int	i;
	int	j;

	length = 0;
	while (base[length])
		length++;
	i = -1;
	while (++i < length)
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		j = i;
		while (++j < length)
			if (base[i] == base[j])
				return (0);
	}
	return (length);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_atoi_base("  \n -255", "0123456789"));
	printf("%i\n", ft_atoi_base("  \r -11111111", "01"));
	printf("%i\n", ft_atoi_base("  \t -ff", "0123456789abcdef"));
}
*/