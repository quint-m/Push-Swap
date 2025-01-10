/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:05:54 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 16:46:59 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stacks *stacks, long first, long second, long third)
{
	if (first > second && first < third && second < third)
		ft_swap(stacks, 'a');
	else if (first > second && first > third && second < third)
		ft_rotate(stacks, 'a');
	else if (first < second && first > third && second > third)
		ft_rev_rotate(stacks, 'a');
	else if (first > second && first > third && second > third)
	{
		ft_swap(stacks, 'a');
		ft_rev_rotate(stacks, 'a');
	}
	else if (first < second && first < third && second > third)
	{
		ft_swap(stacks, 'a');
		ft_rotate(stacks, 'a');
	}
}

void	sort_three(t_stacks *stacks, int flag)
{
	long	first;
	long	second;
	long	third;

	first = stacks->a_head->content;
	second = stacks->a_head->next->content;
	third = stacks->a_head->next->next->content;
	sort(stacks, first, second, third);
	if (flag)
	{
		ft_freeall(stacks);
		exit(0);
	}
}

void	sort_two(t_stacks *stacks)
{
	long	first;
	long	second;

	first = stacks->a_head->content;
	second = stacks->a_head->next->content;
	if (first > second)
		ft_swap(stacks, 'a');
	ft_freeall(stacks);
	exit(0);
}

void	sort_four(t_stacks *stacks)
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
	ft_push(stacks, 'b');
	sort_three(stacks, 0);
	move_back(stacks);
	ft_freeall(stacks);
	exit(0);
}
