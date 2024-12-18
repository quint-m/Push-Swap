/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:15:28 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/18 19:17:50 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stacks *stacks)
{
	t_moves		*moves;
	t_values	*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;

	while (ft_listsize(stacks->a_head) > 3)
	{
		min_max(stacks, 'b');
		break;
	}
}
