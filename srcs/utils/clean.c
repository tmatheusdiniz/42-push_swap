/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:19:53 by mreinald          #+#    #+#             */
/*   Updated: 2025/03/03 14:23:17 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	clean_matrix(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free (str[i++]);
	free (str);
}
