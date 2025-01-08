/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:35:55 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 12:51:55 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_moves(t_stacks *stacks)
{
	while(stacks->moves->rra-- > 0)
		ft_rev_rotate(stacks, 'a');
	while(stacks->moves->ra-- > 0)
		ft_rotate(stacks, 'a');
}

static void	fix_order(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->rra = 0;
	stacks->moves->ra = 0;
	if (stacks->a_head->content != stacks->values->a_min)
	{
		i = find_index_a(stacks, stacks->values->a_min);
		size = ft_listsize(stacks->a_head);
		if (i > size / 2)
			stacks->moves->rra = size - i;
		else
			stacks->moves->ra = i;
	}
	do_moves(stacks);
}

void	move_back(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->b_head != NULL)
	{
		min_max(stacks, 'a');
		if (stacks->b_head->content < stacks->values->a_min)
			new_min_a(stacks);
		else if (stacks->b_head->content > stacks->values->a_max)
			new_max_a(stacks);
		else
			new_element_a(stacks, stacks->b_head);
		i++;
	}
	min_max(stacks, 'a');
	fix_order(stacks);
}
