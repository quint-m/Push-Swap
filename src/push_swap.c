/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:33:39 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/12 15:48:48 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_stack *a)
{
	int	s_max;
	int	s_min;
	int	sorted;

	s_max = stack_max(a);
	s_min = stack_min(a);
	sorted = 0;
	while (!sorted)
	{
		if (a->head->val != s_min && a->head->val != s_max)
			sa(a);
		if (a->head->val == s_max)
			ra(a);
		if (a->head->next->next->val == s_min)
			rra(a);
		s_max = stack_max(a);
		s_min = stack_min(a);
		sorted = (a->head->val == s_min && a->head->next->next->val == s_max);
	}
}

int			find_next(t_stack *a, t_stack *b)
{
	int	n_cost;
	int	l_cost;
	int	n;
	int	i;

	n = 0;
	i = 0;
	l_cost = INT_MAX;
	while (i < a->size)
	{
		n_cost = cost(i, a, b);
		if (n_cost < l_cost)
		{
			l_cost = n_cost;
			n = i;
		}
		i++;
	}
	return (n);
}

static void		rot(int i, t_stack *a, t_stack *b)
{
	int	a_val;
	int	a_rot;
	int	b_rot;
	int	r_overlap;

	a_val = stack_at(i, a);
	a_rot = st_rotations(a_val, a);
	if (a_val > stack_max(b))
		b_rot = st_rotations(stack_max(b), b);
	else if (a_val < stack_min(b))
		b_rot = st_rotations(stack_min(b), b);
	else
		b_rot = st_rotations(st_closest(a_val, b), b);
	r_overlap = rot_overlap(a_rot, b_rot);
	while (r_overlap > 0)
	{
		if (a_rot < 0)
			rrr(a, b);
		else
			rr(a, b);
		r_overlap--;
		//TODO: Check this if it's right
		a_rot -= ft_sign(a_rot);
		b_rot -= ft_sign(b_rot);
	}
	while (a_rot != 0)
	{
		//TODO: Check this if it's right
		ra(a);
		a_rot -= ft_sign(a_rot);
	}
	while (b_rot != 0)
	{
		//TODO: Check this if it's right
		rb(b);
		b_rot -= ft_sign(b_rot);
	}
}

t_stack		*sort(t_stack *a)
{
	t_stack	*b;
	int		next;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	/*
	pb(a, b);
	pb(a, b);
	next = find_next(a, b);
	rot(next, a, b);
	pb(a, b);
	pb(a, b);
	next = find_next(a, b);
	rot(next, a, b);
	pb(a, b);
	next = find_next(a, b);
	rot(next, a, b);
	*/
	pb(a, b);
	pb(a, b);
	next = find_next(a, b);
	rot(next, a, b);

	//sort_a(a);
	ft_printf("next to move is at index %i\n", next);
	debug_stacks(a, b);
	free_stack(b);
	return (a);
}
