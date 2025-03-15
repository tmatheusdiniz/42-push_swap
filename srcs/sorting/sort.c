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

void	sort_all(t_stack **stack, t_cost_index **info)
{
	(void)stack;
	(void)info;
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
