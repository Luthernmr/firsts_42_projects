/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:43:08 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/07 14:25:27 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	take_mediane(t_stacks *stack)
{
	int	*a_bis;
	int	i;
	int	j;
	int	k;

	a_bis = malloc((sizeof(int) * stack->top_a) + sizeof(int));
	stack->median = malloc(sizeof(int) * 4);
	if (!a_bis || !stack->median)
		return ;
	i = 0;
	while (i <= stack->top_a)
	{
		a_bis[i] = stack->a[i];
		i++;
	}
	a_bis = sort_for_mediane(a_bis, stack);
	k = (stack->top_a / 4) * 3;
	j = 0;
	while (j < 4)
	{
		stack->median[j] = a_bis[k];
		j++;
		k -= stack->top_a / 4;
	}
	free(a_bis);
}

static void	check_num_a(t_stacks *stack, int median, int last_mediane)
{
	int	i;

	i = stack->top_a;
	while (i > -1)
	{
		if (stack->a[i] <= median && stack->a[i] > last_mediane)
		{
			while (i < stack->top_a)
			{
				do_ra(stack);
				i++;
			}
			do_pb(stack);
			break ;
		}
		i--;
	}
}

static void	check_num_a1(t_stacks *stack, int median, int last_mediane)
{
	int	i;

	i = stack->top_a;
	while (i > -1)
	{
		if (stack->a[i] <= median && stack->a[i] >= last_mediane)
		{
			while (i < stack->top_a)
			{
				do_ra(stack);
				i++;
			}
			do_pb(stack);
			break ;
		}
		i--;
	}
}

void	sort_hundred_nb(t_stacks *stack)
{
	int	i;
	int	last_mediane;

	take_mediane(stack);
	last_mediane = find_smallest(stack);
	i = -1;
	while (++i < 4)
	{
		if (i < 1)
		{
			while (is_in_median_five_special(stack, stack->median[i],
					last_mediane) == 1)
				check_num_a1(stack, stack->median[i], last_mediane);
		}
		while (is_in_median_five(stack, stack->median[i], last_mediane) == 1)
			check_num_a(stack, stack->median[i], last_mediane);
		if (i > 0)
			up_pile(stack);
		last_mediane = stack->median[i];
		while (stack->top_b > -1)
			check_num_b(stack);
	}
	up_pile(stack);
	free(stack->median);
	return ;
}
