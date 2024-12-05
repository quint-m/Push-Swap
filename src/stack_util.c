/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:05:31 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/05 16:05:47 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, long val)
{
	t_data	*new;
	if (!stack)
		return;
	new = ft_calloc(1, sizeof(t_data));
	new->val = val;
	new->next = stack->head;
	stack->head = new;
	stack->size += 1;
}

void	pop(t_stack *stack)
{
	t_data	*last;
	if (!stack->head)
		return;
	last = stack->head;
	stack->head = stack->head->next;
	free(last);
}
