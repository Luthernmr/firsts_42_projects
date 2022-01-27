/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_frees1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:47:08 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/06 16:03:49 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;
	size_t	csize;

	if (!s1 || !s2)
		return (NULL);
	csize = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = 0;
	dest = (char *)malloc(sizeof(char) * csize + 1);
	if (!dest)
		return (NULL);
	while (s1[++i])
	{
		dest[i] = s1[i];
	}
	while (s2[j])
	{
		dest[i] = s2[j++];
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}
