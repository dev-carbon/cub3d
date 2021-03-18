/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:17:54 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 12:29:32 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_line(t_window win, t_icoor start, t_icoor end, int color)
{
	int	dx;
	int	dy;
	int	err;

	dx = abs(start.x - end.x);
	dy = -abs(end.y - start.y);
	err = dx + dy;
	while (1)
	{
		win.img.data[(start.y * win.size.width) + start.x] = color;
		if (start.x == end.x && start.y == end.y)
			break ;
		if (2 * err >= dy)
		{
			err += dy;
			start.x += (start.x < end.x) ? 1 : -1;
		}
		if (2 * err <= dx)
		{
			err += dx;
			start.y += (start.y < end.y) ? 1 : -1;
		}
	}
}
