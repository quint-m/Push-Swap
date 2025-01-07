/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:46:44 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/07 19:28:18 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_a(t_stack_item *a_head)
{
	t_stack_item	*current;

	current = a_head;
	while (current)
	{
		ft_printf("%i\n", current->content);
		current = current->next;
	}
	ft_printf("a\n");
}

static void	ft_print_b(t_stack_item *b_head)
{
	t_stack_item	*current;

	current = b_head;
	while (current)
	{
		ft_printf("%i\n", current->content);
		current = current->next;
	}
	ft_printf("b\n");
}

void	ft_print_list(t_stacks *stacks, char c)
{
	if (c == 'b')
		ft_print_b(stacks->b_head);
	else if (c == 'a')
		ft_print_a(stacks->a_head);
	else
	{
		ft_print_a(stacks->a_head);
		ft_printf(" \n");
		ft_print_b(stacks->b_head);
	}
}
