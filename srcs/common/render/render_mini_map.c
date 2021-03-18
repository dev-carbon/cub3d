/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:22:27 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 12:37:14 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_mini_grid(t_map map, t_window win, t_setting setting)
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
				start.x = x * setting.tile_size * MINIMAP_SCALE_FACTOR;
				start.y = y * setting.tile_size * MINIMAP_SCALE_FACTOR;
				size.width = setting.tile_size * MINIMAP_SCALE_FACTOR;
				size.height = setting.tile_size * MINIMAP_SCALE_FACTOR;
				render_rectangle(win, start, size, DARK_GRAY);
			}
		}
	}
}

static void	render_mini_rays(t_ray *rays, t_window win, t_setting setting)
{
	int		i;
	t_icoor	start;
	t_icoor	end;

	i = -1;
	while (++i < setting.num_rays)
	{
		start.x = rays[i].origin.x * MINIMAP_SCALE_FACTOR;
		start.y = rays[i].origin.y * MINIMAP_SCALE_FACTOR;
		end.x = rays[i].wall_hit.x * MINIMAP_SCALE_FACTOR;
		end.y = rays[i].wall_hit.y * MINIMAP_SCALE_FACTOR;
		render_line(win, start, end, LIGHT_GRAY);
	}
}

static void	render_mini_sprites(t_sprite *sprites, t_window win,
	t_config config, t_setting setting)
{
	int		i;
	t_icoor	start;
	t_size	size;

	i = -1;
	while (++i < config.num_sprites)
	{
		start.x = sprites[i].pos.x * MINIMAP_SCALE_FACTOR;
		start.y = sprites[i].pos.y * MINIMAP_SCALE_FACTOR;
		size.width = (setting.tile_size / 4) * MINIMAP_SCALE_FACTOR;
		size.height = (setting.tile_size / 4) * MINIMAP_SCALE_FACTOR;
		if (sprites[i].is_visible)
			render_rectangle(win, start, size, YELLOW);
		else
			render_rectangle(win, start, size, DARK);
	}
}

void		render_mini_map(t_game *game)
{
	render_mini_grid(*game->map, *game->window, game->setting);
	render_mini_rays(game->rays, *game->window, game->setting);
	render_mini_sprites(game->sprites, *game->window, *game->config,
		game->setting);
}
