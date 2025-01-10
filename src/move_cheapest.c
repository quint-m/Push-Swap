/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:15:28 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 16:58:11 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stacks *stacks)
{
	t_moves		*moves;
	t_moves		*cheap;
	t_values	*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheap = ft_calloc(1, sizeof(t_moves));
	stacks->cheap = cheap;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	while (ft_listsize(stacks->a_head) != 3)
	{
		min_max(stacks, 'b');
		check_moves(stacks);
		do_cheap_moves(stacks);
	}
}

void	do_cheap_moves(t_stacks *stacks)
{
	while (stacks->cheap->rb-- > 0)
		ft_rotate(stacks, 'b');
	while (stacks->cheap->ra-- > 0)
		ft_rotate(stacks, 'a');
	while (stacks->cheap->rrb-- > 0)
		ft_rev_rotate(stacks, 'b');
	while (stacks->cheap->rra-- > 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->cheap->rr-- > 0)
		ft_rotate(stacks, ' ');
	while (stacks->cheap->rrr-- > 0)
		ft_rev_rotate(stacks, ' ');
	while (stacks->cheap->pb-- > 0)
		ft_push(stacks, 'b');
}
