/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:39:53 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/07 19:33:10 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_top_of_a(t_stacks *stacks, t_stack_item *a_head, int i)
{
	int	size;

	size = ft_listsize(stacks->a_head);
	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
}
