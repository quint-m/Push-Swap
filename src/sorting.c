/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:43:58 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 17:01:51 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stacks *stacks)
{
	int				i;
	int				size;
	t_stack_item	*last;
	t_stack_item	*head;

	head = stacks->a_head;
	i = 0;
	size = ft_listsize(stacks->a_head);
	while (i < size)
	{
		last = head;
		head = head->next;
		if (last->content > head->content)
			return (0);
		i++;
	}
	return (1);
}

void	sorting(t_stacks *stacks)
{
	int	size;

	size = ft_listsize(stacks->a_head);
	if (size == 2)
		sort_two(stacks);
	else if (size == 3)
		sort_three(stacks, 1);
	else if (size == 4)
		sort_four(stacks);
	if (check_order(stacks))
		return ;
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_cheapest(stacks);
	sort_three(stacks, 0);
	move_back(stacks);
}
