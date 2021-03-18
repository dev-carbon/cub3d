/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:49:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:42:29 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

int	count_sprites(t_map map)
{
	int	x;
	int	y;
	int	num_sprites;

	y = 0;
	num_sprites = 0;
	while (y < map.size.height)
	{
		x = 0;
		while (x < map.size.width)
		{
			if (*(*(map.grid + y) + x) == MAP_SPRITE_1 ||
				*(*(map.grid + y) + x) == MAP_SPRITE_2 ||
				*(*(map.grid + y) + x) == MAP_SPRITE_3)
				num_sprites++;
			x++;
		}
		y++;
	}
	return (num_sprites);
}
