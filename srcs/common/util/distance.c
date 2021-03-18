/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 01:16:31 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/11 19:31:09 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

float	distance(t_fcoor p1, t_fcoor p2)
{
	return (sqrt((p2.x - p1.x) * (p2.x - p1.x) +
	(p2.y - p1.y) * (p2.y - p1.y)));
}
