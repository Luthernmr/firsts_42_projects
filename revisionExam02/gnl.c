/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:50:17 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 16:02:21 by lnemor           ###   ########lyon.fr   */
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
	dest = malloc(sizeof(char) * size);
	while (src[i])
	{
		dest[i] = src[i]
		i++;
	}
	dest[i] = '\0';
	return(dest);

}
