/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:57:50 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/17 18:01:07 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// W = 13
// A = 0
// S = 1
// D = 2

void	forward(t_program *program)
{
	if (program->map[program->y - 1][program->x] != '1' &&
		!(program->map[program->y - 1][program->x] == 'E' &&
		program->nb_coin != 0))
	{
		program->moove++;
		printf("number of movement : %d\n", program->moove);
		program->y--;
		program->position_y -= 32;
		if (program->map[program->y][program->x] == 'C')
		{
			program->nb_coin--;
			program->map[program->y][program->x] = '0';
		}
		if (program->map[program->y][program->x] == 'E'
			&& program->nb_coin <= 0)
			close_window(program);
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.floor, program->position_x,
			program->position_y + 32);
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.avatar_forward, program->position_x,
			program->position_y);
	}
}

void	left(t_program *program)
{
	if (program->map[program->y][program->x - 1] != '1' &&
		!(program->map[program->y][program->x - 1] == 'E' &&
		program->nb_coin != 0))
	{
		program->moove++;
		printf("number of movement : %d\n", program->moove);
		program->x--;
		program->position_x -= 32;
		if (program->map[program->y][program->x] == 'C')
		{
			program->nb_coin--;
			program->map[program->y][program->x] = '0';
		}
		if (program->map[program->y][program->x] == 'E'
			&& program->nb_coin <= 0)
			close_window(program);
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.floor, program->position_x + 32,
			program->position_y);
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.avatar_left, program->position_x,
			program->position_y);
	}
}

void	right(t_program *program)
{
	if (program->map[program->y][program->x + 1] != '1' &&
		!(program->map[program->y][program->x + 1] == 'E' &&
		program->nb_coin != 0))
	{
		program->moove++;
		printf("number of movement : %d\n", program->moove);
		program->x++;
		program->position_x += 32;
		if (program->map[program->y][program->x] == 'C')
		{
			program->nb_coin--;
			program->map[program->y][program->x] = '0';
		}
		if (program->map[program->y][program->x] == 'E'
			&& program->nb_coin <= 0)
			close_window(program);
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.floor, program->position_x - 32,
			program->position_y);
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.avatar_right, program->position_x,
			program->position_y);
	}
}

void	back(t_program *program)
{
	if (program->map[program->y + 1][program->x] != '1' &&
		!(program->map[program->y + 1][program->x] == 'E' &&
		program->nb_coin != 0))
	{
		program->moove++;
		printf("number of movement : %d\n", program->moove);
		program->y++;
		program->position_y += 32;
		if (program->map[program->y][program->x] == 'C')
		{
			program->nb_coin--;
			program->map[program->y][program->x] = '0';
		}
		if (program->map[program->y][program->x] == 'E'
			&& program->nb_coin <= 0)
			close_window(program);
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.floor, program->position_x,
			program->position_y - 32);
		mlx_put_image_to_window(program->mlx_pointer, program->window,
			program->image.avatar_back, program->position_x,
			program->position_y);
	}
}

int	key_hooked_function(int keycode, t_program *program)
{	
	if (keycode == 53)
		close_window(program);
	if (keycode == 13 || keycode == 126)
		forward(program);
	if (keycode == 0 || keycode == 123)
		left(program);
	if (keycode == 2 || keycode == 124)
		right(program);
	if (keycode == 1 || keycode == 125)
		back(program);
	return (0);
}
