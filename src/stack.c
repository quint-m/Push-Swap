/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:05:31 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/10 18:03:37 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, long val)
{
	t_data	*new;

	if (! stack)
		return ;
	new = ft_calloc(1, sizeof(t_data));
	new->val = val;
	new->next = stack->head;
	stack->head = new;
	stack->size += 1;
}

void	pop(t_stack *stack)
{
	t_data	*last;

	if (! stack->head)
		return ;
	last = stack->head;
	stack->head = stack->head->next;
	stack->size -= 1;
	free(last);
}

void	swap(t_stack *stack)
{
	t_data	*last;
	t_data	*third;

	if (stack->size < 2)
		return ;
	last = stack->head;
	third = stack->head->next->next;
	stack->head = stack->head->next;
	stack->head->next = last;
	stack->head->next->next = third;
}

void	rotate(t_stack *stack)
{
	t_data	*current;
	t_data	*head;
	t_data	*new_top;

	if (stack->size < 2)
		return ;
	head = stack->head;
	current = stack->head;
	new_top = stack->head->next;
	while (current->next != NULL)
		current = current->next;
	current->next = head;
	head->next = NULL;
	stack->head = new_top;
}

void	r_rotate(t_stack *stack)
{
	t_data	*current;
	t_data	*second;

	if (stack->size < 2)
		return ;
	current = stack->head;
	while (current->next != NULL)
	{
		second = current;
		current = current->next;
	}
	second->next = NULL;
	current->next = stack->head;
	stack->head = current;
}
