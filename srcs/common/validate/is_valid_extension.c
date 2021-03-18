/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:26:53 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:19:33 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_extension(const char *filename, const char *ext)
{
	int		index;
	int		len;
	char	*buff;

	buff = (char *)filename;
	len = ft_strlen(ext);
	index = ft_strlen(buff) - len;
	if (ft_strncmp(buff + index, ext, len) != 0)
		return (0);
	return (1);
}
