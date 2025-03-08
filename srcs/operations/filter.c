/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:43:32 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/04 22:21:27 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	filter_op(t_stack **stack_a, t_stack **stack_b, int mov)
{
	if (mov == SA)
		op_swap(stack_a, 1);
	else if (mov == SB)
		op_swap(stack_b, 2);
	else if (mov == SS)
		op_s_s(stack_a, stack_b);
	else if (mov == PA)
		op_pa(stack_a, stack_b);
	else if (mov == PB)
		op_pb(stack_a, stack_b);
	else if (mov == RA)
		op_rotate(stack_a, 6);
	else if (mov == RB)
		op_rotate(stack_b, 7);
	else if (mov == RR)
		op_r_rotate(stack_a, stack_b);
	else if (mov == RRA)
		op_reverse_rotate(stack_a, 9);
	else if (mov == RRB)
		op_reverse_rotate(stack_b, 10);
	else if (mov == RRR)
		op_rev_r_rotate(stack_a, stack_b);
	return (0);
}
