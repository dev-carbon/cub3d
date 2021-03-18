/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:57:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:24:20 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	keyrelease(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game);
	if (key == KEY_Z)
		game->player->walk_dir = 0;
	if (key == KEY_S)
		game->player->walk_dir = 0;
	if (key == KEY_Q)
		game->player->translation_dir = 0;
	if (key == KEY_D)
		game->player->translation_dir = 0;
	if (key == KEY_RIGHT)
		game->player->rotation_dir = 0;
	if (key == KEY_LEFT)
		game->player->rotation_dir = 0;
	return (0);
}
