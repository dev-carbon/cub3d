/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:48:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:47:08 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

void	render_line(t_window win, t_icoor start, t_icoor end, int color);
void	render_rectangle(t_window win, t_icoor start, t_size size, int color);
void	render_map(t_game *game);
void	render_mini_map(t_game *game);
void	render_world3d(t_game *game);

#endif
