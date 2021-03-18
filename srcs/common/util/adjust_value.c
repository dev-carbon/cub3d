/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:38:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/11 18:58:43 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int		adjust_value(int value, int min, int max)
{
	value = value < min ? min : value;
	value = value > max ? max : value;
	return (value);
}
