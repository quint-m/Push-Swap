/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:50:02 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/07 19:42:40 by qmennen          ###   ########.fr       */
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
