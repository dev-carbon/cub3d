/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:49:12 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 12:34:43 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_grid(t_map map, t_window win, t_setting setting)
{
	int		x;
	int		y;
	t_icoor	start;
	t_size	size;

	y = -1;
	while (++y < map.size.height)
	{
		x = -1;
		while (++x < map.size.width)
		{
			if (*(*(map.grid + y) + x) == MAP_WALL)
			{
				start.x = x * setting.tile_size;
				start.y = y * setting.tile_size;
				size.width = setting.tile_size;
				size.height = setting.tile_size;
				render_rectangle(win, start, size, DARK);
			}
		}
	}
}

static void	render_rays(t_ray *rays, t_window win, t_setting setting)
{
	int		i;
	t_icoor	start;
	t_icoor	end;

	i = -1;
	while (++i < setting.num_rays)
	{
		start.x = rays[i].origin.x;
		start.y = rays[i].origin.y;
		end.x = rays[i].wall_hit.x;
		end.y = rays[i].wall_hit.y;
		render_line(win, start, end, LIGHT_GRAY);
	}
}

static void	render_sprites(t_sprite *sprites, t_window win, t_config config,
	t_setting setting)
{
	int		i;
	t_icoor	start;
	t_size	size;

	i = -1;
	while (++i < config.num_sprites)
	{
		start.x = sprites[i].pos.x;
		start.y = sprites[i].pos.y;
		size.width = (setting.tile_size / 4);
		size.height = (setting.tile_size / 4);
		if (sprites[i].is_visible)
			render_rectangle(win, start, size, YELLOW);
		else
			render_rectangle(win, start, size, DARK);
	}
}

void		render_map(t_game *game)
{
	render_grid(*game->map, *game->window, game->setting);
	render_rays(game->rays, *game->window, game->setting);
	render_sprites(game->sprites, *game->window, *game->config, game->setting);
}
