/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:40:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/10 18:10:03 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*process_input(char **input)
{
	t_stack *result;

	result = ft_calloc(1, sizeof(t_stack));
	if (!result)
		return (NULL);
	while (*input)
		push(result, ft_atoi(*(input++)));
	return (result);
}

static void	print_stack(t_stack *stack)
{
	t_data	*current;

	current = stack->head;
	while(current->next)
	{
		ft_printf("%i\n", current->val);
		current = current->next;
	}
	ft_printf("%i\n", current->val);
}

static t_stack	*sort(t_stack *a)
{
	t_stack	*b;
	int		tmp_a;
	int		tmp_b;
	int		operations;
	t_data	*current;

	operations = 0;
	b = ft_calloc(1, sizeof(*a));
	if (!b)
		return (NULL);
	while (a->size > 0)
	{
		tmp_a = a->head->val;
		pop(a);
		operations++;
		while (b->size > 0 && b->head->val < tmp_a)
		{
			operations++;
			pa(a, b);
		}
		operations++;
		push(b, tmp_a);
	}
	ft_printf("operations: %i\n", operations);
	return (b);
}

static int	ft_max(t_stack *stack)
{
	int		max;
	t_data	*current;

	current = stack->head;
	max = current->val;
	while(current)
	{
		if (max < current->val)
			max = current->val;
		current = current->next;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack *sorted;
	if (argc < 2)
		return (1);
	if (argc == 2)
		stack = process_input(ft_split(argv[1], ' '));
	else if (argc > 2)
		stack = process_input(++argv);

	sorted = sort(stack);
	print_stack(sorted);
	return (0);
}
