/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:19:11 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/10 14:24:10 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	set_resolution(t_config *config, t_game *g)
{
	if (is_set_resolution(*config))
		exit_game(EXIT_FAILURE, "Multiple definition of resolution.", g);
	config->resolution.width = ft_atoi(g->global->split[1]);
	config->resolution.height = ft_atoi(g->global->split[2]);
}

static void	set_texture(t_config *config, t_game *g, int id)
{
	if (is_set_texture(*config, id))
		exit_game(EXIT_FAILURE, "Multiple definition of texture.", g);
	config->texture[id] = ft_strdup(g->global->split[1]);
}

static void	set_color(t_config *config, t_game *g, int id)
{
	int		i;
	int		color;

	if (is_set_color(*config, id))
		exit_game(EXIT_FAILURE, "Multiple definition of color.", g);
	i = 0;
	g->global->buff = ft_strdup(g->global->trim + 1);
	g->global->buff = ft_strremove_spaces(g->global->buff);
	free_split(g->global->split);
	g->global->split = ft_split(g->global->buff, ',');
	free_line(g->global->buff);
	color = ft_atoi(g->global->split[0]);
	color = (color << 8) + ft_atoi(g->global->split[1]);
	color = (color << 8) + ft_atoi(g->global->split[2]);
	config->color[id] = color;
}

static void	set(t_config *config, t_game *g)
{
	if (ft_strncmp(g->global->trim, "R", 1) == 0 && is_valid_resolution(g))
		set_resolution(config, g);
	else if (ft_strncmp(g->global->trim, "NO", 2) == 0 && is_valid_texture(g))
		set_texture(config, g, TN);
	else if (ft_strncmp(g->global->trim, "SO", 2) == 0 && is_valid_texture(g))
		set_texture(config, g, TS);
	else if (ft_strncmp(g->global->trim, "EA", 2) == 0 && is_valid_texture(g))
		set_texture(config, g, TE);
	else if (ft_strncmp(g->global->trim, "WE", 2) == 0 && is_valid_texture(g))
		set_texture(config, g, TW);
	else if (ft_strncmp(g->global->trim, "S", 1) == 0 && is_valid_texture(g))
		set_texture(config, g, TSP);
	else if (ft_strncmp(g->global->trim, "C", 1) == 0 && is_valid_color(g))
		set_color(config, g, CEILING);
	else if (ft_strncmp(g->global->trim, "F", 1) == 0 && is_valid_color(g))
		set_color(config, g, FLOOR);
	else if (ft_isdigit(*g->global->trim) && is_set_config(*config, g))
		lstadd_scene_line(config, g->global->line);
	else if (g->config->scene != NULL && g->global->ret == 1)
		exit_game(EXIT_FAILURE, "Bad scene descrition.", g);
}

t_config	*set_config(const char *file, t_game *g)
{
	if ((g->global->fd = open(file, O_RDONLY)) == -1)
		exit_game(EXIT_FAILURE, "Unable to open map file.\n", g);
	while (TRUE)
	{
		g->global->ret = get_next_line(g->global->fd,
			&g->global->line);
		g->global->trim = ft_strtrim(g->global->line, " ");
		g->global->split = ft_split(g->global->trim, ' ');
		set(g->config, g);
		if (!ft_isdigit(*g->global->trim))
			free_line(g->global->line);
		free_line(g->global->trim);
		free_split(g->global->split);
		if (g->global->ret == 0 || g->global->ret == -1)
			break ;
	}
	if (!has_player(g->config->scene))
		exit_game(EXIT_FAILURE, "Missing player's initial position.\n", g);
	return (g->config);
}
