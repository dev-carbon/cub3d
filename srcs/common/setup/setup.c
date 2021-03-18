/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:43:36 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:56:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

t_game	*setup(const char *file, t_game *game)
{
	if (!(game = init_struct(game)))
		exit_game(EXIT_FAILURE, "Failed allocating sufficient memory.\n", NULL);
	set_config(file, game);
	set_window(game);
	set_map(game);
	set_setting(game);
	set_player(game);
	set_rays(game);
	set_textures(game);
	set_sprites(game);
	return (game);
}
