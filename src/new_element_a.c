/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_element_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:19:57 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 12:43:25 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_moves(t_stacks *stacks)
{
	while (stacks->moves->ra-- > 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- > 0)
		ft_rev_rotate(stacks, 'a');
}

void	new_element_a(t_stacks *stacks, t_stack_item *b_head)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->a_head->content != search_num_a(stacks, b_head->content))
	{
		i = find_index_a(stacks, search_num_a(stacks, b_head->content));
		size = ft_listsize(stacks->a_head);
		if (i > size / 2)
			stacks->moves->rra = size - i;
		else
			stacks->moves->ra = i;
	}
	do_moves(stacks);
	ft_push(stacks, 'a');
}
