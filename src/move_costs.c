/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:12:19 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/24 10:42:54 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_moves(t_stacks *stacks)
{
	int				size;
	t_stack_item	*a_head;
	int				i;

	size = ft_listsize(stacks->a_head);
	a_head = stacks->a_head;
	i = 0;
	while (i++ < size)
	{
		get_top_of_a(stacks, a_head, i - 1);
		if (a_head->content > stacks->values->b_max ||
			a_head->content < stacks->values->b_min)
			new_max_min_b(stacks);
		else
			new_num_b(stacks, a_head->content);
		ft_printf("for I %i: ra %i, rra %i, rb %i, rrb %i", i, stacks->moves->ra, stacks->moves->rra, stacks->moves->rb, stacks->moves->rrb);
		a_head = a_head->next;
	solve_doubles(stacks);
	ft_printf(" | rr %i, rrr %i\n", stacks->moves->rr, stacks->moves->rrr);
	}
}

void	solve_doubles(t_stacks *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;

	while (stacks->moves->rb != 0 && stacks->moves->ra != 0)
	{
		stacks->moves->rr++;
		stacks->moves->ra--;
		stacks->moves->rb--;
	}
	while (stacks->moves->rrb != 0 && stacks->moves->rra != 0)
	{
		stacks->moves->rrr++;
		stacks->moves->rra--;
		stacks->moves->rrb--;
	}
}
