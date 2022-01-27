/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:49:33 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 13:48:35 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra_or_not(t_stacks *stack, int count1, int smallest, int biggest)
{
	int	i;
	int	count2;

	i = stack->top_b;
	count2 = 0;
	while (i > -1)
	{
		if (stack->b[i] < stack->b[smallest])
			smallest = i;
		i--;
		count2++;
	}
	count2 -= smallest;
	count1 -= biggest;
	if (count1 > count2)
	{
		rb_or_rrb(stack, smallest);
		do_ra(stack);
	}
	else if (count1 <= count2)
		rb_or_rrb(stack, biggest);
}

void	check_num_b(t_stacks *stack)
{
	int	i;
	int	biggest;
	int	smallest;
	int	count1;

	i = stack->top_b - 1;
	biggest = stack->top_b;
	smallest = stack->top_b;
	count1 = 0;
	while (i > -1)
	{
		if (stack->b[i] > stack->b[biggest])
			biggest = i;
		i--;
		count1++;
	}
	ra_or_not(stack, count1, smallest, biggest);
}
