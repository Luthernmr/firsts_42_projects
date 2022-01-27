/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:03:51 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 14:45:15 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrb(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	if (stack->top_b == -1)
		return ;
	ft_putendl_fd("rrb", 1);
	temp = stack->b[0];
	while (i < stack->top_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->top_b] = temp;
}
