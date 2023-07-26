/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:56:54 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/26 21:12:35 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int a = 1;
	int b = 42;
	printf("before swapping a is %i, b is %i\n", a, b);
	ft_swap(&a, &b);
	printf("after swapping a is %i, b is %i\n", a, b);
}*/
