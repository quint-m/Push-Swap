/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:46:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/12 15:41:01 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stddef.h>

typedef struct s_data
{
	long			val;
	struct s_data	*next;
}				t_data;

typedef struct s_stack
{
	t_data	*head;
	size_t	size;
}				t_stack;

t_stack	*sort(t_stack *a);
void	push(t_stack *stack, long val);
void	pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);
/*
 *	Stack utils
 */
void	rrr(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	rb(t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
int		stack_max(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_at(int i, t_stack *stack);
int		st_indexof(int n, t_stack *stack);
void	free_stack(t_stack *stack);
/*
 * Calculations
 */
int	st_rotations(int n, t_stack *stack);
int	rot_overlap(int a_rot, int b_rot);
int	st_closest(int n, t_stack *stack);
int	cost(int a_idx, t_stack *a, t_stack *b);
/*
 *	Math utils
 */
int		ft_abs(int a);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_sign(int a);
/*
 * Utils
 */
void	debug_stacks(t_stack *a, t_stack *b);
#endif
