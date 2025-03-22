/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:07:19 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/08 21:56:41 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->info->above_median
		&& cheapest_node->target_node->info->above_median)
	{
		while (*stack_a != cheapest_node
			&& *stack_b != cheapest_node->target_node)
		{
			op_r_rotate(stack_a, stack_b);
			*stack_a = first_node(*stack_a);
			*stack_b = first_node(*stack_b);
		}
		current_index(*stack_a);
		current_index(*stack_b);
	}
	else if (!(cheapest_node->info->above_median)
		&& !(cheapest_node->target_node->info->above_median))
	{
		while (*stack_a != cheapest_node
			&& *stack_b != cheapest_node->target_node)
		{
			op_rev_r_rotate(stack_a, stack_b);
			*stack_a = first_node(*stack_a);
			*stack_b = first_node(*stack_b);
		}
		current_index(*stack_a);
		current_index(*stack_b);
	}
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	op_pb(stack_a, stack_b);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->next->next->next && !stack_sorted(*stack_a))
		op_pb(stack_a, stack_b);
	if ((*stack_a)->next->next->next && !stack_sorted(*stack_a))
		op_pb(stack_a, stack_b);
	while ((*stack_a)->next->next->next && !stack_sorted(*stack_a))
	{
		init_node_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_node_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}

void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*stack);
	if (biggest_node == *stack)
		op_rotate(stack, RA);
	if (biggest_node == (*stack)->next)
	{
		op_reverse_rotate(stack, RRA);
		*stack = first_node(*stack);
	}
	if ((*stack)->nbr > (*stack)->next->nbr)
		op_swap(stack, SA);
}
