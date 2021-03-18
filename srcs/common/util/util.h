/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:43:31 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:46:31 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "cub3d.h"

int		has_player(t_list *scene);
int		is_player(char c);
int		is_wall(t_map map, t_fcoor pos, float tile_size);
int		is_sprite(t_map map, t_fcoor pos, float tile_size);
t_list	*lstadd_scene_line(t_config *config, char *line);
float	normalize_angle(float angle);
int		adjust_value(int value, int min, int max);
float	adjust_angle(float angle);
float	distance(t_fcoor p1, t_fcoor p2);
t_icoor	adjust_icoordinate(t_icoor coor, t_size size);
t_fcoor	adjust_fcoordinate(t_fcoor coor, t_size size);
void	set_start_position(t_config *config, int x, int y);
int		exit_game(int status, const char *msg, t_game *game);
int		close_game(t_game *game);
void	destroy_global(t_global *global);
void	destroy_config(t_config *config);
void	destroy_map(t_map *map);
void	ft_print_params(t_game game);
void	free_split(char **split);
void	free_line(char *line);
void	free_grid(int	**grid, t_size size);

#endif
