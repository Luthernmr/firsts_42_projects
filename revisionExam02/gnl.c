/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:50:17 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 17:48:52 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int	size;
	char	*dest;
	int	i;

	i = 0;
	size = ft_strlen(src);
	dest = malloc(sizeof(char) * size + 1);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

char *ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *) str + i);
		i++;
	}
	if (c == 0)
		return((char *)str + i);
	return(NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int	j;
	char *dest;
	int size;

	size = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * size + 1);
	i = 0; 
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return(dest);
}

char *ft_substr(char *str, int start, int size)
{
	int i;
	int	j;
	char *dest;
	int	len;

	i = start;
	j = 0;
	len = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
		return(ft_strdup(""));
	if (len > size)
		len = size;
	dest = malloc(sizeof(char) * len + 1);
	while (str[i] && j < len)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
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

char *get_str(char *line)
{
	int start;
	char *str_saved;

	start = 0;
	while (line[start] != '\n' && line[start])
		start++;
	if (!line[start] || !line[1])
		return(NULL);
	str_saved = ft_substr(line, start + 1, ft_strlen(line) - start);
	if (!str_saved[0])
	{
		free(str_saved);
		return (NULL);
	}
	line[start + 1] = '\0';
	return (str_saved);
}
char *gnl(int fd)
{
	char *line;
	char *buf;
	static char	*str_saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_text(fd, buf, str_saved);
	free(buf);
	if (!line)
		return (NULL);
	str_saved = get_str(line);
	return (line);
}

int main()
{
	char	*line;
	int		fd;

	fd = open("bible.txt", O_RDONLY);
	line = gnl(fd);
	printf("%s", line);
	while (line)
	{
		free(line);
		line = gnl(fd);
		printf("%s", line);
	}
}

















