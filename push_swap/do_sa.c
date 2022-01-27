/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:16:08 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 15:33:32 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stacks *stack)
{
	int	temp;

	temp = stack->a[stack->top_a];
	stack->a[stack->top_a] = stack->a[stack->top_a - 1];
	stack->a[stack->top_a - 1] = temp;
	ft_putendl_fd("sa", 1);
}
