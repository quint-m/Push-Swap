/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:58:37 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 17:59:59 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_stackat(int t_i, t_stack *stack)
{
	t_data	*result;
	int		i;

	result = stack->head;
	i = 0;
	while (i < t_i && result->next)
	{
		result = result->next;
		i++;
	}
	return (result);
}
