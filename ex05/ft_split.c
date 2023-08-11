/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:24:00 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 14:24:01 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int		ft_strlen(char *str);
char	**count_separators(char *str, char *charset, int str_len, int num_sep);

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = count_separators(str, charset, ft_strlen(str), ft_strlen(charset));
	return (result);
}

char **count_separators(char *str, char *charset, int str_len, int num_sep)
{
	int count;
	int	i;
	int	j;
	int	k;
	int	flag;

	count = 1;
	flag = 0;

	while (*str)
	{
		if (flag  && *(str + 1))
		{
			i = -1;
			while (++i < num_sep)
			{
				if (*str == charset[i])
				{
					count++;
					flag = 0;
				}
			}
		}
		else
		{
			flag = 1;
			i = -1;
			while (++i < num_sep)
			{
				if (*str == charset[i])
				{
					flag = 0;
				}
			}
		}
		str++;
	}

	printf("%i\n", count);
	return (malloc(sizeof(char *) * count));
}

int	main(void)
{
	char **str = ft_split("h!e", ":!$");
	free(str);
}


int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] && dest_length < size)
		dest_length++;
	while (src[src_length])
		src_length++;
	i = 0;
	if (dest_length < size)
	{
		while (src[i] != '\0' && dest_length + i + 1 < size)
		{
			dest[dest_length + i] = src[i];
			i++;
		}
		dest[dest_length + i] = '\0';
	}
	return (dest_length + src_length);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (to_find[i] && str[i])
			{
				if (str[i] != to_find[i])
					break ;
				i++;
			}
			if (to_find[i] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}