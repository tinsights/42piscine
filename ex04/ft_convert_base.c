/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:23:47 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 14:23:48 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid(char *base);
int		ft_atoi_base(char *str, char *base);
int		is_digit(char c, char *base, int length);
int		prepare_temp(char *temp, long *copy, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	temp[33];
	char	*result;
	int		num_of_digits;
	long	copy;

	if (is_valid(base_to) <= 1 || is_valid(base_from) <= 1)
		return (NULL);
	copy = (long) ft_atoi_base(nbr, base_from);
	num_of_digits = prepare_temp(temp, &copy, base_to);
	result = (char *)malloc(num_of_digits + 1);
	while (copy++ < num_of_digits + 1)
		result[copy - 1] = temp[num_of_digits - copy];
	result[copy] = '\0';
	return (result);
}

int	prepare_temp(char *temp, long *copy, char *base_to)
{
	int		num_of_digits;
	short	negative;

	num_of_digits = 0;
	negative = (*copy < 0);
	if (!*copy)
		temp[num_of_digits++] = base_to[0];
	*copy *= ((*copy < 0) * -1 + (*copy > 0) * 1);
	while (*copy > 0)
	{
		temp[num_of_digits++] = base_to[*copy % is_valid(base_to)];
		*copy /= is_valid(base_to);
	}
	if (negative)
		temp[num_of_digits++] = '-';
	return (num_of_digits);
}

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
	while (*str == 32)
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
	return (polarity * (int) nb);
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
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (++j < length)
			if (base[i] == base[j])
				return (0);
	}
	return (length);
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

/*
#include <stdio.h>
int	main(void)
{
	char *result;

	result = ft_convert_base("7FFFFFFF", "0123456789ABCDEF", "0123456789" );
	printf("%s\n", result);
	free(result);

	result = ft_convert_base("-80000000", "0123456789ABCDEF", "0123456789" );
	printf("%s\n", result);
	free(result);

	result = ft_convert_base("12", "0123456789", "01" );
	printf("%s\n", result);
	free(result);

	result = ft_convert_base("-1100", "01", "0123456789" );
	printf("%s\n", result);
	free(result);

	result = ft_convert_base("32", "0123456789", "01234567" );
	printf("%s\n", result);
	free(result);

}
*/