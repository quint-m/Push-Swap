/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:40:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 18:17:01 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack *t)
{
	int		i;
	t_data	*current;

	current = t->head;
	while (current)
	{
		ft_printf("%i", current->val);
		current = current->next;
		ft_printf("\n");
	}
}
/*
 * Sort the last three in A.
 * Bit sticky, it has to be hardcoded
 */
static void	sort_three(t_stack *t)
{
	int	min;
	int	max;

	min = ft_stackmin(t);
	max = ft_stackmax(t);
	if (t->head->next->next->val == max && t->head->val == min)
		return ;
	if (t->head->next->next->val == min)
		rra(t);
	if (t->head->val == max)
		ra(t);
	if (t->head->next->next->val == max && t->head->val != min)
		sa(t);
	if (t->head->val == min && t->head->next->next->val != max)
	{
		sa(t);
		ra(t);
	}
}

void	sort(t_stack *a)
{
	t_stack	*b;
	int		next;
	int		rotate;

	if (!a)
		return ;
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	b = ft_calloc(1, sizeof(*a));
	if (!b)
		return ;
	pb(a, b);
	pb(a, b);
	
	while (a->size > 3)
	{
		next = cheapest_index(a, b);
		move(a, b, next);
	}
	push_back(a, b);
	rotate = calculate_rotations(ft_stackmin(a), a);
	while (rotate > 0)
	{
		ra(a);
		rotate--;
	}
	while (rotate < 0)
	{
		rra(a);
		rotate++;
	}
	ft_stackfree(b);
}
