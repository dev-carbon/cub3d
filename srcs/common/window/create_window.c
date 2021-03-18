/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:38:20 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 12:06:20 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	create_window(t_game *game)
{
	game->window->img.ptr = mlx_new_image(game->window->mlx_ptr,
		game->window->size.width, game->window->size.height);
	game->window->img.data = (int *)mlx_get_data_addr(game->window->img.ptr,
		&game->window->img.bpp, &game->window->img.line_size,
			&game->window->img.endian);
}
