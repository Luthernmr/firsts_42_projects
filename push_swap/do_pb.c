/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:33:55 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/06 16:54:36 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_stacks *stack)
{
	stack->b[stack->top_b + 1] = stack->a[stack->top_a];
	stack->top_b = stack->top_b + 1;
	stack->top_a = stack->top_a - 1;
	ft_putendl_fd("pb", 1);
}
