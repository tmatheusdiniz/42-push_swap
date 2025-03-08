/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:21:17 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/21 20:33:41 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../lib/Libft/include/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_cost_index
{
	int	cost;
	int	index;
}	t_cost_index;

// Core
int		main(int c, char **str);

// Parse
int		check_errors(t_stack **stack_a, char **str);

// Stack
t_stack	*first_node(t_stack *stack);
t_stack	*last_node(t_stack *stack);
t_stack	*add_node_front(t_stack *stack, int content);

// Operations
int		op_pa(t_stack **stack_a, t_stack **stack_b);
int		op_pb(t_stack **stack_a, t_stack **stack_b);
int		op_swap(t_stack **stack, int mov);
int		op_s_s(t_stack **stack_a, t_stack **stack_b);
int		op_rotate(t_stack **stack, int mov);
int		op_reverse_rotate(t_stack **stack, int mov);
int		op_r_rotate(t_stack **stack_a, t_stack **stack_b);
int		op_rev_r_rotate(t_stack **stack_a, t_stack **stack_b);

// Errors
void	error_handler(t_stack *stack_a, t_stack *stack_b, int flag);

// Utils
int		ft_atoi_check(char *nptr);

#endif
