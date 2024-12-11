/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:03:28 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 17:55:45 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pa(t_stack *a, t_stack *b)
{
	write(1, "pa\n", 3);
	push(a, b->head->val);
	pop(b);
}

void	pb(t_stack *a, t_stack *b)
{
	write(1, "pb\n", 3);
	push(b, a->head->val);
	pop(a);
}

void	ra(t_stack *a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_stack *b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
