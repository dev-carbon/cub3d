/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 01:25:47 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:54:37 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

t_ray	*set_rays(t_game *game)
{
	if (!(game->rays = (t_ray *)malloc(sizeof(t_ray) *
	game->setting.num_rays)))
		return (NULL);
	init_rays(game->rays, game->setting.num_rays);
	return (game->rays);
}
