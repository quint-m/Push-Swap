/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:40:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 15:09:18 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*process_input(char **input)
{
	t_stack	*result;

	result = ft_calloc(1, sizeof(t_stack));
	if (!result)
		return (NULL);
	while (*input)
		push(result, ft_atoi(*(input++)));
	return (result);
}

static void	print_stacks(t_stack *a, t_stack *b)
{
	int		diff;
	int		i;
	t_data	*current;
	t_data	*b_current;

	diff = a->size - b->size;
	i = 0;
	current = a->head;
	b_current = b->head;
	while (diff < 0)
	{
		ft_printf("  ");
		ft_printf("%i", b_current->val);
		ft_printf("\n");
		b_current = b_current->next;
		diff++;
	}
	while (diff > 0)
	{
		ft_printf("%i", current->val);
		ft_printf(" ");
		ft_printf("\n");
		current = current->next;
		diff--;
	}
	if (diff == 0)
	{
		while (current)
		{
			ft_printf("%i", current->val);
			ft_printf(" ");
			ft_printf("%i", b_current->val);
			current = current->next;
			b_current = b_current->next;
			ft_printf("\n");
		}
	}
	ft_printf("===\na b\n");
}

static t_stack	*sort(t_stack *a)
{
	t_stack	*b;
	int		next;

	b = ft_calloc(1, sizeof(*a));
	if (!b)
		return (NULL);
	//pb(a, b);
	//pb(a, b);
	//print_stacks(a, b);
	pop(a);
	pop(a);
	pop(a);
	pop(a);
	pop(a);
	push(b, 7);
	push(b, 1);
	push(b, 2);
	push(b, 5);
	push(b, 6);
	print_stacks(a, b);
	next = cheapest_index(a, b);
	ft_printf("\nnext to move at index: %i\n\n", next);
	/*
	while (a->size > 3)
	{
		next = cheapest_index(a, b);
		ft_printf("\nnext to move at index: %i\n\n", next);
		move(a, b, next);
		print_stacks(a, b);
	}
	print_stacks(a, b);
	*/
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*sorted;

	if (argc < 2)
		return (1);
	if (argc == 2)
		stack = process_input(ft_split(argv[1], ' '));
	else if (argc > 2)
		stack = process_input(++argv);
	sorted = sort(stack);
	return (0);
}
