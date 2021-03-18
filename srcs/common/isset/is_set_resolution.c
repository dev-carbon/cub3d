/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:33:07 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:45:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isset.h"

int	is_set_resolution(t_config config)
{
	if (config.resolution.width > 0 && config.resolution.height > 0)
		return (1);
	return (0);
}
