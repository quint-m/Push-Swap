/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:46:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/17 18:05:31 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stddef.h>

typedef struct	t_stack_item
{
	long				content;
	struct t_stack_item	*next;
}				t_stack_item;

typedef struct	t_stacks
{
	struct t_stack_item	*a_head;
	struct t_stack_item	*b_head;
}				t_stacks;



void			ft_rotate(t_stacks *stacks, char c);
void			push(t_stacks *stacks, char c);
t_stack_item	*create_a_stack(char **argv);
t_stack_item	*ft_newnode(long val);

#endif
