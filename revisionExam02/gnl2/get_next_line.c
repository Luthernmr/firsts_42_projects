/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:48:35 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/01 14:41:03 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_substr(char *str, int start,  int size)
{
	int i;
	int len;
	char *dest;
	int j;

	j = 0;
	i = start;
	len = ft_strlen(str) - start;
	if (size > len)
		size = len;
	dest = malloc(sizeof(char) * len + 1);
	while (str[i])
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return(dest);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		size;
	int i;
	int j;

	size = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * size + 1);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0 ;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *read_text(int fd, char *buf, char *str_saved)
{
	int res;
	char *temp_dest;

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
			str_saved = ft_substr("" , 0, 0);
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

char *get_str(char *line)
{
	int i;
	char *str_saved;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i] || !line[1])
		return(NULL);
	str_saved = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!str_saved[0])
	{
		free(str_saved);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (str_saved);
}

char *get_next_line(int fd)
{
	char 		*line;
	static char *str_saved;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = read_text(fd, buf, str_saved);
	free(buf);
	if (!line)
		return (NULL);
	str_saved = get_str(line);
	return (line);
}

























