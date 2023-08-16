/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:06:16 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/16 16:06:18 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
// open the map
// read first line lenght
// check that length is >= 4
// read symbols into data

int	checkFirstLine(t_data *data)
{
	if (data->empty == data->filled
		|| data->filled == data->obstacle
		|| data->empty == data->obstacle)
		data->valid = 0;
	return (data->valid);
}
