/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:25:41 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 16:46:04 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackmin(t_stack *stack)
{
	int		min;
	t_data	*current;

	current = stack->head;
	min = current->val;
	while (current)
	{
		if (min > current->val)
			min = current->val;
		current = current->next;
	}
	return (min);
}

// calculate where in stack the number num should go
int		ft_stackpos(int	num, t_stack *stack)
{
	int		i;
	int		dist;
	t_data	*current;

	i = 0;
	current = stack->head;
	dist = 999;
	while (current)
	{
		if (current->val > num)
		{
			current = current->next;
			continue;
		}
		if (dist > num - current->val)
		{
			dist = num - current->val;
			i = current->val;
		}
		current = current->next;
	}
	return (i);
}
