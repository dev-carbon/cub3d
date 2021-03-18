/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:56:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:23:14 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	keypress(int key, t_game *game)
{
	if (key == KEY_Z)
		game->player->walk_dir = +1;
	if (key == KEY_S)
		game->player->walk_dir = -1;
	if (key == KEY_D)
		game->player->translation_dir = +1;
	if (key == KEY_Q)
		game->player->translation_dir = -1;
	if (key == KEY_RIGHT)
		game->player->rotation_dir = +1;
	if (key == KEY_LEFT)
		game->player->rotation_dir = -1;
	return (0);
}
