/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:04:51 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/04 17:05:04 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	op_rotate(t_stack **stack, int mov)
{
	t_stack	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return (-1);
	*stack = first_node(*stack);
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last_node(*stack);
	last_node(*stack)->next = first;
	if (mov == RA)
		write(1, "ra\n", 3);
	else if (mov == RB)
		write(1, "rb\n", 3);
	return (0);
}

int	op_reverse_rotate(t_stack **stack, int mov)
{
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (-1);
	*stack = last_node(*stack);
	last = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	last->prev = NULL;
	last->next = first_node(*stack);
	first_node(*stack)->prev = last;
	if (mov == RRA)
		write(1, "rra\n", 4);
	else if (mov == RRB)
		write(1, "rrb\n", 4);
	return (0);
}

int	op_r_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return (-1);
	if (op_rotate(stack_a, 0) == -1)
		return (-1);
	if (op_rotate(stack_b, 0) == -1)
		return (-1);
	write(1, "rr\n", 3);
	return (0);
}

int	op_rev_r_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return (-1);
	if (op_reverse_rotate(stack_a, 0) == -1)
		return (-1);
	if (op_reverse_rotate(stack_b, 0) == -1)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}
