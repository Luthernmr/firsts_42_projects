/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:13:21 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/17 16:58:32 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error(t_program *program)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Bad arguments\n", 1);
	close_window(program);
}

void	return_error_parsing(t_program *program)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Failed parsing\n", 1);
	close_window(program);
}

void	return_error_wall(t_program *program)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Wall are not closed\n", 1);
	close_window(program);
}

void	return_error_map(t_program *program)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Wrong map, bad character found\n", 1);
	close_window(program);
}

void	return_error_position(t_program *program)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("No issue, Multiple or Any player postion\n", 1);
	close_window(program);
}
