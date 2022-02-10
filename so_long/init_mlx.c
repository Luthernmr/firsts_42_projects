/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:03:01 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/10 16:24:03 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_program *program)
{
	program->mlx_pointer = mlx_init();
	program->window = mlx_new_window(program->mlx_pointer,
			program->width, program->hight, "so_long");
}

void	init_sprites(t_program *program)
{
	program->image.wall = mlx_xpm_file_to_image(program->mlx_pointer,
			"./textures/wall.xpm", program->image.size_x,
			program->image.size_y);
	program->image.floor = mlx_xpm_file_to_image(program->mlx_pointer,
			"./textures/floor.xpm", &(program->image.size_x),
			&(program->image.size_y));
	program->image.avatar_back = mlx_xpm_file_to_image(program->mlx_pointer,
			"./textures/avatar_back.xpm", &(program->image.size_x),
			&(program->image.size_y));
	program->image.avatar_forward = mlx_xpm_file_to_image(program->mlx_pointer,
			"./textures/avatar_forward.xpm", &(program->image.size_x),
			&(program->image.size_y));
	program->image.avatar_left = mlx_xpm_file_to_image(program->mlx_pointer,
			"./textures/avatar_left.xpm", &(program->image.size_x),
			&(program->image.size_y));
	program->image.avatar_right = mlx_xpm_file_to_image(program->mlx_pointer,
			"./textures/avatar_right.xpm", &(program->image.size_x),
			&(program->image.size_y));
	program->image.door = mlx_xpm_file_to_image(program->mlx_pointer,
			"./textures/door.xpm", &(program->image.size_x),
			&(program->image.size_y));
	program->image.coin = mlx_xpm_file_to_image(program->mlx_pointer,
			"./textures/coin.xpm", &(program->image.size_x),
			&(program->image.size_y));
}
