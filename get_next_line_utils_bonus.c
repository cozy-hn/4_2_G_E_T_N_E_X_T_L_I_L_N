/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:33:12 by jiko              #+#    #+#             */
/*   Updated: 2023/07/17 01:01:08 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*rtm;
	size_t			idx;

	idx = size * count;
	rtm = malloc(idx);
	if (!rtm)
		return (NULL);
	while (idx--)
		rtm[idx] = 0;
	return (rtm);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*free_openmax(char **str)
{
	int	idx;

	idx = 0;
	while (idx <= OPEN_MAX_GNL)
	{
		if (str[idx])
			free(str[idx]);
		idx++;
	}
	return (NULL);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
