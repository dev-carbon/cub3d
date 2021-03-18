/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:26:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:37:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

static t_texture	get_texture(t_texture textures[NUM_TEXTURES])
{
	return (textures[TSP]);
}

t_sprite			*set_sprite_params(t_sprite *sprite, t_game game)
{
	float	perp_dist;
	float	sprite_angle;

	perp_dist = sprite->dist * cos(sprite->angle);
	sprite->height = (game.setting.tile_size / perp_dist) *
		game.setting.projection_plane_dist;
	sprite->width = sprite->height;
	sprite->top = (game.window->size.height / 2) - (sprite->height / 2);
	sprite->top = (sprite->top < 0) ? 0 : sprite->top;
	sprite->bottom = (game.window->size.height / 2) + (sprite->height / 2);
	sprite->bottom = (sprite->bottom > game.window->size.height) ?
		game.window->size.height : sprite->bottom;
	sprite_angle = atan2(sprite->pos.y - game.player->pos.y,
		sprite->pos.x - game.player->pos.x) - game.player->rotation_angle;
	sprite->texture = get_texture(game.textures);
	sprite->screen_pos.x = tan(sprite_angle) *
		game.setting.projection_plane_dist;
	sprite->left.x = (game.window->size.width / 2) + sprite->screen_pos.x -
		(sprite->width / 2);
	sprite->right.x = sprite->left.x + sprite->width;
	return (sprite);
}
