/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:21:39 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/12 16:06:54 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static char	*read_text(int fd, char *buf, char *str_saved)
{
	int		res;
	char	*temp_dest;

	res = 1;
	while (res != 0)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res < 0)
			return (NULL);
		else if (res == 0)
			return (str_saved);
		buf[res] = '\0';
		if (!str_saved)
			str_saved = ft_strdup("");
		temp_dest = str_saved;
		str_saved = ft_strjoin(temp_dest, buf);
		free(temp_dest);
		if (!str_saved)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			return (str_saved);
	}
	return (str_saved);
}

static char	*get_str(char *line)
{
	size_t	start;
	char	*str_saved;

	start = 0;
	while (line[start] != '\n' && line[start])
		start++;
	if (!line[start] || !line[1])
		return (NULL);
	str_saved = ft_substr(line, start + 1, ft_strlen(line) - start);
	if (!str_saved[0])
	{
		free(str_saved);
		return (NULL);
	}
	line[start + 1] = '\0';
	return (str_saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*str_saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_text(fd, buf, str_saved);
	free(buf);
	if (!line)
		return (NULL);
	str_saved = get_str(line);
	return (line);
}
