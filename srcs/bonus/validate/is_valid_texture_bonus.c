/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:52:04 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:17:12 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		is_valid_texture(t_game *game)
{
	int	len;

	if (ft_split_len(game->global->split) != 2)
		exit_game(EXIT_FAILURE, "Bad texture format.", game);
	len = ft_strlen(game->global->split[0]);
	if (len != 2 && len != 1)
		exit_game(EXIT_FAILURE, "Bad texture identifier.", game);
	if (len == 1 && *game->global->split[0] != 'S')
		exit_game(EXIT_FAILURE, "Bad sprite texture identifier .", game);
	return (1);
}
