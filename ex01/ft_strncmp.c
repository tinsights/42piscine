/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:57:58 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 07:58:01 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char*s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (*s1 && *s2 && counter++ < n && *s1++ == *s2++)
		continue ;
	return (s1[-1] - s2[-1]);
}
