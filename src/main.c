/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:51:49 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/12 12:52:11 by qmennen          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (1);
	if (argc == 2)
		stack = process_input(ft_split(argv[1], ' '));
	else if (argc > 2)
		stack = process_input(++argv);
	stack = sort(stack);
	free_stack(stack);
	return (0);
}
