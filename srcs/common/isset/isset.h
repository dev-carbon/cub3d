/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:25:45 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:41:30 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISSET_H
# define ISSET_H

# include "cub3d.h"

int	is_set_config(t_config config, t_game *game);
int	is_set_resolution(t_config config);
int	is_set_texture(t_config config, int texture_id);
int	is_set_color(t_config config, int color_id);
int	is_set_player(t_player player);
int	is_set_map(t_map map);

#endif
