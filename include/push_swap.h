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

typedef struct s_cost_index
{
	int	cost;
	int	cheapest;
	int	index;
	int	above_median;
}	t_cost_index;

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
	t_cost_index	*info;
}	t_stack;

// Core
int		main(int c, char **str);

// Parse
int		check_errors(t_stack **stack_a, char **str);

// Stack
int		stack_len(t_stack *stack);
int		stack_sorted(t_stack *stack);
t_stack	*first_node(t_stack *stack);
t_stack	*last_node(t_stack *stack);
t_stack	*add_node_front(t_stack *stack, int content);

// Sorting
void	sort_all(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	init_node_a(t_stack *stack_a, t_stack *stack_b);
void	init_node_b(t_stack *stack_a, t_stack *stack_b);

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
void	exit_handler(t_stack *stack_a, t_stack *stack_b, int flag);

// Utils
int		ft_atoi_check(char *nptr);
void	prep_for_push(t_stack **stack, t_stack *top, char wt_stack);
void	current_index(t_stack *stack);
void	min_on_top(t_stack **stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);

#endif
