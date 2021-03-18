/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_fcoordinate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:19:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/11 19:24:32 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_fcoor	adjust_fcoordinate(t_fcoor coor, t_size size)
{
	coor.x = coor.x < 0 ? 0 : coor.x;
	coor.x = coor.x > size.width ? size.width : coor.x;
	coor.y = coor.y < 0 ? 0 : coor.y;
	coor.y = coor.y > size.height ? size.height : coor.y;
	return (coor);
}
