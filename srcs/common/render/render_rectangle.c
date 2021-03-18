/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:18:20 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 12:27:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_rectangle(t_window win, t_icoor start, t_size size, int color)
{
	int		x;
	int		y;

	y = start.y - 1;
	while (++y <= size.height + start.y)
	{
		x = start.x - 1;
		while (++x <= size.width + start.x)
			win.img.data[(y * win.size.width) + x] = color;
	}
}
