/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:14:09 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/08 16:18:11 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	t_stack	*save;

	if (!stack || !stack->next)
		return (NULL);
	stack = first_node(stack);
	save = stack;
	while (stack->next)
	{
		if (stack->next->nbr > stack->nbr)
			save = stack->next;
		stack = stack->next;
	}
	return (save);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*save;

	if (!stack || !stack->next)
		return (NULL);
	stack = first_node(stack);
	save = stack;
	while (stack->next)
	{
		if (stack->next->nbr < stack->nbr)
			save = stack->next;
		stack = stack->next;
	}
	return (save);
}
