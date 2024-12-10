/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:40:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/10 17:50:34 by qmennen          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**arguments;
	t_stack	*stack;
	if (argc < 2)
		return (1);
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else if (argc > 2)
		arguments = ++argv;
	stack = process_input(arguments);
	print_stack(stack);
	return (0);
}
