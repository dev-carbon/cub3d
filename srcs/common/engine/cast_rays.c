/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:23:22 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:21:51 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void		set_ray_params(t_ray *ray, float tile_size, float ray_angle,
	t_fcoor origin)
{
	ray->origin = origin;
	ray->angle = normalize_angle(ray_angle);
	ray->dir.x = (ray->angle < 0.5 * PI || ray->angle > 1.5 * PI) ? 1 : -1;
	ray->dir.y = (ray->angle > 0 && ray->angle < PI) ? 1 : -1;
	ray->found_h_hit = 0;
	ray->h_hit.y = floor(ray->origin.y / tile_size) * tile_size;
	ray->h_hit.y += ray->dir.y == 1 ? tile_size : 0;
	ray->h_hit.x = ray->origin.x +
		(ray->h_hit.y - ray->origin.y) / tan(ray->angle);
	ray->h_step.y = tile_size;
	ray->h_step.y *= ray->dir.y == 1 ? 1 : -1;
	ray->h_step.x = tile_size / tan(ray->angle);
	ray->h_step.x *= (ray->dir.x == -1 && ray->h_step.x > 0) ? -1 : 1;
	ray->h_step.x *= (ray->dir.x == 1 && ray->h_step.x < 0) ? -1 : 1;
	ray->found_v_hit = 0;
	ray->v_hit.x = floor(ray->origin.x / tile_size) * tile_size;
	ray->v_hit.x += ray->dir.x == 1 ? tile_size : 0;
	ray->v_hit.y = ray->origin.y + (ray->v_hit.x - ray->origin.x) *
		tan(ray->angle);
	ray->v_step.x = tile_size;
	ray->v_step.x *= ray->dir.x == -1 ? -1 : 1;
	ray->v_step.y = tile_size * tan(ray->angle);
	ray->v_step.y *= (ray->dir.y == 1 && ray->v_step.y < 0) ? -1 : 1;
	ray->v_step.y *= (ray->dir.y == -1 && ray->v_step.y > 0) ? -1 : 1;
}

static t_fcoor	get_horizontal_wall_hit(t_game game, t_window win, t_ray *ray)
{
	t_fcoor	next_hit;
	t_fcoor	to_check;

	next_hit = ray->h_hit;
	while (next_hit.x >= 0 && next_hit.x < win.size.width &&
		next_hit.y >= 0 && next_hit.y < win.size.height)
	{
		to_check.x = next_hit.x;
		to_check.y = next_hit.y + (ray->dir.y == 1 ? 0 : -1);
		if (is_wall(*game.map, to_check, game.setting.tile_size))
		{
			ray->horz_wall_hit = next_hit;
			ray->found_h_hit = 1;
			break ;
		}
		else
		{
			next_hit.x += ray->h_step.x;
			next_hit.y += ray->h_step.y;
		}
	}
	return (next_hit);
}

static t_fcoor	get_vertical_wall_hit(t_game game, t_window win, t_ray *ray)
{
	t_fcoor	next_hit;
	t_fcoor	to_check;

	next_hit = ray->v_hit;
	while (next_hit.x >= 0 && next_hit.x < win.size.width &&
		next_hit.y >= 0 && next_hit.y < win.size.height)
	{
		to_check.x = next_hit.x + (ray->dir.x == -1 ? -1 : 0);
		to_check.y = next_hit.y;
		if (is_wall(*game.map, to_check, game.setting.tile_size))
		{
			ray->vert_wall_hit = next_hit;
			ray->found_v_hit = 1;
			break ;
		}
		else
		{
			next_hit.x += ray->v_step.x;
			next_hit.y += ray->v_step.y;
		}
	}
	return (next_hit);
}

static void		cast_ray(t_game game, t_window win, t_ray *ray, float ray_angle)
{
	float	horz_dist;
	float	vert_dist;

	set_ray_params(ray, game.setting.tile_size, ray_angle, game.player->pos);
	get_horizontal_wall_hit(game, win, ray);
	get_vertical_wall_hit(game, win, ray);
	horz_dist = ray->found_h_hit ?
		distance(ray->origin, ray->horz_wall_hit) : win.size.width;
	vert_dist = ray->found_v_hit ?
		distance(ray->origin, ray->vert_wall_hit) : win.size.height;
	ray->dist_from_wall = horz_dist > vert_dist ? vert_dist : horz_dist;
	ray->wall_hit = horz_dist > vert_dist ? ray->vert_wall_hit :
		ray->horz_wall_hit;
	ray->was_h_hit = vert_dist > horz_dist ? TRUE : FALSE;
	ray->was_v_hit = horz_dist > vert_dist ? TRUE : FALSE;
}

void			cast_rays(t_game *game)
{
	int		i;
	float	ray_angle;

	i = -1;
	ray_angle = game->player->rotation_angle - (game->setting.fov_angle / 2);
	while (++i < game->setting.num_rays)
	{
		cast_ray(*game, *game->window, &game->rays[i], ray_angle);
		ray_angle += game->setting.fov_angle / game->setting.num_rays;
	}
}
