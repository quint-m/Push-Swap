/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:43:58 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 12:55:08 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stacks *stacks)
{
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_cheapest(stacks);
	sort_three(stacks);
	move_back(stacks);
}
