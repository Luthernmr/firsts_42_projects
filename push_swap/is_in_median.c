/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_median.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:45:59 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 15:37:40 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_median(t_stacks *stack, int median)
{
	int	i;

	i = stack->top_a;
	while (i > -1)
	{
		if (stack->a[i] < median)
			return (1);
		i--;
	}
	return (0);
}

int	is_in_median2(t_stacks *stack, int median)
{
	int	i;

	i = stack->top_a;
	while (i > -1)
	{
		if (stack->a[i] >= median)
			return (1);
		i--;
	}
	return (0);
}

int	is_in_median_five(t_stacks *stack, int mediane, int last_mediane)
{
	int	i;

	i = stack->top_a;
	while (i > -1)
	{
		if (stack->a[i] <= mediane && stack->a[i] > last_mediane)
			return (1);
		i--;
	}
	return (0);
}

int	is_in_median_five_special(t_stacks *stack, int mediane, int last_mediane)
{
	int	i;

	i = stack->top_a;
	while (i > -1)
	{
		if (stack->a[i] <= mediane && stack->a[i] >= last_mediane)
			return (1);
		i--;
	}
	return (0);
}
