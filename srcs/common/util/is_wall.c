/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:00:04 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:24:55 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	is_wall(t_map map, t_fcoor pos, float tile_size)
{
	int	x;
	int	y;

	x = (int)floor(pos.x / tile_size);
	y = (int)floor(pos.y / tile_size);
	if (x >= 0 && x < map.size.width && y >= 0 && y < map.size.height)
		if (*(*(map.grid + y) + x) == MAP_WALL)
			return (1);
	return (0);
}
