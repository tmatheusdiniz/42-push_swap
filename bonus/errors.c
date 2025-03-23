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

#include "./checker.h"

// in this case i come back for first element
// at the left side and so i clean all.

static void	clean_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = first_node(stack);
	while (current)
	{
		next = current->next;
		free (current);
		current = next;
	}
}

static void	clean_get(char *line)
{
	if (line)
		free (line);
	line = get_next_line(0);
	while (line)
	{
		free (line);
		line = get_next_line(0);
	}
}

void	exit_handler_2(t_stack *stack_a, t_stack *stack_b, char *line, int flag)
{
	if (stack_a)
		clean_stack(stack_a);
	if (stack_b)
		clean_stack(stack_b);
	if (line)
		clean_get(line);
	if (flag == 1)
		exit (1);
	else
		write (2, "Error\n", 6);
	exit (1);
}

void	exit_handler(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (stack_a)
		clean_stack(stack_a);
	if (stack_b)
		clean_stack(stack_b);
	if (flag == 1)
		exit (1);
	else
		write (2, "Error\n", 6);
	exit (1);
}
