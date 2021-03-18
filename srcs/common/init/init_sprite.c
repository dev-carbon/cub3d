/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:14:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:39:29 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_sprite	*init_sprite(t_sprite *sprite)
{
	sprite->top = -1;
	sprite->bottom = -1;
	sprite->size.width = -1;
	sprite->size.height = -1;
	sprite->pos.x = -1;
	sprite->pos.y = -1;
	sprite->dist = -1;
	sprite->angle = -1;
	sprite->is_visible = FALSE;
	return (sprite);
}
