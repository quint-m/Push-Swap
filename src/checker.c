/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:06 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/09 16:03:25 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stacks *stacks)
{
	t_moves		*moves;
	t_moves		*cheap;
	t_values	*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheap = ft_calloc(1, sizeof(t_moves));
	stacks->cheap = cheap;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
}

static void	new_move(t_stacks *stacks, const char *move)
{
	size_t	len;

	len = ft_strlen(move) - 1;
	if (ft_strncmp(move, "ra", len) == 0)
		ft_rotate(stacks, 'a');
	else if (ft_strncmp(move, "rb", len) == 0)
		ft_rotate(stacks, 'b');
	else if (ft_strncmp(move, "rra", len) == 0)
		ft_rev_rotate(stacks, 'a');
	else if (ft_strncmp(move, "rrb", len) == 0)
		ft_rev_rotate(stacks, 'b');
	else if (ft_strncmp(move, "rr", len) == 0)
		ft_rotate(stacks, ' ');
	else if (ft_strncmp(move, "rrr", len) == 0)
		ft_rev_rotate(stacks, ' ');
	else if (ft_strncmp(move, "pb", len) == 0)
		ft_push(stacks, 'b');
	else if (ft_strncmp(move, "pa", len) == 0)
		ft_push(stacks, 'a');
	else if (ft_strncmp(move, "sa", len) == 0)
		ft_swap(stacks, 'a');
	else if (ft_strncmp(move, "sb", len) == 0)
		ft_swap(stacks, 'b');
	else if (ft_strncmp(move, "ss", len) == 0)
		ft_swap(stacks, ' ');
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**input;
	char		*move;

	input = split_input(argc, argv);
	if (!validate_input(input))
	{
		free_input(input);
		exit_on_error();
	}
	stacks.a_head = create_a_stack(input);
	stacks.b_head = NULL;
	init_stacks(&stacks);
	move = get_next_line(0);
	while (move != NULL)
	{
		new_move(&stacks, move);
		free(move);
		move = get_next_line(0);
	}
	if (check_order(&stacks) && stacks.b_head == NULL)
		ft_printf("OK\n");
	ft_freeall(&stacks);
	free_input(input);
	return (0);
}
