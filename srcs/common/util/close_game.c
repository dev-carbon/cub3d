/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:24:55 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:24:27 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	close_game(t_game *game)
{
	mlx_clear_window(game->window->mlx_ptr, game->window->mlx_win);
	mlx_destroy_window(game->window->mlx_ptr, game->window->mlx_win);
	exit_game(EXIT_SUCCESS, "GoodBye!", game);
}
