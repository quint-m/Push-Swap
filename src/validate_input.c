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

void	exit_on_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	check_number_count(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	return (i);
}

static int	check_numbers(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if (!ft_isdigit(numbers[i][j]) && j > 0)
				return (1);
			if (ft_isalpha(numbers[i][j]))
				return (1);
			j++;
		}
		if (ft_atoi(numbers[i]) < 0 && !ft_strchr(numbers[i], '-'))
			return (1);
		else if (ft_atoi(numbers[i]) > 0 && ft_strchr(numbers[i], '-'))
			return (1);
		i++;
	}
	return (0);
}

static int	check_doubles(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(char **input)
{
	if (check_number_count(input) < 2)
		return (0);
	if (check_numbers(input))
		return (0);
	if (check_doubles(input))
		return (0);
	return (1);
}
