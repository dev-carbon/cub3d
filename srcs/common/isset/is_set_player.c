/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:04:54 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:42:54 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isset.h"

int	is_set_player(t_player player)
{
	if (player.dir != '\0')
		return (TRUE);
	return (FALSE);
}
