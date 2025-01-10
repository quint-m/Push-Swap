/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:46:11 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 16:11:36 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stddef.h>
# include <stdlib.h>

typedef struct t_stack_item
{
	int					content;
	struct t_stack_item	*next;
}	t_stack_item;

typedef struct t_stacks
{
	struct t_stack_item	*a_head;
	struct t_stack_item	*b_head;
	struct t_values		*values;
	struct t_moves		*moves;
	struct t_moves		*cheap;
}	t_stacks;

typedef struct t_values
{
	int	a_min;
	int	a_max;
	int	b_min;
	int	b_max;
}	t_values;

typedef struct t_moves
{
	int	cost;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
}				t_moves;
/*
 * Stack operations
 */
void			ft_rotate(t_stacks *stacks, char c);
void			ft_rev_rotate(t_stacks *stacks, char c);
void			ft_swap(t_stacks *stacks, char c);
void			ft_push(t_stacks *stacks, char c);
/*
 * Algorithm functions
 */
void			check_moves(t_stacks *stacks);
void			new_max_min_b(t_stacks *stacks);
void			new_num_b(t_stacks *stacks, long num);
void			get_top_of_a(t_stacks *stacks, t_stack_item *a_head, int i);
void			sorting(t_stacks *stacks);
void			move_cheapest(t_stacks *stacks);
void			solve_doubles(t_stacks *stacks);
void			calculate_cost(t_stacks *stacks, int i);
void			do_cheap_moves(t_stacks *stacks);
void			sort_four(t_stacks *stacks);
void			sort_three(t_stacks *stacks, int flag);
void			sort_two(t_stacks *stacks);
void			move_back(t_stacks *stacks);
void			new_max_a(t_stacks *stacks);
void			new_min_a(t_stacks *stacks);
void			new_element_a(t_stacks *stacks, t_stack_item *b_head);
int				validate_input(char **input);
/*
 * Stack helper
 */
t_stack_item	*create_a_stack(char **argv);
t_stack_item	*ft_newnode(long val);
int				ft_listsize(t_stack_item *list);
t_stack_item	*ft_listlast(t_stack_item *list);
void			ft_print_list(t_stacks *stacks, char c);
void			min_max(t_stacks *stacks, char c);
int				find_index_b(t_stacks *stacks, int num);
int				find_index_a(t_stacks *stacks, int num);
long			search_num_b(t_stacks *stacks, int num);
long			search_num_a(t_stacks *stacks, int num);
void			ft_freeall(t_stacks *stacks);
/*
 * Helper
 */
void			exit_on_error(void);
char			**split_input(int count, char **argv);
void			free_input(char **input);
int				check_order(t_stacks *stacks);
#endif
