/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:50:02 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 13:03:15 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_item	*ft_newnode(long val)
{
	t_stack_item	*res;

	res = malloc(sizeof(t_stack_item));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->content = val;
	return (res);
}

int	ft_listsize(t_stack_item *list)
{
	int				size;
	t_stack_item	*tail;

	size = 0;
	tail = list;
	while (tail)
	{
		size++;
		tail = tail->next;
	}
	return (size);
}

t_stack_item	*ft_listlast(t_stack_item *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

static void			ft_clearlist(t_stack_item *list)
{
	t_stack_item	*current;
	t_stack_item	*last;
	if (!list)
		return ;
	current = list;
	while (current)
	{
		last = current;
		current = current->next;
		free(last);
	}
	list = NULL;
}

void		ft_freeall(t_stacks *stacks)
{
	ft_clearlist(stacks->a_head);
	ft_clearlist(stacks->b_head);
	if (stacks->moves != NULL)
		free(stacks->moves);
	if (stacks->values != NULL)
		free(stacks->values);
	if (stacks->cheap != NULL)
		free(stacks->cheap);
}
