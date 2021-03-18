/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:52:05 by humanfou          #+#    #+#             */
/*   Updated: 2021/02/19 12:52:07 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include "cub3d.h"

t_wall	*set_wall_params(t_game game, t_window win, t_ray ray, t_wall *wall);

#endif
