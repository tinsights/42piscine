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

#include <stdio.h>

int	pow_ten(char *str, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isnumeric(char c)
{
	return (c >= 48 && c <= 57);
}

char *clean_num(char *str, int len)
{
	while (*str && *str == ' ')
		str++;
	if (*str && *str == '+')
		str++;
	while (*str && *str == '0')
		str++;
	if (*str < 48 || *str > 57)
		str--;
	str[len] = '\0';
	return str;
}

int	num_len(char *str)
{
	int	length;

	length = 0;
	while (*str && *str == ' ')
		str++;
	if (*str && *str == '+')
		str++;
	while (*str && *str == '0')
		str++;
	if (*str == '\0' || *str == ' ')
		return (1);
	while (*str)
	{
		if (*str == ' ')
			return length;
		else if (!ft_isnumeric(*str))
			return (0);
		length++;
		str++;
	}
	return (length);
}


int valid_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isnumeric(str[i]) && (str[i] != ' ' && str[i] != '+'))
			return (0);
		i++;
	}
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		str++;
	if (!str[i])
		return (0);
	while (ft_isnumeric(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] != ' ')
			return(0);
		i++;
	}
	return (1);
}