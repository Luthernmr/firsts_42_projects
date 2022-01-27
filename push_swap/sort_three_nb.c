/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:43:07 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 15:32:09 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nb(t_stacks *stack)
{
	if (stack->a[2] < stack->a[0] && stack->a[2] > stack->a[1])
		do_sa(stack);
	else if (stack->a[2] > stack->a[1] && stack->a[1] > stack->a[0])
	{
		do_sa(stack);
		do_rra(stack);
	}
	else if (stack->a[2] > stack->a[1] && stack->a[1] < stack->a[0])
		do_ra(stack);
	else if (stack->a[2] < stack->a[0] && stack->a[1] > stack->a[0])
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if (stack->a[2] > stack->a[0] && stack->a[1] > stack->a[0])
		do_rra(stack);
}
