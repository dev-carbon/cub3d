/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 01:43:17 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 12:05:12 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	refresh_window(t_game *game)
{
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->mlx_win,
		game->window->img.ptr, 0, 0);
	mlx_destroy_image(game->window->mlx_ptr, game->window->img.ptr);
}
