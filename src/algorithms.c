/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:58:39 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 17:43:07 by qmennen          ###   ########.fr       */
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
	{
		rot_b = calculate_rotations(ft_stackpos(a_data->val, b), b);
	}
	overlap = 0;
	if ((rot_a > 0 && rot_b > 0)
		|| (rot_a < 0 && rot_b < 0))
	{
		overlap = ft_min(ft_abs(rot_a), ft_abs(rot_b));
		rot_a -= overlap * ft_sign(rot_a);
		rot_b -= overlap * ft_sign(rot_b);
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

void	move(t_stack *a, t_stack *b, int idx)
{
	t_data	*a_data;
	int		i;
	int		rot_a;
	int		rot_b;
	int		overlap;
	int		sign;

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
	{
		rot_b = calculate_rotations(ft_stackpos(a_data->val, b), b);
	}
	overlap = 0;
	sign = 1;
	if ((rot_a > 0 && rot_b > 0)
		|| (rot_a < 0 && rot_b < 0))
	{
		sign = ft_sign(rot_a);
		overlap = ft_min(ft_abs(rot_a), ft_abs(rot_b));
		rot_a -= overlap * sign;
		rot_b -= overlap * sign;
		overlap *= sign;
	}
	while (overlap < 0)
	{
		rrr(a, b);
		overlap++;
	}
	while (overlap-- > 0)
		rr(a, b);
	while (rot_b-- > 0)
		rb(b);
	while (rot_b-- > 0)
		ra(b);
	pb(a, b);
}

void	push_back(t_stack *a, t_stack *b)
{
	int		rot_a;
	int		next;
	t_data	*current;

	while (b->size > 0)
	{
		rot_a = calculate_rotations(ft_rstackpos(b->head->val, a), a);
		while (rot_a > 0)
		{
			ra(a);
			rot_a--;
		}
		while (rot_a < 0)
		{
			rra(a);
			rot_a++;
		}
		pa(a, b);
	}
}
