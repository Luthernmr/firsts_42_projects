/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:48:40 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/17 18:08:15 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_len_lines(t_program *program)
{
	int	i;

	i = 0;
	while (program->map[i] && program->map[i + 1])
	{
		if (ft_strlen(program->map[i]) != ft_strlen(program->map[i + 1]))
			return_error_size(program);
		i++;
	}
}

void	check_wall(t_program *program)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (program->map[0][++x])
		if (program->map[0][x] != '1')
			return_error_wall(program);
	while (program->map[++y])
		if (program->map[y][0] != '1')
			return_error_wall(program);
	y = -1;
	x--;
	while (program->map[++y])
		if (program->map[y][x] != '1')
			return_error_wall(program);
	x = -1;
	y--;
	while (program->map[y][++x])
		if (program->map[y][x] != '1')
			return_error_wall(program);
}

void	return_error_empty_file(t_program *program)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Empty_file\n", 1);
	close_window(program);
}

void	return_error_size(t_program *program)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("map is not rectangle\n", 1);
	close_window(program);
}

void	check_error(t_program *program, char **argv)
{
	int		k;

	k = ft_strlen(argv[1]);
	if (k > 4)
	{
		if (!(argv[1][k - 1] == 'r' && argv[1][k - 2] == 'e' &&
			argv[1][k - 3] == 'b'
			&& argv[1][k - 4] == '.'))
			return_error(program);
	}
	else
		return_error(program);
}
