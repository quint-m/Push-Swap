/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:34:52 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/19 11:39:10 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_index_b(t_stacks *stacks, long num)
{
	int				i;
	int				size;
	t_stack_item	*current;

	i = 0;
	current = stacks->b_head;
	size = ft_listsize(stacks->b_head);
	while (i < size)
	{
		if (current->content == num)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

long     search_num_b(t_stacks *stacks, long num)
{
	t_stack_item	*head_b;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_b = stacks->b_head;
	size = ft_listsize(stacks->b_head);
	while (flag == 0)
	{
		i = 0;
		num--;
		head_b = stacks->b_head;
		while (i++ < size)
		{
			if (head_b->content == num)
				flag = 1;
			head_b = head_b->next;
		}
	}
	return (num);
}
