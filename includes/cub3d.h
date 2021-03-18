/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:49:54 by humanfou          #+#    #+#             */
/*   Updated: 2020/12/02 10:49:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include "mlx.h"
# include "libft.h"
# include "const.h"
# include "struct.h"
# include "init.h"
# include "util.h"
# include "validate.h"
# include "setup.h"
# include "engine.h"
# include "render.h"
# include "event.h"
# include "colors.h"
# include "window.h"
# include "sprite.h"
# include "wall.h"
# include "bmp.h"
# include "isset.h"

int cub3d_loop(t_game *game);
int cub3d_listen(t_game *game);
int cub3d_update(t_game *game);
int cub3d_render(t_game *game);

#endif
