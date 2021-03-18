/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:07:56 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:36:59 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

t_game		*init_struct(t_game *game);
t_global	*init_global(t_global *global);
t_config	*init_config(t_config *config);
t_setting	init_setting(t_setting setting);
t_player	*init_player(t_player *player);
t_ray		*init_rays(t_ray *rays, int num_rays);
t_map		*init_map(t_map *map);
t_sprite	*init_sprite(t_sprite *sprite);

#endif
