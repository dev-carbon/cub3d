/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:28:45 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/10 14:21:13 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_headers(int fd, t_bmp *bmp, t_window win)
{
	bmp->signature[0] = 'B';
	bmp->signature[1] = 'M';
	bmp->file_size = (win.size.width * win.size.height * 4) + 54;
	bmp->reserved = 0;
	bmp->offset = 54;
	bmp->header_size = 40;
	bmp->image_width = win.size.width;
	bmp->image_height = win.size.height;
	bmp->num_planes = 1;
	bmp->bits_per_pixel = 32;
	bmp->compression = 0;
	bmp->image_size = win.size .width * win.size.height * 4;
	bmp->x_resolution_ppm = 2742;
	bmp->y_resolution_ppm = 2742;
	bmp->num_colors = 0;
	bmp->important_colors = 0;
}

static int	put_headers(int fd, t_bmp bmp)
{
	int		num_bytes;

	num_bytes = 0;
	num_bytes += write(fd, &bmp.signature, 2);
	num_bytes += write(fd, &bmp.file_size, 4);
	num_bytes += write(fd, &bmp.reserved, 4);
	num_bytes += write(fd, &bmp.offset, 4);
	num_bytes += write(fd, &bmp.header_size, 4);
	num_bytes += write(fd, &bmp.image_width, 4);
	num_bytes += write(fd, &bmp.image_height, 4);
	num_bytes += write(fd, &bmp.num_planes, 2);
	num_bytes += write(fd, &bmp.bits_per_pixel, 2);
	num_bytes += write(fd, &bmp.compression, 4);
	num_bytes += write(fd, &bmp.image_size, 4);
	num_bytes += write(fd, &bmp.x_resolution_ppm, 4);
	num_bytes += write(fd, &bmp.y_resolution_ppm, 4);
	num_bytes += write(fd, &bmp.num_colors, 4);
	num_bytes += write(fd, &bmp.important_colors, 4);
	return (num_bytes);
}

static int	put_data(int fd, t_game *game)
{
	int		x;
	int		y;
	int		ret;
	int		color;

	ret = 0;
	y = game->window->size.height;
	while (--y > -1)
	{
		x = -1;
		while (++x < game->window->size.width)
		{
			color = game->window->img.data[y * game->window->size.width + x];
			ret += write(fd, &color, 4);
		}
	}
	return (ret);
}

void		create_bmp(t_game *game)
{
	int		fd;
	int		color;
	t_bmp	bmp;

	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd < 0)
		exit_game(EXIT_FAILURE, "Unable to create bmp file.", game);
	ft_bzero(&bmp, sizeof(t_bmp));
	set_headers(fd, &bmp, *game->window);
	if (put_headers(fd, bmp) != 54)
		exit_game(EXIT_FAILURE, "An error occured while writing file header.",
			game);
	if (put_data(fd, game) != bmp.image_size)
		exit_game(EXIT_FAILURE, "An error occured while writing file data.",
			game);
	close(fd);
}
