/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:40:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 17:48:43 by qmennen          ###   ########.fr       */
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

static void	sort_three(t_stack *t)
{
	int	min;
	int	max;

	min = ft_stackmin(t);
	max = ft_stackmax(t);
	if (t->head->next->next->val == max && t->head->val == min)
		return;
	if (t->head->next->next->val == min)
		rra(t);
	if (t->head->val == max)
		ra(t);
	if (t->head->next->next->val == max && t->head->val != min)
		sa(t);
	if (t->head->val == min && t->head->next->next->val != max)
	{
		sa(t);
		ra(t);
	}
}

static void	sort(t_stack *a)
{
	t_stack	*b;
	int		next;

	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	b = ft_calloc(1, sizeof(*a));
	if (!b)
		return ;
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
	{
		next = cheapest_index(a, b);
		move(a, b, next);
	}
	sort_three(a);
	push_back(a, b);
	print_stacks(a, b);
	ft_stackfree(b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (1);
	if (argc == 2)
		stack = process_input(ft_split(argv[1], ' '));
	else if (argc > 2)
		stack = process_input(++argv);
	sort(stack);
	ft_stackfree(stack);
	return (0);
}
