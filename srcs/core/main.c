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

t_stack *create_stack(t_stack *stack_a, t_stack *stack_b, int v, char **str)
{
	if (v < 2 || (v == 2 && !str[1][0]))
		error_handler(stack_a, stack_b, 1);
	if (v == 2)
		str = ft_split(str[1], ' ');
	if (check_errors(stack_a, str))
		error_handler(stack_a, stack_b, 1);
}

int	main(int v, char **str)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(stack_a, stack_b, v, str);
	return (0);
}
