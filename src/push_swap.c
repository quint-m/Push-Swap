/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:32:33 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 16:42:49 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**input;

	if (argc < 2)
		return (1);
	input = split_input(argc, argv);
	if (!validate_input(input))
	{
		free_input(input);
		exit_on_error();
	}
	stacks.a_head = create_a_stack(input);
	stacks.b_head = NULL;
	stacks.values = NULL;
	stacks.moves = NULL;
	stacks.cheap = NULL;
	sorting(&stacks);
	ft_freeall(&stacks);
	free_input(input);
	return (0);
}

