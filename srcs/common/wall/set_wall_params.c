/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:55:18 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:28:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

static t_texture	get_texture(t_texture textures[NUM_TEXTURES], t_ray ray)
{
	t_texture	texture;

	if (ray.was_h_hit && ray.dir.y == UP)
		return (textures[TN]);
	if (ray.was_h_hit && ray.dir.y == DOWN)
		return (textures[TS]);
	if (ray.was_v_hit && ray.dir.x == RIGHT)
		return (textures[TE]);
	if (ray.was_v_hit && ray.dir.x == LEFT)
		return (textures[TW]);
}

t_wall				*set_wall_params(t_game game, t_window win,
	t_ray ray, t_wall *wall)
{
	float	projected_wall_height;

	projected_wall_height = (game.setting.tile_size / (ray.dist_from_wall *
		cos(ray.angle - game.player->rotation_angle))) *
			game.setting.projection_plane_dist;
	wall->size.height = (int)projected_wall_height;
	wall->top = win.size.height / 2 - wall->size.height / 2;
	wall->top = adjust_value(wall->top, 0, win.size.height);
	wall->bottom = win.size.height / 2 + wall->size.height / 2;
	wall->bottom = adjust_value(wall->bottom, 0, win.size.height);
	wall->texture = get_texture(game.textures, ray);
	return (wall);
}
