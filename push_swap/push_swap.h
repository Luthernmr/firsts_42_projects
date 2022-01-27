/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:40:45 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/06 17:03:53 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include "limits.h"
# include "stdlib.h"

typedef struct t_stacks
{
	int		*a;
	int		*b;
	int		*median;
	int		top_a;
	int		top_b;
}					t_stacks;

/************************* FONCTION DE MOUVEMENT ***********************/
void	do_sa(t_stacks *stack);
void	do_sb(t_stacks *stack);
void	do_pa(t_stacks *stack);
void	do_pb(t_stacks *stack);
void	do_ra(t_stacks *stack);
void	do_rb(t_stacks *stack);
void	do_rra(t_stacks *stack);
void	do_rrb(t_stacks *stack);
void	do_rrr(t_stacks *stack);
/************************* TRI MEDIANE ***********************/
void	rb_or_rrb(t_stacks *stack, int j);
void	ra_or_rra(t_stacks *stack, int j);
int		is_sorted(t_stacks *stack, int *tab);
int		is_in_median(t_stacks *stack, int median);
int		is_in_median2(t_stacks *stack, int median);
void	check_num_b(t_stacks *stack);
void	sort_three_nb(t_stacks *stack);
void	sort_five_hundred_nb(t_stacks *stack);
void	sort_five_nb(t_stacks *stack);
void	sort_hundred_nb(t_stacks *stack);
void	parse_argument(t_stacks *stack, char *str);
void	parse_argument_multi(t_stacks *stack, char **argv, int argc);
int		find_smallest_count(t_stacks *stack);
int		find_smallest(t_stacks *stack);
int		is_in_median_five(t_stacks *stack, int mediane, int last_mediane);
int		is_in_median_five_special(t_stacks *stack,
			int mediane, int last_mediane);
void	up_pile(t_stacks *stack);
int		*sort_for_mediane(int *a_bis, t_stacks *stack);
int		ft_check_exist(t_stacks *stack);
void	return_error(void);

#endif
