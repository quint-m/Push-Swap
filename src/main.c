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

void	print_stack(t_stack *stack)
{
	t_data	*last;
	int		i;

	last = stack->head;
	i = 0;
	while (last)
	{
		ft_printf("Stack at %i = %i\n", i, last->val);
		i++;
		last = last->next;
	}
}

int	main(void)
{
	t_stack *stack;
	t_list	*idx;

	stack = ft_calloc(1, sizeof(t_stack));
	push(stack, 12);
	push(stack, 14);
	push(stack, 16);
	push(stack, 18);
	print_stack(stack);
	r_rotate(stack);
	ft_printf("\n\n");
	print_stack(stack);
	free(stack);
	return (0);
}
