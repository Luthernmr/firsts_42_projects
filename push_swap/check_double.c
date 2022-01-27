/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:59:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/10 18:15:59 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_exist(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= stack->top_a)
	{
		i = j + 1;
		while (i <= stack->top_a)
		{
			if (stack->a[j] == stack->a[i])
			{
				free(stack->a);
				free(stack->b);
				free(stack);
				return_error();
			}
			i++;
		}
		j++;
	}
	return (0);
}
