/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:35:55 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/07 19:53:05 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_back(t_stacks *stacks)
{
	while (stacks->b_head != NULL)
	{
		min_max(stacks, 'a');
		if (stacks->b_head->content < stacks->values->a_min)
			new_min_a(stacks);
		else if (stacks->b_head->content > stacks->values->a_max)
			new_max_a(stacks);
		else
		{

		}
	}
	min_max(stacks, 'a');
}
