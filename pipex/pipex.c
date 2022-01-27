/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:48:55 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 12:44:48 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_cmd1(t_pipex *pipex, char **argv, char **env)
{
	int	i;

	i = 0;
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	dup2(pipex->file_in, STDIN_FILENO);
	pipex->argv_cmd = ft_split(argv[2], ' ');
	if (find_path(pipex, env, pipex->argv_cmd[0]) == 0)
	{
		ft_putstr_fd("command(1) not found\n", 2);
		i = -1;
		while (pipex->argv_cmd[++i])
			free(pipex->argv_cmd[i]);
		free(pipex->argv_cmd);
		exit(0);
	}
	pipex->path_1 = find_path(pipex, env, pipex->argv_cmd[0]);
	execve(pipex->path_1, pipex->argv_cmd, env);
}

void	do_cmd2(t_pipex *pipex, char **argv, char **env)
{
	int	i;

	i = 0;
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[1]);
	dup2(pipex->file_out, STDOUT_FILENO);
	pipex->argv_cmd = ft_split(argv[3], ' ');
	if (find_path(pipex, env, pipex->argv_cmd[0]) == 0)
	{
		ft_putstr_fd("command(2) not found\n", 2);
		i = -1;
		while (pipex->argv_cmd[++i])
			free(pipex->argv_cmd[i]);
		free(pipex->argv_cmd);
		exit(0);
	}
	pipex->path_2 = find_path(pipex, env, pipex->argv_cmd[0]);
	execve(pipex->path_2, pipex->argv_cmd, env);
}
