/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:43:29 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/17 16:24:41 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_for_malloc(t_program *program, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (line == '\0')
		return_error_empty_file(program);
	i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	parse_map(t_program *program, int fd, char **argv)
{
	int		i;
	int		j;
	int		k;

	k = size_for_malloc(program, fd);
	fd = open(argv[1], O_RDONLY);
	program->map = (char **)malloc(sizeof(char *) * k);
	program->map[k - 1] = NULL;
	i = 0;
	program->map[i] = get_next_line(fd);
	j = ft_strlen(program->map[i]);
	program->map[i++][j - 1] = '\0';
	while (k-- > 2)
	{
		program->map[i] = get_next_line(fd);
		j = ft_strlen(program->map[i]);
		if (program->map[i][j - 1] == '\n')
			program->map[i][j - 1] = '\0';
		if (program->map[i][0] == '\n' || !program->map[i][0])
			return_error_parsing(program);
		i++;
	}
	close(fd);
	check_len_lines(program);
	init_map(program, program->map);
}
