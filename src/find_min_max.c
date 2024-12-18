/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:21:26 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/18 19:27:11 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_b(t_stack_item *b_head, t_stacks *stacks)
{
	t_stack_item	*current;

	current = b_head;
	stacks->values->b_min = b_head->content;
	while(current)
	{
		if (current->content < stacks->values->b_min)
			stacks->values->b_min = current->content;
		current = current->next;
	}
}

static void	find_max_b(t_stack_item *b_head, t_stacks *stacks)
{
	t_stack_item	*current;

	current = b_head;
	stacks->values->b_max = b_head->content;
	while(current)
	{
		if (current->content > stacks->values->b_max)
			stacks->values->b_max = current->content;
		current = current->next;
	}
}

static void	find_min_a(t_stack_item *a_head, t_stacks *stacks)
{
	t_stack_item	*current;

	current = a_head;
	stacks->values->a_min = a_head->content;
	while(current)
	{
		if (current->content < stacks->values->a_min)
			stacks->values->a_min = current->content;
		current = current->next;
	}
}

static void	find_max_a(t_stack_item *a_head, t_stacks *stacks)
{
	t_stack_item	*current;

	current = a_head;
	stacks->values->a_max = a_head->content;
	while(current)
	{
		if (current->content > stacks->values->a_max)
			stacks->values->a_max = current->content;
		current = current->next;
	}
}
void	min_max(t_stacks *stacks, char c)
{
	if (c == 'b' && stacks->b_head != NULL)
	{
		find_min_b(stacks->b_head, stacks);
		find_max_b(stacks->b_head, stacks);
	}
	else if (c == 'a' && stacks->a_head != NULL)
	{
		find_min_a(stacks->a_head, stacks);
		find_max_a(stacks->a_head, stacks);
	}
}
