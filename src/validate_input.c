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
	while (numbers[i])
	{
		i++;
	}
	return (i);
}

int		check_alpha_chars(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
			if (ft_isalpha(numbers[i][j++]))
				return (1);
		i++;
	}
	return (0);
}

int		check_doubles(char **numbers)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (numbers[i])
	{
		n = ft_atoi(numbers[i]);
		j = 0;
		while (i > 0 && numbers[i + j])
		{
			if (n == ft_atoi(numbers[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(int argc, char **argv)
{
	char	**numbers;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (check_number_count(numbers) < 2)
			return (0);
		if (check_alpha_chars(numbers))
			return (0);
		if (check_doubles(numbers))
			return (0);
	}
	return (1);
}
