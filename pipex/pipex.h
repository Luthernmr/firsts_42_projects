/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:25:21 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 12:43:45 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdio.h>
# include "limits.h"
# include "stdlib.h"
# include "fcntl.h"

typedef struct t_pipex
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		file_in;
	int		file_out;
	int		pipe_fd[2];
	char	**path;
	char	*path_temp;
	char	**argv_cmd;
	char	*path_1;
	char	*path_2;
}				t_pipex;

char	*find_path(t_pipex *pipex, char **env, char *cmd);
void	do_cmd1(t_pipex *pipex, char **argv, char **env);
void	do_cmd2(t_pipex *pipex, char **argv, char **env);
void	free_all(t_pipex *pipex);
void	exit_error(t_pipex *pipex, char *str, int i);

#endif
