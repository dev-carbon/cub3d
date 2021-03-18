/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 04:36:09 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 16:24:15 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void	print_message(int status, const char *msg)
{
	if (msg != NULL && *msg != '\0')
	{
		if (status == EXIT_FAILURE)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			ft_putstr_fd((char*)msg, STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
		}
		if (status == EXIT_SUCCESS)
		{
			ft_putstr_fd("Success\n", STDOUT_FILENO);
			ft_putstr_fd((char*)msg, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
	}
}

int			exit_game(int status, const char *msg, t_game *game)
{
	print_message(status, msg);
	exit(status);
}
