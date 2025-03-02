/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:38:43 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/02 16:53:01 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	aux_check_dup(char **str, int *count, int *max_int, int *min_int)
{
	int	temp;

	while (str[*count])
	{
		temp = ft_atoi(str[(*count)++]);
		if (temp < *min_int)
			*min_int = temp;
		if (temp > *max_int)
			*max_int = temp;
		(*count) ++;
	}
}

int	check_dup(char **str)
{
	int		count;
	int		max_int;
	int		min_int;
	int		temp;
	char	*hash_tab;

	count = 0;
	max_int = 0;
	min_int = 0;
	aux_check_dup(str, &count, &max_int, &min_int);
	hash_tab = ft_calloc(max_int - min_int + 1, sizeof(char));
	if (!hash_tab)
		return (1);
	max_int = 0;
	while (max_int < count)
	{
		int	temp = ft_atoi(str[max_int]);
		if (hash_tab[temp - min_int])
			return (free(hash_tab), 1);
		hash_tab[temp - min_int] = 1;
		++max_int;
	}
	return (0);
}

int	check_errors(t_stack **stack_a, char **str)
{
	int	i;

	i = 0;
	if (check_dup(str))
		return (1);
	while (str[i])
	{
		if (!ft_atoi_check(str[i]) && ft_atoi(str[i]) != 0)
			return (1);
		*stack_a = add_node_front(*stack_a, ft_atoi(str[i]));
		i ++;
	}
	return (0);
}
