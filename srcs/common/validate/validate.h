/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:12:07 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:20:13 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "cub3d.h"

int	is_valid_args(const int ac, const char *av[]);
int	is_valid_extension(const char *filename, const char *ext);
int	is_valid_resolution(t_game *game);
int	is_valid_texture(t_game *game);
int	is_valid_color(t_game *game);
int	is_valid_map(int x, int y, int **grid, t_map map);
int	is_valid_char(char c);

#endif
