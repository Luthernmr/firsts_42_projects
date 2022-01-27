/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:11:52 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 16:20:09 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;
	size_t	csize;

	if (!s1 || !s2)
		return (NULL);
	csize = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * csize + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i++] = s2[j++];
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;
	size_t	lenstr;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	lenstr = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > lenstr)
		len = lenstr;
	new = (char *)malloc(sizeof(char) * ((unsigned int)len + 1));
	if (!new)
		return (NULL);
	while (str[i + start] && j < len)
	{
		new[j++] = str[i++ + start];
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)chr)
			return ((char *)str + i);
		i++;
	}
	if (chr == 0)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strndup(char *src, int size)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
