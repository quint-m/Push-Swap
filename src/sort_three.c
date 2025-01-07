/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:05:54 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/07 19:20:28 by qmennen          ###   ########.fr       */
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

void	sort_three(t_stacks *stacks)
{
	long	first;
	long	second;
	long	third;

	first = stacks->a_head->content;
	second = stacks->a_head->next->content;
	third = stacks->a_head->next->next->content;
	sort(stacks, first, second, third);
}
