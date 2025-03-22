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
#include <string.h>

t_stack	*create_stack(t_stack *stack_a, t_stack *stack_b, int v, char **str)
{
	char	*push_s;

	if (v < 2 || (v == 2 && !str[1][0]))
		exit_handler(stack_a, stack_b, 1);
	if (v == 2)
		str = ft_split(str[1], ' ');
	if (!str || !str[0] || !str[1])
	{
		clean_matrix(str);
		exit(1);
	}
	v = 0;
	push_s = ft_substr(str[0], ft_strlen(str[0]) - 9, ft_strlen(str[0]));
	if (!(strncmp(push_s, "push_swap", 9)))
		v = 1;
	if (check_errors(&stack_a, str))
	{
		if (!v)
			clean_matrix(str);
		free (push_s);
		exit_handler(stack_a, stack_b, 0);
	}
	if (v)
		return (free(push_s), stack_a);
	return (free(push_s), clean_matrix(str), stack_a);
}

int	main(int v, char **str)
{
	t_stack			*stack_a;
	t_stack			*stack_b;

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
			sort_all(&stack_a, &stack_b);
	}
	exit_handler(stack_a, stack_b, 1);
}
