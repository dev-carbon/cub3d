/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:20:35 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:54:12 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	set_dir(t_player *player, t_list *lst, t_map map)
{
	int		x;
	int		y;
	char	*str;
	t_list	*data;

	y = -1;
	data = lst;
	while (++y < map.size.height)
	{
		x = -1;
		str = (char *)data->content;
		while (++x < map.size.width && x < ft_strlen(str))
		{
			if (is_player(str[x]))
			{
				if (is_set_player(*player))
					exit_game(EXIT_FAILURE, "Multiple declaration of player.",
						NULL);
				player->dir = str[x];
			}
		}
		data = data->next;
	}
	if (!is_set_player(*player))
		exit_game(EXIT_FAILURE, "Missing player position.", NULL);
}

static void	set_position(t_player *player, t_map map, t_setting setting)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.size.height)
	{
		x = 0;
		while (x < map.size.width)
		{
			if (*(*(map.grid + y) + x) == MAP_PLAYER)
			{
				player->pos.x = x * setting.tile_size;
				player->pos.y = y * setting.tile_size;
				*(*(map.grid + y) + x) = MAP_SPACE;
				break ;
			}
			x++;
		}
		y++;
	}
}

static void	set_rotation_angle(t_player *player)
{
	if (player->dir == 'N')
		player->rotation_angle = PI / 2;
	if (player->dir == 'S')
		player->rotation_angle = (3 * PI) / 2;
	if (player->dir == 'E')
		player->rotation_angle = 0;
	if (player->dir == 'W')
		player->rotation_angle = PI;
}

t_player	*set_player(t_game *game)
{
	set_dir(game->player, game->config->scene, *game->map);
	set_position(game->player, *game->map, game->setting);
	set_rotation_angle(game->player);
	return (game->player);
}
