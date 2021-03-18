/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:23:57 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:16:54 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_resolution(t_game *game)
{
	int	width;
	int	height;

	if (ft_strlen(game->global->split[0]) != 1)
		exit_game(EXIT_FAILURE, "Invalid resolution identifier; ", game);
	if (ft_split_len(game->global->split) != 3)
		exit_game(EXIT_FAILURE, "Invalid resolution format; ", game);
	width = ft_atoi(game->global->split[1]);
	height = ft_atoi(game->global->split[2]);
	if (width <= 0 || height <= 0)
		exit_game(EXIT_FAILURE, "Invalid resolution value; ", game);
	return (1);
}
