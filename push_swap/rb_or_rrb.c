/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_or_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor.student@42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:37:02 by lnemor            #+#    #+#             */
/*   Updated: 2021/12/23 00:37:02 by lnemor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_or_rrb(t_stacks *stack, int j)
{
	if (j >= (stack->top_b / 2))
	{
		while (j < stack->top_b)
		{
			do_rb(stack);
			j++;
		}
	}
	else if (j < (stack->top_b / 2))
	{
		while (j > -1)
		{
			do_rrb(stack);
			j--;
		}
	}
	do_pa(stack);
}
