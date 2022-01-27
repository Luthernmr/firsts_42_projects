/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:25:21 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/17 17:28:45 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include "limits.h"
# include "stdlib.h"
# include "mlx/mlx.h"
# include "fcntl.h"
# define BUFFER_SIZE 1

typedef struct s_image
{
	void	*pointer;
	char	*pixels;
	int		size_x;
	int		size_y;
	int		bits_per_pixel;
	char	path;
	int		line_size;
	void	*wall;
	void	*floor;
	void	*avatar_back;
	void	*avatar_forward;
	void	*avatar_left;
	void	*avatar_right;
	void	*door;
	void	*coin;
	int		endian;
}					t_image;

typedef struct s_program
{
	int		count_p;
	int		count_e;
	int		moove;
	int		x;
	int		y;
	int		pixel_x;
	int		pixel_y;
	void	*mlx_pointer;
	void	*window;
	int		position_x;
	int		position_y;
	int		nb_coin;
	int		width;
	int		hight;
	char	**map;
	t_image	image;
}				t_program;

/**************************INIT****************************/
void	init_mlx(t_program *program);
void	init_asset(t_program *program, char *path);
void	init_sprites(t_program *program);
void	init_map(t_program *program, char **dest);
void	take_window_size(t_program *program, char **dest);
int		key_hooked_function(int keycode, t_program *program);

/*************************PARSING**************************/

void	parse_map(t_program *program, int fd, char **argv);
char	*get_next_line(int fd);

/*************************RETURN**************************/

void	return_error(t_program *program);
void	return_error_empty_file(t_program *program);
void	return_error_map(t_program *program);
void	return_error_wall(t_program *program);
void	return_error_parsing(t_program *program);
void	return_error_position(t_program *program);
void	return_error_size(t_program *program);
int		close_window(t_program *program);

/*************************CHECKERS**************************/

void	check_error(t_program *program, char **argv);
void	check_wall(t_program *program);
void	check_len_lines(t_program *program);

#endif
