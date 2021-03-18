/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:54:27 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/10 15:54:28 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	free_grid(int **grid, t_size size)
{
	int		j;

	j = -1;
	if (grid != NULL)
	{
		while (++j < size.height)
			free(grid[j]);
		free(grid);
		grid = NULL;
	}
}
