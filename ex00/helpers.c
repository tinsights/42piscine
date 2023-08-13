/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:16:49 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/13 11:16:51 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int pow_ten(char *str, int len)
{
	int	i;

	// printf("%s\n", str);
	i = 1;
	while (i < len)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int ft_isnumeric(char c)
{
	return (c >=48 && c <= 57);
}

int ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		length++;
		str++;
	}
	return (length);
}

