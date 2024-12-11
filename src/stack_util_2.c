/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:25:41 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 17:45:05 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Find the smallest number in `stack`
 */
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

/*
 * Find the biggest number in `stack`
 */
int	ft_stackmax(t_stack *stack)
{
	int		max;
	t_data	*current;

	current = stack->head;
	max = current->val;
	while (current)
	{
		if (max < current->val)
			max = current->val;
		current = current->next;
	}
	return (max);
}

/*
 * Find the next smallest number after `num` in `stack`
 */
int		ft_stackpos(int	num, t_stack *stack)
{
	int		i;
	int		c_dist;
	t_data	*current;

	i = 0;
	current = stack->head;
	c_dist = INT_MAX;
	while (current)
	{
		if (current->val < num && c_dist > num - current->val)
		{
			c_dist = num - current->val;
			i = current->val;
		}
		current = current->next;
	}
	return (i);
}

/*
 * Find the next biggest number after `num` in `stack`
 */
int		ft_rstackpos(int num, t_stack *stack)
{
	int		i;
	int		c_dist;
	t_data	*current;

	i = 0;
	current = stack->head;
	c_dist = INT_MAX;
	while (current)
	{
		if (current->val > num && c_dist > current->val - num)
		{
			c_dist = current->val - num; 
			i = current->val;
		}
		current = current->next;
	}
	return (i);
}
