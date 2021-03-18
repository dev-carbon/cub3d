/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:34:51 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:16:01 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		is_valid_color(t_game *g)
{
	t_color	c;

	if (ft_strlen(g->global->split[0]) != 1)
		exit_game(EXIT_FAILURE, "Bad color identifier.", g);
	g->global->buff = ft_strdup(g->global->trim + 1);
	g->global->buff = ft_strremove_spaces(g->global->buff);
	free_split(g->global->split);
	g->global->split = ft_split(g->global->buff, ',');
	free_line(g->global->buff);
	if (ft_split_len(g->global->split) != 3 ||
		!ft_isdigit(*g->global->split[0]))
		exit_game(EXIT_FAILURE, "Bad color format.", g);
	c.r = ft_atoi(g->global->split[0]);
	c.g = ft_atoi(g->global->split[1]);
	c.b = ft_atoi(g->global->split[2]);
	if (c.r < 0 || c.r > 255 || c.g < 0 || c.b > 255 || c.b < 0 || c.b > 255)
		exit_game(EXIT_FAILURE, "Bad color values.", g);
	return (1);
}
