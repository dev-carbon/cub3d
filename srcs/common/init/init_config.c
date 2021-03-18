/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:40:27 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:37:41 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_config	*init_config(t_config *config)
{
	int		i;

	i = -1;
	config->resolution.width = -1;
	config->resolution.height = -1;
	while (++i < NUM_TEXTURES)
		config->texture[i] = NULL;
	config->color[CEILING] = -1;
	config->color[FLOOR] = -1;
	config->scene = NULL;
	return (config);
}
