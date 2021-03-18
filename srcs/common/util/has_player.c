/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:30:27 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/18 15:32:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	has_player(t_list *scene)
{
	char	*s;
	t_list	*head;

	head = scene;
	while (head != NULL)
	{
		s = (char *)head->content;
		if (ft_strchr(s, 'N') != NULL)
			return (1);
		if (ft_strchr(s, 'S') != NULL)
			return (1);
		if (ft_strchr(s, 'E') != NULL)
			return (1);
		if (ft_strchr(s, 'W') != NULL)
			return (1);
		head = head->next;
	}
	return (0);
}
