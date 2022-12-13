/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:27:50 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/13 15:17:52 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errors(char **stack_a, int len)
{
	if (error_non_integer(stack_a, len) == 1)
		return (1);
	if (error_min_max_integer(stack_a, len) == 1)
		return (1);
	if (error_duplicate(stack_a, len) == 1)
		return (1);
	return (0);
}

int	error_non_integer(char **stack_a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (stack_a[i][j] == '-')
			j++;
		while (stack_a[i][j])
		{
			if (ft_isdigit(stack_a[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// This needs to be fixed:

int	error_min_max_integer(char **stack_a, int len)
{
	int	i;
	int	num;

	i = 0;
	while (i < len)
	{
		num = ft_atoi(stack_a[i]);
		if (ft_itoa(num)[0] != stack_a[i][0])
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicate(char **stack_a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(stack_a[i]) == ft_atoi(stack_a[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
