/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:40:12 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/22 17:33:23 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

static int	aux_filter(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!(ft_strncmp(line, "sa\n", 3)))
		op_swap(stack_a);
	else if (!(ft_strncmp(line, "sb\n", 3)))
		op_swap(stack_b);
	else if (!(ft_strncmp(line, "ss\n", 3)))
		op_s_s(stack_a, stack_b);
	else if (!(ft_strncmp(line, "pa\n", 3)))
		op_pa(stack_a, stack_b);
	else if (!(ft_strncmp(line, "pb\n", 3)))
		op_pb(stack_a, stack_b);
	else if (!(ft_strncmp(line, "ra\n", 3)))
		op_rotate(stack_a);
	else if (!(ft_strncmp(line, "rb\n", 3)))
		op_rotate(stack_b);
	else if (!(ft_strncmp(line, "rr\n", 3)))
		op_r_rotate(stack_a, stack_b);
	else if (!(ft_strncmp(line, "rra\n", 3)))
		op_reverse_rotate(stack_a);
	else if (!(ft_strncmp(line, "rrb\n", 3)))
		op_reverse_rotate(stack_b);
	else if (!(ft_strncmp(line, "rrr\n", 3)))
		op_rev_r_rotate(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	filter_op(t_stack **stack_a, t_stack **stack_b, char *line)
{
	*stack_a = first_node(*stack_a);
	*stack_b = first_node(*stack_b);
	if (aux_filter(stack_a, stack_b, line))
		return (1);
	else
		return (0);
}
