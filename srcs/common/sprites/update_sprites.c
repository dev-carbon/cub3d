/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:19:42 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:27:03 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

static t_sprite	*reinit_sprite(t_sprite *sprite)
{
	sprite->top = -1;
	sprite->bottom = -1;
	sprite->size.width = -1;
	sprite->size.height = -1;
	sprite->dist = -1;
	sprite->angle = -1;
	sprite->is_visible = FALSE;
	return (sprite);
}

static void		set_visible_sprite_params(t_sprite *sprite, t_game game,
	float angle)
{
	sprite->is_visible = TRUE;
	sprite->angle = angle;
	sprite->dist = distance(sprite->pos, game.player->pos);
}

void			update_sprites(t_game *game)
{
	int		i;
	float	angle_player_sprite;

	i = -1;
	game->setting.num_visible_sprites = 0;
	while (++i < game->config->num_sprites)
	{
		angle_player_sprite = game->player->rotation_angle -
	atan2(game->sprites[i].pos.y - game->player->pos.y,
		game->sprites[i].pos.x - game->player->pos.x);
		angle_player_sprite = adjust_angle(angle_player_sprite);
		angle_player_sprite = fabs(angle_player_sprite);
		if (angle_player_sprite < (game->setting.fov_angle / 2) +
			game->setting.epsilon)
		{
			set_visible_sprite_params(&game->sprites[i], *game,
				angle_player_sprite);
			game->visible_sprites[game->setting.num_visible_sprites] =
				game->sprites[i];
			game->setting.num_visible_sprites += 1;
		}
		else
			reinit_sprite(&game->sprites[i]);
	}
	sort_sprites(game->visible_sprites, game->setting.num_visible_sprites);
}
