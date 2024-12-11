/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:51:49 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/11 18:13:03 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	print_stack(t_stack *t)
{
	int		i;
	t_data	*current;

	current = t->head;
	while (current)
	{
		ft_printf("%i", current->val);
		current = current->next;
		ft_printf("\n");
	}
	ft_printf("===\na b\n");
}
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
	//print_stack(stack);
	ft_stackfree(stack);
	return (0);
}
