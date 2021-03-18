/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:50:43 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 09:19:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

typedef struct			s_global
{
	int		fd;
	int		ret;
	char	**split;
	char	*trim;
	char	*line;
	char	*buff;
}						t_global;

typedef struct			s_fcoor
{
	float	x;
	float	y;
}						t_fcoor;

typedef struct			s_icoor
{
	int		x;
	int		y;
}						t_icoor;

typedef struct			s_size
{
	int		width;
	int		height;
}						t_size;

typedef struct			s_color
{
	int		r;
	int		g;
	int		b;
}						t_color;

typedef struct			s_image
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		line_size;
	int		endian;
}						t_image;

typedef	struct			s_window
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	img;
	t_size	size;
}						t_window;

typedef struct			s_map
{
	int		**grid;
	t_size	size;
}						t_map;

typedef struct			s_config
{
	t_icoor	start;
	int		color[2];
	int		num_sprites;
	char	*texture[NUM_TEXTURES];
	t_size	resolution;
	t_list	*scene;
}						t_config;

typedef struct			s_setting
{
	int		num_rays;
	int		num_visible_sprites;
	float	fov_angle;
	float	epsilon;
	float	projection_plane_dist;
	float	tile_size;
}						t_setting;

typedef struct			s_player
{
	t_fcoor	pos;
	char	dir;
	int		walk_dir;
	int		look_dir;
	int		translation_dir;
	int		rotation_dir;
	float	walk_step;
	float	translation_step;
	float	move_speed;
	float	rotation_speed;
	float	rotation_angle;
}						t_player;

typedef struct			s_ray
{
	int		found_h_hit;
	int		found_v_hit;
	int		was_h_hit;
	int		was_v_hit;
	float	angle;
	float	dist_from_wall;
	t_fcoor	origin;
	t_fcoor	dir;
	t_fcoor	h_step;
	t_fcoor	h_hit;
	t_fcoor	horz_wall_hit;
	t_fcoor	v_step;
	t_fcoor	v_hit;
	t_fcoor	vert_wall_hit;
	t_fcoor	wall_hit;
}						t_ray;

typedef struct			s_texture
{
	char	*path;
	t_size	size;
	t_image	img;
}						t_texture;

typedef struct			s_wall
{
	int			top;
	int			bottom;
	t_size		size;
	t_texture	texture;
}						t_wall;

typedef struct			s_sprite
{
	int			top;
	int			bottom;
	int			is_visible;
	float		width;
	float		height;
	float		dist;
	float		angle;
	t_size		size;
	t_fcoor		screen_pos;
	t_fcoor		pos;
	t_fcoor		left;
	t_fcoor		right;
	t_texture	texture;
}						t_sprite;

typedef struct			s_game
{
	int			status;
	t_global	*global;
	t_setting	setting;
	t_config	*config;
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_ray		*rays;
	t_texture	textures[NUM_TEXTURES];
	t_sprite	*sprites;
	t_sprite	*visible_sprites;
}						t_game;

#endif
