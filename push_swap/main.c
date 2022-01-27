/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:51:54 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/10 19:07:24 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_push_swap(t_stacks *stack)
{
	if (stack->top_a == 1 && is_sorted(stack, stack->a) == -1)
		do_sa(stack);
	else if (stack->top_a == 2)
		sort_three_nb(stack);
	else if (stack->top_a > 2 && stack->top_a < 5
		&& is_sorted(stack, stack->a) == -1)
		sort_five_nb(stack);
	else if (stack->top_a > 4 && stack->top_a <= 300
		&& is_sorted(stack, stack->a) == -1)
		sort_hundred_nb(stack);
	else if (stack->top_a > 300)
		sort_five_hundred_nb(stack);
}

int	main(int argc, char **argv)
{
	t_stacks	*stack;

	if (argc > 1)
	{
		stack = malloc(sizeof(*stack));
		if (!stack)
			return (0);
		stack->top_b = -1;
		if (argc == 2)
			parse_argument(stack, argv[1]);
		else if (argc > 2)
			parse_argument_multi(stack, argv, argc);
		ft_check_exist(stack);
		ft_push_swap(stack);
		free(stack->a);
		free(stack->b);
		free(stack);
	}
	return (0);
}
