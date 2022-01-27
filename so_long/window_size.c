/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:35:43 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/14 18:49:39 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_window_size(t_program *program, char **dest)
{
	int	i;
	int	j;

	i = 0;
	program->nb_coin = 0;
	program->width = 0;
	program->hight = 0;
	while (dest[i] != 0)
	{
		program->hight += 32;
		i++;
	}
	j = 0;
	while (dest[0][j])
	{
		program->width += 32;
		j++;
	}
}
