/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 02:35:15 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 13:22:36 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_ceiling(t_window win, int top, int x, int color)
{
	int	y;

	y = -1;
	while (++y < top)
		win.img.data[(win.size.width * y) + x] = color;
}

static void	draw_wall(t_wall wall, t_game game, t_ray ray, int x)
{
	int		y;
	int		dist_from_top;
	float	step;
	t_icoor	text_coor;

	if (ray.was_v_hit)
		text_coor.x = (int)(ray.wall_hit.y * wall.texture.size.width /
				game.setting.tile_size) % wall.texture.size.width;
	else
		text_coor.x = (int)(ray.wall_hit.x * wall.texture.size.width /
				game.setting.tile_size) % wall.texture.size.width;
	y = wall.top - 1;
	while (++y < wall.bottom)
	{
		dist_from_top = y + (wall.size.height / 2) -
			(game.window->size.height / 2);
		text_coor.y = dist_from_top * ((float)wall.texture.size.height /
				wall.size.height);
		text_coor = adjust_icoordinate(text_coor, wall.texture.size);
		if (text_coor.x >= 0 && text_coor.x < wall.texture.size.width &&
				text_coor.y >= 0 && text_coor.y < wall.texture.size.height)
			game.window->img.data[(game.window->size.width * y) + x] =
				wall.texture.img.data[(wall.texture.size.width * text_coor.y) +
				text_coor.x];
	}
}

static void	draw_floor(t_window win, int bottom, int x, int color)
{
	int	y;

	y = bottom - 1;
	while (++y < win.size.height)
		win.img.data[win.size.width * y + x] = color;
}

static void	draw_sprites(t_sprite sprite, t_window win, t_ray *rays,
		t_setting setting)
{
	int			x;
	int			y;
	int			color;
	t_icoor		text_coor;

	x = sprite.left.x - 1;
	while (++x < sprite.right.x)
	{
		text_coor.x = (x - sprite.left.x) * (sprite.texture.size.width /
			sprite.width);
		y = sprite.top - 1;
		while (++y < sprite.bottom)
			if (x > 0 && x < win.size.width && y > 0 && y < win.size.height)
			{
				text_coor.y = (y + (sprite.height / 2) - (win.size.height / 2))
					* (sprite.texture.size.height / sprite.height);
				text_coor = adjust_icoordinate(text_coor, sprite.texture.size);
				color = sprite.texture.img.data[text_coor.y *
					sprite.texture.size.width + text_coor.x];
				if (sprite.dist < rays[x].dist_from_wall
					&& color != 0x0 && color != 0xFF00FF)
					win.img.data[y * win.size.width + x] = color;
			}
	}
}

void		render_world3d(t_game *game)
{
	int			i;
	t_wall		wall;
	t_sprite	sprite;

	i = -1;
	while (++i < game->setting.num_rays)
	{
		set_wall_params(*game, *game->window, game->rays[i], &wall);
		draw_ceiling(*game->window, wall.top, i, game->config->color[CEILING]);
		draw_wall(wall, *game, game->rays[i], i);
		draw_floor(*game->window, wall.bottom, i, game->config->color[FLOOR]);
	}
	i = -1;
	while (++i < game->setting.num_visible_sprites)
	{
		set_sprite_params(&game->visible_sprites[i], *game);
		draw_sprites(game->visible_sprites[i], *game->window,
			game->rays, game->setting);
	}
}
