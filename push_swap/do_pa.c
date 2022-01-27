/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:30:15 by lnemor            #+#    #+#             */
/*   Updated: 2021/12/14 18:30:13 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stacks *stack)
{
	stack->a[stack->top_a + 1] = stack->b[stack->top_b];
	stack->top_b = stack->top_b - 1;
	stack->top_a = stack->top_a + 1;
	ft_putendl_fd("pa", 1);
}
