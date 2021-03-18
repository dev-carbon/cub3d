/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:10:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:13:44 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_args(const int ac, const char *av[])
{
	if (ac < 2 || ac > 3)
		exit_game(EXIT_FAILURE, "Bad number of arguments; ", NULL);
	if (!is_valid_extension(av[1], EXTENSION))
		exit_game(EXIT_FAILURE, "Bad file extension; ", NULL);
	if (ac == 3 && (ft_strncmp(av[2], "--save", 6) != 0))
		exit_game(EXIT_FAILURE, "Bad arguments format; ", NULL);
	return (1);
}
