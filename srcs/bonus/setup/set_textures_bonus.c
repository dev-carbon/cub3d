/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:36:12 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:52:02 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static t_texture	*load_texture(t_window win, t_texture *texture)
{
	if (!(texture->img.ptr = mlx_xpm_file_to_image(win.mlx_ptr, texture->path,
		&texture->size.width, &texture->size.height)))
		return (NULL);
	if (!(texture->img.data = (int*)mlx_get_data_addr(texture->img.ptr,
		&texture->img.bpp, &texture->img.line_size, &texture->img.endian)))
		return (NULL);
	return (texture);
}

t_texture			*set_textures(t_game *game)
{
	game->textures[TN].path = game->config->texture[TN];
	game->textures[TS].path = game->config->texture[TS];
	game->textures[TE].path = game->config->texture[TE];
	game->textures[TW].path = game->config->texture[TW];
	game->textures[TSP1].path = game->config->texture[TSP1];
	game->textures[TSP2].path = game->config->texture[TSP2];
	game->textures[TSP3].path = game->config->texture[TSP3];
	if (!(load_texture(*game->window, &game->textures[TN])))
		exit_game(EXIT_FAILURE, "Unable to load texture north", game);
	if (!(load_texture(*game->window, &game->textures[TS])))
		exit_game(EXIT_FAILURE, "Unable to load texture south", game);
	if (!(load_texture(*game->window, &game->textures[TE])))
		exit_game(EXIT_FAILURE, "Unable to load texture east", game);
	if (!(load_texture(*game->window, &game->textures[TW])))
		exit_game(EXIT_FAILURE, "Unable to load texture west", game);
	if (!(load_texture(*game->window, &game->textures[TSP1])))
		exit_game(EXIT_FAILURE, "Unable to load texture sprite 1", game);
	if (!(load_texture(*game->window, &game->textures[TSP2])))
		exit_game(EXIT_FAILURE, "Unable to load texture sprite 2", game);
	if (!(load_texture(*game->window, &game->textures[TSP3])))
		exit_game(EXIT_FAILURE, "Unable to load texture sprite 3\n", game);
	return (game->textures);
}
