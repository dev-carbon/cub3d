/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:36:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:25:38 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	destroy_vars(char **split, char *trim, char *line)
{
	int	i;

	if (!ft_isdigit(*trim))
	{
		free(line);
		line = NULL;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	free(trim);
	split = NULL;
	trim = NULL;
}
