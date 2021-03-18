/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:44:39 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/11 19:36:53 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	run(t_game *game)
{
	mlx_hook(game->window->mlx_win, 2, 1L << 0, &keypress, game);
	mlx_hook(game->window->mlx_win, 3, 1L << 1, &keyrelease, game);
	mlx_hook(game->window->mlx_win, 33, 1L << 17, &close_game, game);
	mlx_loop_hook(game->window->mlx_ptr, &cub3d_loop, game);
	mlx_loop(game->window->mlx_ptr);
	return (0);
}

static int	save(t_game *game)
{
	cub3d_listen(game);
	cub3d_update(game);
	cub3d_render(game);
	create_bmp(game);
	exit_game(EXIT_SUCCESS, "Screenshot saved.", game);
	return (0);
}

int			main(const int argc, const char *argv[])
{
	t_game	*game;

	if (is_valid_args(argc, argv) && (game = setup(argv[1], game)))
		argc == 3 ? save(game) : run(game);
	return (0);
}
