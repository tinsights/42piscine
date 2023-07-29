/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:58:42 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 07:58:43 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	while (*str && *str != *to_find)
	{
		i = 0;
		while (str[i] && to_find[i] && str[i] == to_find[i])
		{
			if (to_find[i] == '\0')
				return str;
			i++;
		}
		str++;
	}
	return str;
}
