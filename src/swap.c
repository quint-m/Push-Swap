/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:36:52 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/07 19:32:20 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_a(t_stack_item *a_head)
{
	int	tmp_content;

	if (!a_head || !a_head->next)
		return ;
	tmp_content = a_head->content;
	a_head->content = a_head->next->content;
	a_head->next->content = tmp_content;
}

static void	ft_swap_b(t_stack_item *b_head)
{
	int	tmp_content;

	if (!b_head || !b_head->next)
		return ;
	tmp_content = b_head->content;
	b_head->content = b_head->next->content;
	b_head->next->content = tmp_content;
}

void	ft_swap(t_stacks *stacks, char c)
{
	if (c == 'b')
		ft_swap_b(stacks->b_head);
	else if (c == 'a')
		ft_swap_a(stacks->a_head);
}
