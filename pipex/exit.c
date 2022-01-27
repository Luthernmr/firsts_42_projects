/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:42:09 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 13:10:27 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(t_pipex *pipex, char *str, int i)
{
	close(pipex->file_in);
	close(pipex->file_out);
	ft_putstr_fd(str, 2);
	exit(i);
}
