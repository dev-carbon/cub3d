/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:16:45 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 09:48:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		set_position(t_player *player, t_fcoor *new_pos)
{
	player->walk_step = player->walk_dir * player->move_speed;
	new_pos->x = player->pos.x + player->walk_step *
		cos(player->rotation_angle);
	new_pos->y = player->pos.y + player->walk_step *
		sin(player->rotation_angle);
}

static void	translate(t_player *player, t_fcoor *new_pos)
{
	float	angle;

	angle = 0.5 * PI - player->rotation_angle;
	player->translation_step = player->translation_dir *
		player->move_speed;
	new_pos->x = new_pos->x - cos(angle) * player->translation_step;
	new_pos->y = new_pos->y + sin(angle) * player->translation_step;
}

void		move_camera(t_game *game)
{
	t_fcoor	tmp;
	t_fcoor	new_pos;

	set_position(game->player, &new_pos);
	if (game->player->translation_dir == 1 ||
		game->player->translation_dir == -1)
		translate(game->player, &new_pos);
	tmp.x = new_pos.x;
	tmp.y = game->player->pos.y;
	if (!is_wall(*game->map, tmp, game->setting.tile_size) &&
		!is_sprite(*game->map, tmp, game->setting.tile_size))
		game->player->pos.x = new_pos.x;
	tmp.x = game->player->pos.x;
	tmp.y = new_pos.y;
	if (!is_wall(*game->map, tmp, game->setting.tile_size) &&
		!is_sprite(*game->map, tmp, game->setting.tile_size))
		game->player->pos.y = new_pos.y;
}
