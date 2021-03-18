/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:41:31 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:38:40 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_setting	init_setting(t_setting setting)
{
	setting.tile_size = -1;
	setting.projection_plane_dist = -1;
	setting.num_rays = -1;
	setting.num_visible_sprites = -1;
	return (setting);
}
