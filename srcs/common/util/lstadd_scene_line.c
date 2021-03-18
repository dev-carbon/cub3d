/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_scene_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:05:50 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:25:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_list	*lstadd_scene_line(t_config *config, char *line)
{
	t_list	*new;
	t_list	*last;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = ft_strrtrim(line, " ");
	new->next = NULL;
	if (config->scene == NULL)
		config->scene = new;
	else
	{
		last = config->scene;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (config->scene);
}
