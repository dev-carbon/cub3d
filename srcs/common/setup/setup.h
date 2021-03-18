/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:50:19 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 19:31:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "cub3d.h"

t_game		*setup(const char *file, t_game *game);
t_config	*set_config(const char *file, t_game *game);
t_setting	set_setting(t_game *game);
t_map		*set_map(t_game *game);
t_window	*set_window(t_game *game);
t_player	*set_player(t_game *game);
t_ray		*set_rays(t_game *game);
t_texture	*set_textures(t_game *game);
t_sprite	*set_sprites(t_game *game);

#endif
