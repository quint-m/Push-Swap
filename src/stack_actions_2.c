/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:09 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 16:14:53 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_stack *b)
{
	write(1, "sa\n", 3);
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	write(1, "rrr\n", 4);
	r_rotate(a);
	r_rotate(b);
}

void	rra(t_stack *a)
{
	write(1, "rrr\n", 4);
	r_rotate(a);
}
