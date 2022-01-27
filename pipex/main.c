/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:39:32 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 17:09:37 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipe_and_fd(t_pipex *pipex, char **argv)
{
	pipe(pipex->pipe_fd);
	pipex->file_in = open(argv[1], O_RDONLY);
	if (pipex->file_in < 0)
		exit_error(pipex, "Invalid fd\n", 0);
	pipex->file_out = open(argv[4], O_TRUNC | O_RDWR | O_CREAT, 0644);
	if (pipex->file_out < 0)
		exit_error(pipex, "Invalid fd\n", 0);
}

void	close_and_wait(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pipex->pid_1, 0, 0);
	waitpid(pipex->pid_2, 0, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		init_pipe_and_fd(&pipex, argv);
		pipex.pid_1 = fork();
		if (pipex.pid_1 == -1)
			exit_error(&pipex, "Fork1 failed\n", 0);
		else if (pipex.pid_1 == 0)
			do_cmd1(&pipex, argv, env);
		pipex.pid_2 = fork();
		if (pipex.pid_2 == -1)
			exit_error(&pipex, "Fork2 failed\n", 0);
		else if (pipex.pid_2 == 0)
			do_cmd2(&pipex, argv, env);
		close_and_wait(&pipex);
		close(pipex.file_in);
		close(pipex.file_out);
	}
	else
		ft_putstr_fd("Invalid syntax\n", 2);
	return (0);
}
