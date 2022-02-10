/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:52:54 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/10 13:36:39 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_program *program)
{
	int	i;

	i = -1;
	if (program->mlx_pointer)
	{
		mlx_destroy_window(program->mlx_pointer, program->window);
		mlx_destroy_image(program->mlx_pointer, program->image.avatar_forward);
		mlx_destroy_image(program->mlx_pointer, program->image.avatar_back);
		mlx_destroy_image(program->mlx_pointer, program->image.avatar_left);
		mlx_destroy_image(program->mlx_pointer, program->image.avatar_right);
		mlx_destroy_image(program->mlx_pointer, program->image.door);
		mlx_destroy_image(program->mlx_pointer, program->image.coin);
		mlx_destroy_image(program->mlx_pointer, program->image.floor);
		mlx_destroy_image(program->mlx_pointer, program->image.wall);
		while (program->map[++i])
			free(program->map[i]);
		free(program->map);
	}
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_program	program;

	if (argc == 2)
	{
		check_error(&program, argv);
		fd = open(argv[1], O_RDONLY);
		parse_map(&program, fd, argv);
		mlx_hook(program.window, 17, 1L << 17, close_window, &program);
		mlx_key_hook(program.window, key_hooked_function, &program);
		mlx_loop(program.mlx_pointer);
	}
	return (0);
}
