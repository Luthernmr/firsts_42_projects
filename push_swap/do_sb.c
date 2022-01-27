/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:09:59 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 16:30:43 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sb(t_stacks *stack)
{
	int	temp;

	temp = stack->b[stack->top_b];
	stack->b[stack->top_b] = stack->b[stack->top_b - 1];
	stack->b[stack->top_b - 1] = temp;
	ft_putendl_fd("sb", 1);
}
