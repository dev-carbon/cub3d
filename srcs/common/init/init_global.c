/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:02:06 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/10 14:22:27 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_global	*init_global(t_global *global)
{
	global->split = NULL;
	global->trim = NULL;
	global->line = NULL;
	return (global);
}
