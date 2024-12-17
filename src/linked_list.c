/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:50:02 by qmennen           #+#    #+#             */
/*   Updated: 2024/12/17 17:52:33 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_item	*ft_newnode(long val)
{
	t_stack_item	*res;

	res = malloc(sizeof(t_stack_item));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->content = val;
	return (res);
}
