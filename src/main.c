/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:07:24 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/05 16:08:48 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack *stack;
	t_list	*idx;

	stack = ft_calloc(1, sizeof(t_stack));
	push(stack, 12);
	push(stack, 14);
	push(stack, 15);
	ft_printf("Stack head: %i\n", stack->head->val);
	pop(stack);
	pop(stack);
	ft_printf("Stack head: %i\n", stack->head->val);
	free(stack);
	return (0);
}
