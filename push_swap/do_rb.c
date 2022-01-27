/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:03:50 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 14:45:45 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rb(t_stacks *stack)
{
	int	i;
	int	temp;

	ft_putendl_fd("rb", 1);
	i = stack->top_b;
	if (stack->top_b == -1)
		return ;
	temp = stack->b[stack->top_b];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = temp;
}
