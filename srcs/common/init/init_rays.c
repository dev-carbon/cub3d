/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:33:04 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/11 18:33:06 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_ray	*init_rays(t_ray *rays, int num_rays)
{
	int	i;

	i = -1;
	while (++i < num_rays)
	{
		rays[i].dist_from_wall = -1;
		rays[i].found_h_hit = 0;
		rays[i].found_v_hit = 0;
		rays[i].angle = 0;
		rays[i].dir.x = 0;
		rays[i].dir.y = 0;
		rays[i].wall_hit.x = 0;
		rays[i].wall_hit.y = 0;
		rays[i].v_hit.x = 0;
		rays[i].v_hit.y = 0;
		rays[i].horz_wall_hit.x = 0;
		rays[i].horz_wall_hit.y = 0;
		rays[i].vert_wall_hit.x = 0;
		rays[i].vert_wall_hit.y = 0;
	}
	return (rays);
}
