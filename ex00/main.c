/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:54:22 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 12:58:28 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);

	rush(atoi(argv[1]), atoi(argv[2]));
}

int		atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while(str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return result;
}

