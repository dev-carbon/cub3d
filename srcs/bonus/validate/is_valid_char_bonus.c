/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:00:35 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:21:07 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_char(char c)
{
	if (c != 'N' &&
		c != 'E' &&
		c != 'S' &&
		c != 'W' &&
		c != ' ' &&
		c != '0' &&
		c != '1' &&
		c != '2' &&
		c != '3' &&
		c != '4')
		return (FALSE);
	return (TRUE);
}