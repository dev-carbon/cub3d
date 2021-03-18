/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:43:34 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:38:08 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_player	*init_player(t_player *player)
{
	player->dir = '\0';
	player->pos.x = -2.0;
	player->pos.y = -2.0;
	player->walk_step = 0;
	player->translation_step = 0;
	player->move_speed = 3;
	player->walk_dir = 0;
	player->translation_dir = 0;
	player->rotation_angle = -2.0;
	player->rotation_speed = 3 * (PI / 180);
	player->rotation_dir = 0;
	return (player);
}
