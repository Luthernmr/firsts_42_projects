/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:40:40 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 15:57:12 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stack, int *tab)
{	
	int	i;

	i = 0;
	while (i < stack->top_a)
	{
		if (tab[i] < tab[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int	*sort_for_mediane(int *a_bis, t_stacks *stack)
{
	int	i;
	int	temp;
	int	desordre;

	desordre = 1;
	i = stack->top_a;
	while (desordre == 1)
	{
		desordre = 0;
		i = stack->top_a;
		while (i > 0)
		{
			if (a_bis[i] > a_bis[i - 1])
			{
				temp = a_bis[i - 1];
				a_bis[i - 1] = a_bis[i];
				a_bis[i] = temp;
				desordre = 1;
			}
			i--;
		}
	}
	return (a_bis);
}
