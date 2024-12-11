/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:58:39 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 12:10:54 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_rotations(int num, t_stack *stack)
{
	t_data	*current;
	int		pos_top;

	current = stack->head;
	pos_top = 0;
	while (current)
	{
		if (current->val == num)
			break ;
		pos_top++;
		current = current->next;
	}
	if (pos_top <= stack->size / 2)
		return (pos_top);
	else
		return (-(stack->size - pos_top));
}

static int	calculate_cost(int a_index, t_stack *a, t_stack *b)
{
	t_data	*a_data;
	int		rotations_b;
	int		rotations_a;
	int		overlap;
	int		i;

	a_data = a->head;
	i = 0;
	while (i < a_index && a_data->next)
	{
		a_data = a_data->next;
		i++;
	}
	rotations_b = calculate_rotations(ft_stackmax(b), b);
	rotations_a = calculate_rotations(a_data->val, a);
	overlap = 0;
	if ((rotations_a > 0 && rotations_b > 0)
		|| (rotations_a < 0 && rotations_b < 0))
	{
		overlap = ft_min(ft_abs(rotations_a), ft_abs(rotations_b));
		rotations_a -= overlap;
		rotations_b -= overlap;
	}
	return (overlap + ft_max(ft_abs(rotations_a), ft_abs(rotations_b)) + 1);
}

int	cheapest_index(t_stack *a, t_stack *b)
{
	t_data	*current;
	int		l_cost;
	int		cost;
	int		i;
	int		cheapest;

	i = 0;
	cheapest = 0;
	l_cost = 999;
	current = a->head;
	while (current)
	{
		cost = calculate_cost(i, a, b);
		if (cost < l_cost)
		{
			l_cost = cost;
			cheapest = i;
		}
		current = current->next;
		i++;
	}
	return (cheapest);
}

int	move(t_stack *a, t_stack *b, int idx)
{
	t_data	*a_data;
	int		i;
	int		a_rot;
	int		b_rot;
	int		overlap;

	a_data = a->head;
	i = 0;
	while (i < idx && a_data->next)
	{
		a_data = a_data->next;
		i++;
	}
	b_rot = calculate_rotations(ft_stackmax(b), b);
	a_rot = calculate_rotations(a_data->val, a);
	overlap = 0;
	
	if ((a_rot > 0 && b_rot > 0)
		|| (a_rot < 0 && b_rot < 0))
	{
		overlap = ft_min(ft_abs(a_rot), ft_abs(b_rot));
	}
	while (overlap-- > 0)
		rr(a, b);
	while (b_rot-- > 0)
	{
		rotate(b);
		ft_printf("rb\n");
	}
	pb(a, b);
}
