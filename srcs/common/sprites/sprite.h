/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:19:11 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:25:54 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cub3d.h"

int			count_sprites(t_map map);
void		update_sprites(t_game *game);
t_sprite	*sort_sprites(t_sprite *sprites, int num_sprites);
t_sprite	*set_sprite_params(t_sprite *sprite, t_game game);

#endif
