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
int		count_separators(char *str, char *charset);
int		char_in_charset(char c, char *charset);


char	*ft_strdup(char *src, int i)
{
	int		idx;
	char	*copy;

	copy = malloc(i + 1);
	idx = -1;
	while(++idx < i)
		copy[idx] = src[idx];
	copy[i] = 0;
	return (copy);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		count;
	int		flag;
	int		i;
	int		j;

	if (!ft_strlen(str))
		return (0);
	// else if (!num_sep)
	// {
	// 	result = malloc(sizeof(char *) * 2);
	// 	result[0] = ft_strdup(str);
	// 	result[1] = 0;
	// }
	count = count_separators(str, charset);
	result = malloc(sizeof(char *) * (count + 1));
	result[count] = 0;

	// skip any characters in sep
	// by moving poiner
	// if we see a non-sep character
	// increase index till we see a sep character
	// duplicate string via malloc and add it to result
	// increment count
	i = 0;
	while (i < count)
	{
		while (*str)
		{
			if (char_in_charset(*str, charset))
				str++;
			else
			{
				j = 1;
				while (!char_in_charset(str[j], charset))
					j++;
				result[i] = ft_strdup(str, j);
				i++;
				str += j;
			}
		}
	}
	return (result);
}

int	count_separators(char *str, char *charset)
{
	int 	count;
	int		flag;

	count = 1;
	flag = 0;
	while (*str)
	{
		if (flag && char_in_charset(*str, charset))
		{
			count++;
			flag = 0;
		}
		else
			flag = !(char_in_charset(*str, charset));
		if (!flag && !*(str+1))
			count--;
		str++;
	}
	printf("%i\n", count);
	return (count);
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

int	main(void)
{
	char **str;
	int i;

	str = ft_split("!!!h:el:lo!!!", ":!$");
	if (!str)
		printf("null\n");
	i = 0;
	while (str[i])
	{
		printf("%s, ", str[i]);
		free(str[i]);
		i++;
	}
	printf("\n");
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