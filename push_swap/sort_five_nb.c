/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:46:22 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/07 12:23:41 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nb(t_stacks *stack)
{
	int	i;

	i = 0;
	if (stack->top_a == 4)
		i = 1;
	while (i >= 0)
	{
		up_pile(stack);
		do_pb(stack);
		i--;
	}
	if (stack->b[1] < stack->b[0] && stack->top_b > 1)
		do_sb(stack);
	sort_three_nb(stack);
	if (stack->top_b == 1)
		do_pa(stack);
	do_pa(stack);
}
