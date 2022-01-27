/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:13:39 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/04 17:10:28 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	if (stack->top_a == -1)
		return ;
	ft_putendl_fd("rra", 1);
	temp = stack->a[0];
	while (i < stack->top_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->top_a] = temp;
}
