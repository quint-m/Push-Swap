/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:48:09 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/08 16:18:40 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	exit_on_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int		check_number_count(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i++]);
	return (i);
}

int	validate_input(int argc, char **argv)
{
	char	**numbers;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (check_number_count(numbers))
			return (0);
	}
	return (1);
}
