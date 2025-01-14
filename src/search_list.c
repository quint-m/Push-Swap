/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:34:52 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 12:40:34 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_b(t_stacks *stacks, int num)
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

int	find_index_a(t_stacks *stacks, int num)
{
	int				i;
	int				size;
	t_stack_item	*current;

	i = 0;
	current = stacks->a_head;
	size = ft_listsize(stacks->a_head);
	while (i < size)
	{
		if (current->content == num)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

long	search_num_b(t_stacks *stacks, int num)
{
	t_stack_item	*head_b;
	int				size;
	int				flag;
	int				i;

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

long	search_num_a(t_stacks *stacks, int num)
{
	t_stack_item	*head_a;
	int				size;
	int				flag;
	int				i;

	i = 0;
	flag = 0;
	head_a = stacks->a_head;
	size = ft_listsize(stacks->a_head);
	while (flag == 0)
	{
		i = 0;
		num++;
		head_a = stacks->a_head;
		while (i++ < size)
		{
			if (head_a->content == num)
				flag = 1;
			head_a = head_a->next;
		}
	}
	return (num);
}

void	get_top_of_a(t_stacks *stacks, t_stack_item *a_head, int i)
{
	int	size;

	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->a_head->content == a_head->content)
		return ;
	size = ft_listsize(stacks->a_head);
	if (i > size / 2)
		stacks->moves->rra = size - i;
	else
		stacks->moves->ra = i;
}
