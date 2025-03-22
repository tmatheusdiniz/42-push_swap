/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:26:28 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/22 19:47:11 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"
#include <stdlib.h>
#include <unistd.h>

static t_stack	*create_stack(t_stack *stack_a,
		t_stack *stack_b, int v, char **str)
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

static void	stack_valid(t_stack *stack_a, t_stack *stack_b, int flag, int count)
{
	char	*number_v;

	write(1, BOLD_RED, 7);
	if (stack_sorted(stack_a) && !(stack_len(stack_b)))
	{
		write (1, "OK\n", 3);
		if (flag)
		{
			write(1, RESET, 4);
			number_v = ft_itoa(count);
			if (!number_v)
				exit_handler(stack_a, stack_b, 0);
			write(1, COLOR_GREEN, 5);
			write (1, "Number of movements made: ", 26);
			write(1, RESET, 4);
			write(1, COLOR_BLUE, 5);
			write(1, number_v, ft_strlen(number_v));
			free (number_v);
		}
	}
	else
		write(1, "KO\n", 3);
	write(1, RESET, 4);
}

int	main(int v, char **str)
{
	int		count;
	int		flag;
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(stack_a, stack_b, v, str);
	count = 0;
	flag = 0;
	if (!(strncmp(str[1], "-c", 2)))
		flag = 1;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (filter_op(&stack_a, &stack_b, line))
			exit_handler_2(stack_a, stack_b, line, 0);
		count ++;
		free (line);
	}
	stack_valid(stack_a, stack_b, flag, count);
	exit_handler_2(stack_a, stack_b, line, 1);
}
