/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:53:18 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 19:53:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	destroy_config(t_config *config)
{
	int		i;
	t_list	*tmp;

	i = -1;
	config->resolution.width = 0;
	config->resolution.height = 0;
	while (++i < NUM_TEXTURES)
	{
		if (config->texture[i] != NULL)
		{
			free(config->texture[i]);
			config->texture[i] = NULL;
		}
	}
	while (config->scene)
	{
		tmp = config->scene;
		config->scene = config->scene->next;
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
	}
}
