/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:27:31 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/17 16:57:12 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	position_player(t_program *program, int x, int y)
{	
	program->position_x = x;
	program->position_y = y;
	mlx_put_image_to_window(program->mlx_pointer, program->window,
		program->image.avatar_back, program->position_x,
		program->position_y);
}

static void	position_c(t_program *program)
{
	mlx_put_image_to_window(program->mlx_pointer,
		program->window, program->image.coin, program->pixel_x,
		program->pixel_y);
		program->nb_coin++;
}

static void	fill_map_short(t_program *program, int i, int j)
{
	if (program->map[i][j] == '1')
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.wall, program->pixel_x, program->pixel_y);
	else if (program->map[i][j] == 'E')
	{
		program->count_e++;
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.door, program->pixel_x, program->pixel_y);
	}
	else if (program->map[i][j] == 'P')
	{
		program->count_p++;
		position_player(program, program->pixel_x, program->pixel_y);
		program->x = j;
		program->y = i;
	}
	else if (program->map[i][j] == 'C')
		position_c(program);
	else if (program->map[i][j] != '0' && program->map[i][j] != 'C' &&
		program->map[i][j] != 'P' && program->map[i][j] != 'E' &&
		program->map[i][j] != '1')
		return_error_map(program);
	check_wall(program);
}

static void	fill_map(t_program *program, char **dest)
{
	int		i;
	int		j;

	i = -1;
	program->count_e = 0;
	program->pixel_y = 0;
	while (dest[++i] != 0)
	{
		j = -1;
		program->pixel_x = 0;
		while (dest[i][++j])
		{
			fill_map_short(program, i, j);
			program->pixel_x += 32;
		}
		program->pixel_y += 32;
	}
	if (!(program->count_p == 1 && program->count_e >= 1))
		return_error_position(program);
}

void	init_map(t_program *program, char **dest)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	y = 0;
	program->count_p = 0;
	take_window_size(program, program->map);
	init_mlx(program);
	init_sprites(program);
	while (dest[++i])
	{
		j = -1;
		x = 0;
		while (dest[i][++j])
		{
			if (dest[i][j])
				mlx_put_image_to_window(program->mlx_pointer,
					program->window, program->image.floor, x, y);
			x += 32;
		}
		y += 32;
	}
	fill_map(program, dest);
}
