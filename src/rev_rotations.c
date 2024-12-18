/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:25:56 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/18 12:34:07 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	ft_rev_rotate_a(t_stacks *stacks, int print)
{
	t_stack_item	*tail;
	t_stack_item	*previous;

   if (!stacks->a_head || !stacks->a_head->next)
        return;
	tail = stacks->a_head;;
	while(tail->next)
	{
		previous = tail;
		tail = tail->next;
	}
	previous->next = NULL;
	tail->next = stacks->a_head;
	stacks->a_head = tail;
	if (print)
		ft_printf("rra\n");
}

static void	ft_rev_rotate_b(t_stacks *stacks, int print)
{
	t_stack_item	*tail;
	t_stack_item	*previous;

   if (!stacks->b_head || !stacks->b_head->next)
        return;
	tail = stacks->b_head;;
	while(tail->next)
	{
		previous = tail;
		tail = tail->next;
	}
	previous->next = NULL;
	tail->next = stacks->b_head;
	stacks->b_head = tail;
	if (print)
		ft_printf("rrb\n");
}

void	ft_rev_rotate(t_stacks *stacks, char c)
{
	if (c == 'b')
		ft_rev_rotate_b(stacks, 1);
	else if (c == 'a')
		ft_rev_rotate_a(stacks, 1);
	else
	{
		ft_rev_rotate_a(stacks, 0);
		ft_rev_rotate_b(stacks, 0);
		ft_printf("rrr\n");
	}
}
