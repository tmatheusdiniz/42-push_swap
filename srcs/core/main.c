/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:53:16 by mreinald          #+#    #+#             */
/*   Updated: 2025/02/27 16:54:01 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*create_stack(t_stack *stack_a, t_stack *stack_b, int v, char **str)
{
	if (v < 2 || (v == 2 && !str[1][0]))
		exit_handler(stack_a, stack_b, 1);
	if (v == 2)
		str = ft_split(str[1], ' ');
	if (check_errors(&stack_a, str))
		exit_handler(stack_a, stack_b, 0);
	return (stack_a);
}

int	main(int v, char **str)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_cost_index	*info;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(stack_a, stack_b, v, str);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			op_swap(&stack_a, SA);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_all(&stack_a, &info);
	}
	exit_handler(stack_a, stack_b, 1);
}
