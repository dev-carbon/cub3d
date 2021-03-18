/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:45:54 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:23:49 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	set_sprites_position(t_sprite *sprites, t_map map,
	t_setting setting)
{
	int	count;
	int	x;
	int	y;

	y = -1;
	count = 0;
	while (++y < map.size.height)
	{
		x = -1;
		while (++x < map.size.width)
		{
			if (*(*(map.grid + y) + x) == MAP_SPRITE)
			{
				sprites[count].pos.x = setting.tile_size *
	(x + 0.5);
				sprites[count].pos.y = setting.tile_size *
	(y + 0.5);
				count++;
			}
		}
	}
}

t_sprite	*set_sprites(t_game *game)
{
	int	i;

	game->config->num_sprites = count_sprites(*game->map);
	if (!(game->sprites = (t_sprite *)malloc(sizeof(t_sprite) *
		game->config->num_sprites)))
		return (NULL);
	if (!(game->visible_sprites = (t_sprite *)malloc(sizeof(t_sprite) *
		game->config->num_sprites)))
		return (NULL);
	i = -1;
	while (++i < game->config->num_sprites)
	{
		init_sprite(&game->sprites[i]);
		init_sprite(&game->visible_sprites[i]);
	}
	set_sprites_position(game->sprites, *game->map, game->setting);
	return (game->sprites);
}
