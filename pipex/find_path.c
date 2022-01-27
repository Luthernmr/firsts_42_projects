/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:28:18 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 13:23:58 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_int_path(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->path[++i])
		free(pipex->path[i]);
	free(pipex->path);
	free(pipex->path_temp);
}

void	free_temp(char **temp)
{
	free(temp[1]);
	free(temp[0]);
	free(temp);
}

char	*find_path(t_pipex *pipex, char **env, char *cmd)
{
	int		i;
	char	**temp;

	i = 0;
	pipex->path_temp = NULL;
	while (ft_strncmp("PATH", env[i], 4) != 0)
		i++;
	temp = ft_split(env[i], '=');
	pipex->path = ft_split(temp[1], ':');
	i = -1;
	while (pipex->path[++i])
	{
		free(pipex->path_temp);
		pipex->path_temp = ft_strjoin(pipex->path[i], "/");
		pipex->path_temp = ft_strjoin_free_s1(pipex->path_temp, cmd);
		if (access(pipex->path_temp, X_OK) == 0)
		{
			free_temp(temp);
			return (pipex->path_temp);
		}
	}
	free_int_path(pipex);
	free_temp(temp);
	return (0);
}
