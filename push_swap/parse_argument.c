/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:39:29 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/10 19:13:15 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isspace(str[i]) == 0)
			break ;
		else if (((size_t)i) == ft_strlen(str) - 1)
			return_error();
	}
}

void	parse_argument(t_stacks *stack, char *str)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	dest = ft_split(str, ' ');
	while (dest[i])
		i++;
	i--;
	stack->top_a = i;
	stack->a = malloc(sizeof(int) * (stack->top_a + 1));
	if (!stack->a)
		return ;
	stack->b = malloc(sizeof(int) * (stack->top_a + 1));
	if (!stack->b)
		return ;
	check_space(str);
	j = -1;
	while (dest[++j])
		stack->a[i--] = ft_atoi(dest[j]);
	while (j-- > 0)
		free(dest[j]);
	free(dest);
}

void	parse_argument_multi(t_stacks *stack, char **argv, int argc)
{
	int		i;
	char	*temp;

	i = 1;
	temp = ft_strdup("");
	while (i < argc)
	{
		if (argv[i][0] == 0)
		{
			free(temp);
			return_error();
		}
		temp = ft_strjoin_free_s1(temp, argv[i]);
		temp = ft_strjoin_free_s1(temp, " ");
		i++;
	}
	i = -1;
	parse_argument(stack, temp);
	free(temp);
}
