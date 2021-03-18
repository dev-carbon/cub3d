/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:00:04 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:27:46 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	is_sprite(t_map map, t_fcoor pos, float tile_size)
{
	t_icoor	map_pos;
	t_icoor	delta;

	map_pos.x = (int)floor((pos.x - (0.5 * tile_size)) / tile_size);
	map_pos.y = (int)floor((pos.y - (0.5 * tile_size)) / tile_size);
	delta.x = pos.x - map_pos.x * tile_size;
	delta.y = pos.y - map_pos.y * tile_size;
	if (delta.x > tile_size / 2 && delta.x < (3 * tile_size) / 4 &&
			delta.y > tile_size / 2 && delta.y < (3 * tile_size) / 4)
		if (*(*(map.grid + map_pos.y) + map_pos.x) == MAP_SPRITE_1 ||
			*(*(map.grid + map_pos.y) + map_pos.x) == MAP_SPRITE_2 ||
			*(*(map.grid + map_pos.y) + map_pos.x) == MAP_SPRITE_3)
			return (1);
	return (0);
}
