/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_op_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:16:59 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/15 23:21:18 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	min_on_top(t_stack **stack)
{
	while ((*stack)->nbr != find_min(*stack)->nbr)
	{
		if (find_min(*stack)->info->above_median)
		{
			op_rotate(stack, RA);
			*stack = first_node(*stack);
		}
		else
		{
			op_reverse_rotate(stack, RRA);
			*stack = first_node(*stack);
		}
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->info->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top, char wt_stack)
{
	while (*stack != top)
	{
		if (wt_stack == 'a')
		{
			if (top->info->above_median)
				op_rotate(stack, RA);
			else
				op_reverse_rotate(stack, RRA);
			*stack = first_node(*stack);
		}
		if (wt_stack == 'b')
		{
			if (top->info->above_median)
				op_rotate(stack, RB);
			else
				op_reverse_rotate(stack, RRB);
			*stack = first_node(*stack);
		}
	}
}
