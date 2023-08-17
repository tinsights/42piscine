/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:57:44 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/14 12:57:45 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		count_separators(char *str, char *charset);
int		char_in_charset(char c, char *charset);
char	*ft_strdup(char *src, int i);
char	**ft_split(char *str, char *charset);

/*
#include <stdio.h>
int	main(void)
{
	char **str;
	int i;
	str = ft_split("", "");
	if (!str)
		printf("null\n");
	i = 0;
	if (!str[i])
			printf("null\n");
	while (str[i])
	{
		printf("%s || ", str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}
*/

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		count;
	int		i;
	int		j;

	count = count_separators(str, charset);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = 0;
	i = 0;
	while (i < count && *str)
	{
		while (*str && char_in_charset(*str, charset))
			str++;
		j = 1;
		while (str[j] && !char_in_charset(str[j], charset))
			j++;
		result[i] = ft_strdup(str, j);
		i++;
		str += j;
	}
	return (result);
}

int	count_separators(char *str, char *charset)
{
	int	count;

	while (char_in_charset(*str, charset))
		str++;
	count = 0;
	if (*str)
		count = 1;
	while (*str)
	{
		if (char_in_charset(*str, charset)
			&& *(str + 1) && !char_in_charset(*(str + 1), charset))
			count++;
		str++;
	}
	return (count);
}

char	*ft_strdup(char *src, int i)
{
	int		idx;
	char	*copy;

	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	idx = -1;
	while (++idx < i)
		copy[idx] = src[idx];
	copy[i] = 0;
	return (copy);
}

int	char_in_charset(char c, char *charset)
{
	int	num_sep;
	int	i;

	num_sep = ft_strlen(charset);
	i = -1;
	while (++i < num_sep)
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
