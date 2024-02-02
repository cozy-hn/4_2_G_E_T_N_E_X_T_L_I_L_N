/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:33:10 by jiko              #+#    #+#             */
/*   Updated: 2023/07/17 02:39:29 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (flag)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	dest = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dest)
		return (freeing(0, s1, NULL));
	while (s1[++i])
		dest[i] = s1[i];
	free(s1);
	while (s2[j])
		dest[i++] = s2[j++];
	return (dest);
}

char	*ft_get_line(char **str, int *i, int fd)
{
	char	*dest;

	*i = 0;
	while ((*(str + fd))[*i] && (*(str + fd))[*i] != '\n')
		(*i)++;
	if ((*(str + fd))[*i] == '\0')
	{
		dest = ft_strjoin(0, (*(str + fd)), 1);
		if (!dest)
			return (NULL);
		return (dest);
	}
	dest = (char *)ft_calloc(*i + 2, sizeof(char));
	if (!dest)
		return (NULL);
	*i = 0;
	while ((*(str + fd))[*i] != '\n')
		dest[(*i)++] = (*(str + fd))[*i];
	dest[(*i)++] = '\n';
	return (dest);
}

char	*freeing(char **str, char *buf, char *dest)
{
	if (buf)
		free(buf);
	if (dest)
		free(dest);
	if (!str)
		return (0);
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (NULL);
}

int	readline(int fd, int *i, char **str)
{
	char	*buf;

	*i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX_GNL)
		return ((int)free_openmax(str));
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return ((int)freeing(str + fd, NULL, NULL));
	while (*i > 0)
	{
		if (ft_strchr(*(str + fd), '\n'))
			break ;
		*i = read(fd, buf, BUFFER_SIZE);
		if ((!(*(str + fd)) && *i == 0) || *i < 0)
			return ((int)freeing((str + fd), buf, NULL));
		buf[*i] = '\0';
		*(str + fd) = ft_strjoin(*(str + fd), buf, !(int)(*(str + fd)));
		if (!(*(str + fd)))
			return ((int)freeing(0, buf, NULL));
	}
	freeing(&buf, NULL, NULL);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX_GNL + 1];
	char		*buf;
	char		*dest;
	int			i;
	int			flag;

	buf = NULL;
	flag = readline(fd, &i, &str[0]);
	if (!flag)
		return (NULL);
	dest = ft_get_line(&str[0], &i, fd);
	if (dest && (ft_strlen(str[fd]) != ft_strlen(dest)))
	{
		buf = ft_strjoin(NULL, str[fd] + i, 1);
		if (!buf)
			return (freeing(&str[fd], NULL, dest));
	}
	free(str[fd]);
	str[fd] = buf;
	return (dest);
}
