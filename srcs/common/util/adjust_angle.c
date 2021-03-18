/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:59:31 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/11 19:31:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

float	adjust_angle(float angle)
{
	if (angle > PI)
		angle -= PI * 2;
	if (angle < -PI)
		angle += PI * 2;
	return (angle);
}
