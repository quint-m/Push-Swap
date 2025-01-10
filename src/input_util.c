/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:32:33 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 16:42:49 by qmennen          ###   ########.fr       */
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

char	**split_input(int count, char **argv)
{
	char			**input;
	int				i;

	i = 1;
	if(count == 2)
	{
		input = ft_split(argv[1], ' ');
		return (input);
	}
	input = ft_calloc(count, sizeof(char *));
	while (argv[i])
	{
		input[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	return (input);
}

void	free_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		free(input[i++]);
	free(input);
}