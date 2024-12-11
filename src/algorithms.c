/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:58:39 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 15:15:00 by qmennen          ###   ########.fr       */
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
	int		rot_a;
	int		rot_b;
	int		overlap;
	int		i;

	a_data = a->head;
	i = 0;
	while (i < a_index && a_data->next)
	{
		a_data = a_data->next;
		i++;
	}
	rot_a = calculate_rotations(a_data->val, a);
	if (a_data->val > ft_stackmax(b) || a_data->val < ft_stackmin(b))
		rot_b = calculate_rotations(ft_stackmax(b), b);
	else
		rot_b = calculate_rotations(ft_stackpos(a_data->val, b), b);
	overlap = 0;
	if ((rot_a > 0 && rot_b > 0)
		|| (rot_a < 0 && rot_b < 0))
	{
		/*
		overlap = ft_min(ft_abs(rot_a), ft_abs(rot_b));
		rot_a -= overlap * ft_sign();
		rot_b -= overlap;
		*/
	}
	return (overlap + ft_abs(rot_a) + ft_abs(rot_b) + 1);
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
		ft_printf("cost for %i is %i\n", current->val, cost);
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
	int		rot_a;
	int		rot_b;
	int		overlap;

	a_data = a->head;
	i = 0;
	while (i < idx && a_data->next)
	{
		a_data = a_data->next;
		i++;
	}
	rot_a = calculate_rotations(a_data->val, a);
	if (a_data->val > ft_stackmax(b) || a_data->val < ft_stackmin(b))
		rot_b = calculate_rotations(ft_stackmax(b), b);
	else
		rot_b = calculate_rotations(ft_stackpos(a_data->val, b), b);
	overlap = 0;
	
	if ((rot_a > 0 && rot_b > 0)
		|| (rot_a < 0 && rot_b < 0))
	{
		overlap = ft_min(ft_abs(rot_a), ft_abs(rot_b));
	}
	while (overlap-- > 0)
		rr(a, b);
	while (rot_b-- > 0)
		rb(b);
	while (rot_b-- > 0)
		ra(b);
	pb(a, b);
}
