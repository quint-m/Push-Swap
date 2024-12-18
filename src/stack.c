/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:32:58 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/18 12:41:24 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_stacks *stacks)
{
	t_stack_item	*tmp;

	tmp = stacks->a_head;
	stacks->a_head = stacks->b_head;
	stacks->b_head = stacks->b_head->next;
	stacks->a_head->next = tmp;
	ft_printf("pa\n");
}

static void	push_b(t_stacks *stacks)
{
	t_stack_item	*tmp;

	tmp = stacks->b_head;
	stacks->b_head = stacks->a_head;
	stacks->a_head = stacks->a_head->next;
	stacks->b_head->next = tmp;
	ft_printf("pb\n");
}

void	ft_push(t_stacks *stacks, char c)
{
	if (c == 'b')
		push_b(stacks);
	else if (c == 'a')
		push_a(stacks);
}
