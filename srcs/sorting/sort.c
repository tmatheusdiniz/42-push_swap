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

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || (*stack_a)->next || !stack_b || !(*stack_b)->next)
		return ;
	if ((*stack_a)->next->next->next && !stack_sorted(*stack_a))
		op_pb(stack_a, stack_b);
	if ((*stack_a)->next->next->next && !stack_sorted(*stack_a))
		op_pb(stack_a, stack_b);
	while ((*stack_a)->next->next->next)
	{
		init_node_a(*stack_a, *stack_b);
		
	}
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
