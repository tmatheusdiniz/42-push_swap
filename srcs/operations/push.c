/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:16:07 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/04 17:05:19 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	op_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !(*stack_b))
		return (-1);
	*stack_b = first_node(*stack_b);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (*stack_a)
		*stack_a = first_node(*stack_a);
	if (*stack_a)
	{
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
	}
	temp->prev = NULL;
	*stack_a = temp;
	ft_printf("pa\n");
	return (0);
}

int	op_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_a || !(*stack_a))
		return (-1);
	*stack_a = first_node(*stack_a);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (*stack_b)
		*stack_b = first_node(*stack_b);
	if (*stack_b)
	{
		temp->next = *stack_b;
		(*stack_b)->prev = temp;
	}
	else
		temp->next = NULL;
	temp->prev = NULL;
	*stack_b = temp;
	ft_printf("pb\n");
	return (0);
}
