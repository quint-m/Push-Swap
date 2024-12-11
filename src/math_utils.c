/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:06:54 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 11:40:45 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_sign(int a)
{
	if (a == 0)
		return (0);
	return (a / ft_abs(a));
}

int	ft_stackmax(t_stack *stack)
{
	int		max;
	t_data	*current;

	current = stack->head;
	max = current->val;
	while (current)
	{
		if (max < current->val)
			max = current->val;
		current = current->next;
	}
	return (max);
}
