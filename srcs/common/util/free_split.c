/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 23:19:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:26:51 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	free_split(char **split)
{
	int	i;

	if (split != NULL)
	{
		i = -1;
		while (split[++i])
			free_line(split[i]);
		free_line(split[i]);
		free(split);
		split = NULL;
	}
}
