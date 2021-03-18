/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:53:06 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:39:54 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_game	*init_struct(t_game *game)
{
	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	if (!(game->config = (t_config *)malloc(sizeof(t_config))))
		return (NULL);
	if (!(game->window = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	if (!(game->map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(game->player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	if (!(game->global = (t_global *)malloc(sizeof(t_global))))
		return (NULL);
	init_global(game->global);
	init_config(game->config);
	init_setting(game->setting);
	init_map(game->map);
	init_player(game->player);
	return (game);
}
