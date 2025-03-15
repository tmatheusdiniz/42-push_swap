/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:24:28 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/04 17:04:01 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*first_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack || !stack->next)
		return (-1);
	while (stack->next)
	{
		count ++;
		stack = stack->next;
	}
	return (count);
}

int	stack_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (-1);
	stack = first_node(stack);
	while (stack->next)
	{
		if (stack->next->nbr > stack->nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}
