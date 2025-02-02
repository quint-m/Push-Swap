/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_positioning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:21:52 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/07 19:39:49 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_max_min_b(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->b_head->content == stacks->values->b_max)
		return ;
	i = find_index_b(stacks, stacks->values->b_max);
	size = ft_listsize(stacks->b_head);
	if (i > size / 2)
		stacks->moves->rrb = size - i;
	else
		stacks->moves->rb = i;
}

void	new_num_b(t_stacks *stacks, long num)
{
	int		i;
	long	nbr;
	int		size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = search_num_b(stacks, num);
	if (stacks->b_head->content == nbr)
		return ;
	i = find_index_b(stacks, nbr);
	size = ft_listsize(stacks->b_head);
	if (i > size / 2)
		stacks->moves->rrb = size - i;
	else
		stacks->moves->rb = i;
}
