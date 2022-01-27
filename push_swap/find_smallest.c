/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:05:15 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/06 11:55:43 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stacks *stack)
{
	int	smallest;
	int	count;
	int	i;

	i = 0;
	smallest = stack->a[0];
	while (i <= stack->top_a)
	{
		if (stack->a[i] < smallest)
		{
				smallest = stack->a[i];
				count = i;
		}
		i++;
	}
	return (smallest);
}

int	find_smallest_count(t_stacks *stack)
{
	int	smallest;
	int	count;
	int	i;

	i = 0;
	smallest = stack->a[0];
	while (i <= stack->top_a)
	{
		if (stack->a[i] < smallest)
		{
				smallest = stack->a[i];
				count = i;
		}
		i++;
	}
	return (count);
}
