/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:30:07 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/12 15:40:56 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_closest(int n, t_stack *stack)
{
	int 	diff;
	int		min_diff;
	int		l_val;
	t_data	*current;

	if (stack->size == 0)
		return (0);
	current = stack->head;
	l_val = current->val;
	min_diff = ft_abs(n - current->val);

	while (current)
	{
		diff = ft_abs(n - current->val);
		// TODO: This is either of two. Example: n (6), closest is 5 or 7 depending on stack order
		if (diff <= min_diff)
		{
			min_diff = diff;
			l_val = current->val;
		}
		current = current->next;
	}
	return (l_val);
}

int	st_rotations(int n, t_stack *stack)
{
	int	i;

	i = st_indexof(n, stack);
	if (i > stack->size / 2)
		return (-(stack->size - i));
	else
		return i;
	return (i);
}

int	rot_overlap(int a_rot, int b_rot)
{
	if (a_rot * b_rot < 0)
		return (0);
	return (ft_min(ft_abs(a_rot), ft_abs(b_rot)));
}

int	cost(int a_idx, t_stack *a, t_stack *b)
{
	int	a_val;
	int	a_rot;
	int	b_rot;

	a_val = stack_at(a_idx, a);
	a_rot = st_rotations(a_val, a);
	if (a_val >= stack_max(b) || a_val <= stack_min(b))
		b_rot = st_rotations(stack_max(b), b);
	else
		b_rot = st_rotations(st_closest(a_val, b), b);
	return ((ft_abs(a_rot) + ft_abs(b_rot)) - rot_overlap(a_rot, b_rot) + 1);
}
