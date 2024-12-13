/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:50:20 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/12 14:52:54 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_stacks(t_stack *a, t_stack *b)
{
	t_data	*a_cur;
	t_data	*b_cur;
	int		diff;

	diff = a->size - b->size;
	a_cur = a->head;
	b_cur = b->head;
	while (diff < 0 && b_cur)
	{
		ft_printf("   %i\n", b_cur->val);
		diff++;
		b_cur = b_cur->next;
	} 
	while (diff > 0 && a_cur)
	{
		ft_printf("%i   \n", a_cur->val);
		diff--;
		a_cur = a_cur->next;
	}
	while (diff == 0)
	{
		if (a_cur == NULL && b_cur == NULL)
			break;
		ft_printf("%i %i\n", a_cur->val, b_cur->val);
		a_cur = a_cur->next;
		b_cur = b_cur->next;
	}
	ft_printf("=====\na  b\n");
}

int		stack_max(t_stack *stack)
{
	int		max;
	t_data	*current;

	current = stack->head;
	max = 0;
	while (current)
	{
		if (current->val > max)
			max = current->val;
		current = current->next;
	}
	return (max);
}

int		stack_min(t_stack *stack)
{
	int		min;
	t_data	*current;

	current = stack->head;
	min = INT_MAX;
	while (current)
	{
		if (current->val < min)
			min = current->val;
		current = current->next;
	}
	return (min);
}

int		stack_at(int i, t_stack *stack)
{
	t_data	*current;
	int		val_at;

	if (i >= stack->size)
		return (-1);	
	current = stack->head;
	val_at = current->val;
	while (i > 0 && current)
	{
		current = current->next;
		val_at = current->val;
		i--;
	}
	
	return (val_at);
}

int		st_indexof(int n, t_stack *stack)
{
	t_data	*current;
	int		i;
	
	i = 0;
	current = stack->head;
	while (current)
	{
		if (current->val == n)
			break ;
		current = current->next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack *stack)
{
	t_data	*current;
	t_data	*last;

	current = stack->head;
	while(current)
	{
		last = current;
		current = current->next;
		free(last);
	}
	free(stack);
}
