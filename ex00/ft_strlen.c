/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:40:23 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/31 18:40:25 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_strlen("hello"));
	printf("%i\n", ft_strlen(""));
	printf("%i\n", ft_strlen("asd"));
}
*/