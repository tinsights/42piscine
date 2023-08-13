/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:18:05 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/13 20:18:07 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_tens(char *dict, char *input)
{
	char	single[1];
	char	tens[2];

	single[0] = input[1];
	tens[0] = input[0];
	tens[1] = '0';
	return (check_key(dict, tens, 2) && check_key(dict, single, 1));
}

int	check_hundreds(char *dict, char *input, int len)
{
	char	multiple[1];
	char	hundreds[3];

	multiple[0] = input[0];
	hundreds[0] = '1';
	hundreds[1] = '0';
	hundreds[2] = '0';
	if (check_key(dict, multiple, 1) && check_key(dict, hundreds, len))
	{
		if (!pow_ten(input, len))
			return (check_all_keys(dict, input + 1, len - 1));
		return (1);
	}
	return (0);
}

int	recurse_thousands(char *dict, char *input, int len)
{
	if (!pow_ten(input - 1, len + 1))
		return (check_all_keys(dict, input, len));
	return (1);
}

int	check_thousands(char *dict, char *input, int len)
{
	int		printed;
	char	*thous;
	char	*hundreds;
	int		idx;
	int		result;

	result = 0;
	printed = (len - 1) % 3 + 1;
	thous = malloc(len - printed);
	hundreds = malloc(printed);
	idx = -1;
	while (++idx < printed)
		hundreds[idx] = input[idx];
	thous[0] = '1';
	idx = 0;
	while (++idx <= len - printed)
		thous[idx] = '0';
	if (check_key(dict, thous, len - printed + 1)
		&& check_all_keys(dict, hundreds, printed))
		return (recurse_thousands(dict, input + printed, len - printed));
	free(hundreds);
	free(thous);
	return (result);
}
