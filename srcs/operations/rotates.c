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
		ft_printf("ra\n");
	else if (mov == RB)
		ft_printf("rb\n");
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
		ft_printf("rra\n");
	else if (mov == RRB)
		ft_printf("rrb\n");
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
	ft_printf("rr\n");
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
	ft_printf("rrr\n");
	return (0);
}
