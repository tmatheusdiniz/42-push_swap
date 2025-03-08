/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:48:53 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/08 21:56:55 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_a_to_b(t_stack *a, t_stack *b)
{
	while (stack_len(a) > 3 && stack_len(b) < 3)
		op_pb(&a, &b);
	// complete after
}
