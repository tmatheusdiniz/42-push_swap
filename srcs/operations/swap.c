/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:04:14 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/04 17:04:29 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	op_swap(t_stack **stack, int mov)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return (-1);
	(*stack)->nbr = (*stack)->nbr ^ (*stack)->next->nbr;
	(*stack)->next->nbr = (*stack)->nbr ^ (*stack)->next->nbr;
	(*stack)->nbr = (*stack)->nbr ^ (*stack)->next->nbr;
	if (mov == SA)
		write(1, "sa\n", 3);
	else if (mov == SB)
		write(1, "sb\n", 3);
	return (0);
}

int	op_s_s(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return (-1);
	if (op_swap(stack_a, 0) == -1)
		return (-1);
	if (op_swap(stack_b, 0) == -1)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}
