/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:03:28 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 12:10:24 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b->head->val);
	pop(b);
}

void	pb(t_stack *a, t_stack *b)
{
	write(1, "pb\n", 3);
	push(b, a->head->val);
	pop(a);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	r_rotate(a);
	r_rotate(b);
}
