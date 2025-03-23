/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:11:49 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/22 19:29:03 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../lib/Libft/include/libft.h"

# define BOLD "\x1b[1m"
# define BOLD_RED "\033[1;31m"
# define COLOR_RED "\033[31m"
# define COLOR_GREEN "\033[32m"
# define COLOR_BLUE "\033[34m"
# define RESET "\033[0m"

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Core
int			main(int v, char **str);

// Check
int			check_errors(t_stack **stack, char **str);
long		ft_atoi_check(char *nptr);

// Stack
t_stack		*add_node_front(t_stack *stack, int content);
int			stack_sorted(t_stack *stack);
t_stack		*first_node(t_stack *stack);
t_stack		*last_node(t_stack *stack);
int			stack_len(t_stack *stack);

// Operations
int			filter_op(t_stack **stack_a, t_stack **stack_b, char *line);
int			op_swap(t_stack **stack);
int			op_s_s(t_stack **stack_a, t_stack **stack_b);
int			op_pa(t_stack **stack_a, t_stack **stack_b);
int			op_pb(t_stack **stack_a, t_stack **stack_b);
int			op_rotate(t_stack **stack);
int			op_reverse_rotate(t_stack **stack);
int			op_r_rotate(t_stack **stack_a, t_stack **stack_b);
int			op_rev_r_rotate(t_stack **stack_a, t_stack **stack_b);

// Clean
void		exit_handler(t_stack *stack_a, t_stack *stack_b, int flag);
void		exit_handler_2(t_stack *stack_a,
				t_stack *stack_b, char *line, int flag);
void		clean_matrix(char **str);

#endif
