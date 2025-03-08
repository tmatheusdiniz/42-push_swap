/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:30:07 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/02 14:36:07 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	clean_stack(t_stack *stack);

// in this case i come back for first element
// at the left side and so i clean all.

static void	clean_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current && current->prev)
		current = current->prev;
	while (current)
	{
		next = current->next;
		free (current);
		current = next;
	}
}

void	error_handler(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (stack_a)
		clean_stack(stack_a);
	if (stack_b)
		clean_stack(stack_b);
	if (flag == 1)
		exit (1);
	else
		ft_printf("Error\n");
	exit (1);
}
