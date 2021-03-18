/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:47:32 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:45:04 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isset.h"

int	is_set_texture(t_config config, int id)
{
	if (config.texture[id] != NULL)
		return (1);
	return (0);
}
