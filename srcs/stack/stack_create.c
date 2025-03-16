/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:59:19 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/02 23:27:28 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack	*create_node(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
    new_node->info = (t_cost_index *)malloc(sizeof(t_cost_index));
	if (!new_node->info)
        return (free(new_node), NULL);
	new_node->nbr = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->info->cheapest = 0;
	new_node->target_node = NULL;
	return (new_node);
}

t_stack	*add_node_front(t_stack *stack, int content)
{
	t_stack	*new_node;

	new_node = create_node(content);
	if (!new_node)
		return (NULL);
	if (!stack)
		return (new_node);
	stack->next = new_node;
	new_node->prev = stack;
	return (new_node);
}
