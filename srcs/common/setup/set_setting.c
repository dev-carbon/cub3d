/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:48:50 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:50:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

t_setting	set_setting(t_game *game)
{
	int	min;
	int	max;

	min = ft_min(game->window->size.width, game->window->size.height);
	max = ft_max(game->map->size.width, game->map->size.height);
	game->setting.fov_angle = 60 * (PI / 180);
	game->setting.epsilon = 3 * (PI / 180);
	game->setting.tile_size = min / max;
	game->setting.projection_plane_dist = (game->window->size.width / 2) /
		tan(game->setting.fov_angle / 2);
	game->setting.num_rays = game->window->size.width;
	return (game->setting);
}
