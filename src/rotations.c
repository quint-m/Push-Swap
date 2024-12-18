/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:08:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/18 12:32:23 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_a(t_stacks *stacks, int print)
{
	t_stack_item	*a_tmp;
	t_stack_item	*current;

   if (!stacks->a_head || !stacks->a_head->next)
        return;
	a_tmp = stacks->a_head;
	current = stacks->a_head;
	stacks->a_head = stacks->a_head->next;
	while(current->next)
	{
		current = current->next;
	}
	a_tmp->next = NULL;
	current->next = a_tmp;
	if (print)
		ft_printf("ra\n");
}

static void	ft_rotate_b(t_stacks *stacks, int print)
{
	t_stack_item	*b_tmp;
	t_stack_item	*current;

   if (!stacks->b_head || !stacks->b_head->next)
        return;
	b_tmp = stacks->b_head;;
	current = stacks->b_head;;
	stacks->b_head = stacks->b_head->next;
	while(current->next)
	{
		current = current->next;
	}
	b_tmp->next = NULL;
	current->next = b_tmp;
	if (print)
		ft_printf("rb\n");
}

void	ft_rotate(t_stacks *stacks, char c)
{
	if (c == 'b')
		ft_rotate_b(stacks, 1);
	else if (c == 'a')
		ft_rotate_a(stacks, 1);
	else
	{
		ft_rotate_a(stacks, 0);
		ft_rotate_b(stacks, 0);
		ft_printf("rr\n");
	}
}
