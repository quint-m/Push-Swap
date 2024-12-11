/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:40:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 11:54:26 by qmennen          ###   ########.fr       */
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
	while (current)
	{
		ft_printf("%i ", current->val);
		if (i < diff)
		{
			ft_printf(" ");
			i++;
		}
		else
		{
			ft_printf("%i", b_current->val);
			b_current = b_current->next;
		}
		ft_printf("\n");
		current = current->next;
	}
	ft_printf("===\na b\n");
}

static int	calculate_rotations(int num, t_stack *stack)
{
	t_data	*current;
	int		pos_top;

	current = stack->head;
	pos_top = 0;
	while (current)
	{
		if (current->val == num)
			break ;
		pos_top++;
		current = current->next;
	}
	if (pos_top <= stack->size / 2)
		return (pos_top);
	else
		return (-(stack->size - pos_top));
}

static int	calculate_cost(int a_index, t_stack *a, t_stack *b)
{
	t_data	*a_data;
	int		rotations_b;
	int		rotations_a;
	int		overlap;
	int		i;

	a_data = a->head;
	i = 0;
	while (i < a_index && a_data->next)
	{
		a_data = a_data->next;
		i++;
	}
	rotations_b = calculate_rotations(ft_stackmax(b), b);
	rotations_a = calculate_rotations(a_data->val, a);
	overlap = 0;
	if ((rotations_a > 0 && rotations_b > 0)
		|| (rotations_a < 0 && rotations_b < 0))
	{
		overlap = ft_min(ft_abs(rotations_a), ft_abs(rotations_b));
		rotations_a -= overlap;
		rotations_b -= overlap;
	}

	return (overlap + ft_max(ft_abs(rotations_a), ft_abs(rotations_b)) + 1);
}

static int		cheapest_index(t_stack *a, t_stack *b)
{
	t_data	*current;
	int		l_cost;
	int		cost;
	int		i;
	int		cheapest;

	i = 0;
	cheapest = 0;
	l_cost = 999;
	current = a->head;
	ft_printf("finding cheapest for stack\n");
	while (current)
	{
		cost = calculate_cost(i, a, b);
		if (cost < l_cost)
		{
			l_cost = cost;
			cheapest = i;
		}
		current = current->next;
		i++;
	}
	return (cheapest);
}

static t_stack	*sort(t_stack *a)
{
	t_stack	*b;
	int		next;

	b = ft_calloc(1, sizeof(*a));
	if (!b)
		return (NULL);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	print_stacks(a, b);

	next = cheapest_index(a, b);

	ft_printf("next to move : %i\n", next);
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
