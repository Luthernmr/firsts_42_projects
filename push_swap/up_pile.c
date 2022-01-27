/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:38:42 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 16:28:03 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_pile(t_stacks *stack)
{
	int	i;
	int	smallest;
	int	count;

	count = find_smallest_count(stack);
	smallest = find_smallest(stack);
	i = 0;
	if (count <= stack->top_a / 2)
	{
		while (stack->a[stack->top_a] != smallest)
			do_rra(stack);
	}
	else if (count > stack->top_a / 2)
	{
		while (stack->a[stack->top_a] != smallest)
			do_ra(stack);
	}
}
