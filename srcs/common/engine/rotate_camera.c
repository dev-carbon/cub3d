/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:23:29 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 09:53:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	rotate_camera(t_player *player)
{
	player->rotation_angle += player->rotation_dir *
		player->rotation_speed;
	player->rotation_angle = normalize_angle(player->rotation_angle);
}
