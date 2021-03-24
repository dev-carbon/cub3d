/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:31:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/10 14:31:44 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_listen(t_game *game)
{
	if (game->player->walk_dir == 1)
		move_camera(game);
	if (game->player->walk_dir == -1)
		move_camera(game);
	if (game->player->translation_dir == 1)
		move_camera(game);
	if (game->player->translation_dir == -1)
		move_camera(game);
	if (game->player->rotation_dir == 1)
		rotate_camera(game->player);
	if (game->player->rotation_dir == -1)
		rotate_camera(game->player);
	return (0);
}

int	cub3d_update(t_game *game)
{
	cast_rays(game);
	update_sprites(game);
	return (0);
}

int	cub3d_render(t_game *game)
{
	create_window(game);
	render_world3d(game);
	return (0);
}

int	cub3d_loop(t_game *game)
{
	cub3d_listen(game);
	cub3d_update(game);
	cub3d_render(game);
	refresh_window(game);
	return (0);
}
