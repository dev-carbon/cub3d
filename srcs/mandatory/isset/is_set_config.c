/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:03:53 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:45:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isset.h"

int	is_set_config(t_config config, t_game *game)
{
	if (!is_set_resolution(config))
		exit_game(EXIT_FAILURE, "Resolution is not set.", game);
	else if (!is_set_texture(config, TN))
		exit_game(EXIT_FAILURE, "Texture north is not set.", game);
	else if (!is_set_texture(config, TS))
		exit_game(EXIT_FAILURE, "Texture south is not set.", game);
	else if (!is_set_texture(config, TE))
		exit_game(EXIT_FAILURE, "Texture east is not set.", game);
	else if (!is_set_texture(config, TW))
		exit_game(EXIT_FAILURE, "Texture west is not set.", game);
	else if (!is_set_texture(config, TSP))
		exit_game(EXIT_FAILURE, "Texture sprite is not set.", game);
	else if (!is_set_color(config, CEILING))
		exit_game(EXIT_FAILURE, "Ceiling color is not set.", game);
	else if (!is_set_color(config, FLOOR))
		exit_game(EXIT_FAILURE, "Floor color is not set.", game);
	return (1);
}
