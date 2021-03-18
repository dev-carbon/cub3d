/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:42:21 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:49:34 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	set_size(t_map *map, t_list *scene)
{
	t_list	*data;
	char	*rtrim;
	int		len;

	data = scene;
	map->size.width = 0;
	map->size.height = 0;
	while (data != NULL)
	{
		rtrim = ft_strrtrim((char*)data->content, " ");
		len = ft_strlen(rtrim);
		if (map->size.width < len)
			map->size.width = len;
		map->size.height += 1;
		data = data->next;
	}
}

static void	set(t_map *map, int x, int y, char c)
{
	if (c == '0')
		*(*(map->grid + y) + x) = MAP_SPACE;
	else if (c == '1')
		*(*(map->grid + y) + x) = MAP_WALL;
	else if (c == '2')
		*(*(map->grid + y) + x) = MAP_SPRITE;
	else if (is_player(c))
		*(*(map->grid + y) + x) = MAP_PLAYER;
	else
		*(*(map->grid + y) + x) = MAP_UNKNOW;
}

static void	set_content(t_map *map, t_list *lst, t_game *game)
{
	t_icoor	c;
	char	*str;
	t_list	*data;

	c.y = -1;
	data = lst;
	while (++c.y < map->size.height)
	{
		c.x = -1;
		str = (char *)data->content;
		while (++c.x < map->size.width)
		{
			if (c.x < ft_strlen(str))
			{
				if (!is_valid_char(str[c.x]))
					exit_game(EXIT_FAILURE, "Invalid map character.", game);
				if (is_player(str[c.x]))
					set_start_position(game->config, c.x, c.y);
				set(map, c.x, c.y, str[c.x]);
			}
			else
				*(*(map->grid + c.y) + c.x) = MAP_UNKNOW;
		}
		data = data->next;
	}
}

static int	**copy_grid(int **src, int width, int height)
{
	int	x;
	int	y;
	int	**grid;

	if (!(grid = (int **)malloc(sizeof(int*) * height)))
		return (NULL);
	y = -1;
	while (++y < height)
		if (!(*(grid + y) = (int *)malloc(sizeof(int) * width)))
			return (NULL);
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			*(*(grid + y) + x) = *(*(src + y) + x);
		}
	}
	return (grid);
}

t_map		*set_map(t_game *game)
{
	int	y;
	int	**copy;

	set_size(game->map, game->config->scene);
	if (!(game->map->grid = (int **)malloc(sizeof(int*) *
		game->map->size.height)))
		return (NULL);
	y = -1;
	while (++y < (int)game->map->size.height)
		if (!(*(game->map->grid + y) = (int *)malloc(sizeof(int) *
			game->map->size.width)))
			return (NULL);
	set_content(game->map, game->config->scene, game);
	copy = copy_grid(game->map->grid, game->map->size.width,
		game->map->size.height);
	if (!is_valid_map(game->config->start.x,
		game->config->start.y, copy, *game->map))
	{
		free_grid(copy, game->map->size);
		exit_game(EXIT_FAILURE, "Map is not correctly bordered; ", game);
	}
	free_grid(copy, game->map->size);
	return (game->map);
}
