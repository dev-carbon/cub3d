/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:56:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:58:33 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

t_window	*set_window(t_game *game)
{
	t_size	screen_size;

	if (!(game->window->mlx_ptr = mlx_init()))
		exit_game(EXIT_FAILURE, "Unable to init mlx; ", NULL);
	mlx_get_screen_size(game->window->mlx_ptr, &screen_size.width,
		&screen_size.height);
	game->window->size.width = game->config->resolution.width >
		screen_size.width ? screen_size.width : game->config->resolution.width;
	game->window->size.height = game->config->resolution.height >
		screen_size.height ? screen_size.height :
			game->config->resolution.height;
	if (!(game->window->mlx_win = mlx_new_window(game->window->mlx_ptr,
		game->window->size.width, game->window->size.height, NAME)))
		exit_game(EXIT_FAILURE, "Unable to init mlx window; ", NULL);
	return (game->window);
}
