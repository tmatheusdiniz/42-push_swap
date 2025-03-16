/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:48:53 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/08 21:56:55 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <limits.h>

static void	set_target_a(t_stack *stack_a, t_stack *stack_b);
static void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b);
static void	set_cheapest(t_stack *stack);

void	init_node_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->info->index = i;
		if (i <= median)
			stack->info->above_median = 1;
		else
			stack->info->above_median = 0;
		++ i;
		stack = stack->next;
	}
}

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	t_stack	*current_b;
	t_stack	*target;
	long	best_number;

	while (stack_a)
	{
		best_number = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->nbr < stack_a->nbr && current_b->nbr > best_number)
			{
				best_number = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_number == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

static void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int	length_a;
	int	length_b;

	length_a = stack_len(stack_a);
	length_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->info->cost = stack_a->info->index;
		if (!(stack_a->info->above_median))
			stack_a->info->cost = length_a - stack_a->info->index;
		if (stack_a->target_node->info->above_median)
			stack_a->info->cost += stack_a->target_node->info->index;
		else
			stack_a->info->cost += length_b - stack_a->target_node->info->index;
		stack_a = stack_a->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	long	cheapest_v;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_v = LONG_MAX;
	while (stack)
	{
		if (stack->info->cost < cheapest_v)
		{
			cheapest_v = stack->info->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->info->cheapest = 1;
}
