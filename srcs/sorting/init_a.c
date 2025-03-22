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
	t_stack	*current_b;
	t_stack	*target;
	long	best_number;

	if (!stack_a || !stack_b)
		return ;
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

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	length_a;
	int	length_b;

	length_a = stack_len(a);
	length_b = stack_len(b);
	while (a)
	{
		if (a->info->above_median)
			a->info->cost = a->info->index;
		else
			a->info->cost = length_a - a->info->index;
		if (a->target_node->info->above_median)
			b->info->cost = a->target_node->info->index;
		else
			b->info->cost = length_b - a->target_node->info->index;
		if ((a->info->above_median && a->target_node->info->above_median)
			|| (!a->info->above_median && !a->target_node->info->above_median))
		{
			if (a->info->cost < b->info->cost)
				a->info->cost = b->info->cost;
		}
		else
			a->info->cost += b->info->cost;
		a = a->next;
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
