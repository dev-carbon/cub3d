/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:34:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 14:38:37 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	unsigned int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char			*start;
	char			*end;
	char			*ret;
	int				len;
	unsigned int	i;

	if (!s1)
		return (0);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (check_set(*start, set))
		start++;
	if (start < end)
		end--;
	while (check_set(*end, set))
		end--;
	len = end - start + 1;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len-- > 0)
		ret[i++] = *start++;
	ret[i] = '\0';
	return (ret);
}
