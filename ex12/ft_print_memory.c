/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:54:23 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/30 14:54:25 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	void			**ptr;

	ptr = &addr;
	printf("%p  || %p \n", ptr, *ptr);
	printf("%p  || %s \n", addr, (char *) addr);
	
	write(1, ptr, 8);
}

int	main(void)
{
	char *c = "hello";

	ft_print_memory(c, 3);
}