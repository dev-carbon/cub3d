/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:39:11 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:43:01 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

t_sprite	*sort_sprites(t_sprite *sprites, int num_sprites)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = -1;
	while (++i < num_sprites)
	{
		j = -1;
		while (++j < num_sprites)
		{
			if (sprites[i].dist > sprites[j].dist)
			{
				tmp = sprites[i];
				sprites[i] = sprites[j];
				sprites[j] = tmp;
			}
		}
	}
	return (sprites);
}
