/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:51:50 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/04 17:09:26 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stacks *stack)
{
	int	i;
	int	temp;

	ft_putendl_fd("ra", 1);
	i = stack->top_a;
	if (stack->top_a == -1)
		return ;
	temp = stack->a[stack->top_a];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = temp;
}
