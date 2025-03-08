/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:44:14 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/02 16:47:23 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	ft_count_bits_aux(long long number)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number > 0)
	{
		count++;
		number >>= 1;
	}
	return (count);
}

int	ft_atoi_check(char *nptr)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i ++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -sign;
		i ++;
	}
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (4);
		res = res * 10 + nptr[i++] - '0';
	}
	if (ft_count_bits_aux(res) > 32)
		return (4);
	return (res * sign);
}
