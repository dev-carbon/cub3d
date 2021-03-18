/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:29:58 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 09:35:06 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "cub3d.h"

typedef struct			s_bmp
{
	char				signature[2];
	unsigned int		file_size;
	unsigned int		reserved;
	unsigned int		offset;
	unsigned int		header_size;
	int					image_width;
	int					image_height;
	unsigned short		num_planes;
	unsigned short		bits_per_pixel;
	unsigned int		compression;
	unsigned int		image_size;
	int					x_resolution_ppm;
	int					y_resolution_ppm;
	unsigned int		num_colors;
	unsigned int		important_colors;
}						t_bmp;

void					create_bmp(t_game *game);

#endif
