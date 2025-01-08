/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:39:56 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 12:45:31 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_stack_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- > 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- > 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}

void	new_max_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (ft_listlast(stacks->a_head)->content != stacks->values->a_max)
	{
		i = find_index_a(stacks, stacks->values->a_max);
		size = ft_listsize(stacks->a_head);
		if (i > size / 2)
			stacks->moves->rra = size - i;
		else
			stacks->moves->ra = i;
	}
	move_stack_a(stacks);
	ft_rotate(stacks, 'a');
}

void	new_min_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (ft_listlast(stacks->a_head)->content != stacks->values->a_min)
	{
		i = find_index_a(stacks, stacks->values->a_min);
		size = ft_listsize(stacks->a_head);
		if (i > size / 2)
			stacks->moves->rra = size - i;
		else
			stacks->moves->ra = i;
	}
	move_stack_a(stacks);
}
