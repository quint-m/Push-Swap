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
		a_head = a_head->next;
		solve_doubles(stacks);
		calculate_cost(stacks, i);
	}
}

void	calculate_cost(t_stacks *stacks, int i)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra + stacks->moves->rb + stacks->moves->rra + stacks->moves->rrb + stacks->moves->rr + stacks->moves->rrr;

	if (i == 1 || (stacks->cheap->cost > stacks->moves->cost))
	{
		stacks->cheap->cost = stacks->moves->cost;
		stacks->cheap->ra = stacks->moves->ra;
		stacks->cheap->rb = stacks->moves->rb;
		stacks->cheap->rra = stacks->moves->rra;
		stacks->cheap->rrb = stacks->moves->rrb;
		stacks->cheap->rrr = stacks->moves->rrr;
		stacks->cheap->rr = stacks->moves->rr;
		stacks->cheap->pb = stacks->moves->pb;
		ft_printf("--- cheapest(%i)---\n", i);
		ft_printf("ra %i rb: %i\n", stacks->cheap->ra, stacks->cheap->rb);
		ft_printf("rra %i rrb: %i\n", stacks->cheap->rra, stacks->cheap->rrb);
		ft_printf("rr %i rrr: %i\n", stacks->cheap->rr, stacks->cheap->rrr);
		ft_printf("pb %i\n", stacks->cheap->pb);
		ft_printf("------------------\n");
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
