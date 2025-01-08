/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:32:33 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 12:50:47 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_item	*create_a_stack(char **argv)
{
	int				i;
	t_stack_item	*a_stack;
	t_stack_item	*tmp;

	i = 0;
	a_stack = ft_newnode(ft_atoi(argv[i++]));
	tmp = a_stack;
	while (argv[i])
	{
		tmp->next = ft_newnode(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
		i++;
	}
	return (a_stack);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 2)
		stacks.a_head = create_a_stack(ft_split(argv[1], ' '));
	else
		stacks.a_head = create_a_stack(++argv);
	stacks.b_head = NULL;
	sorting(&stacks);
	return (0);
}
