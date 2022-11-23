/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_attributes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:43:33 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/23 15:38:42 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted_ascend(char **stack)
{
	int	i;

	i = 0;
	while (stack[i + 1] && stack[i + 1][0] != 'x')
	{
		if (ft_atoi(stack[i]) > ft_atoi(stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	stack_sorted_descend(char **stack)
{
	int	i;

	i = 0;
	while (stack[i + 1] && stack[i + 1][0] != 'x')
	{
		if (ft_atoi(stack[i]) < ft_atoi(stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	stack_length(char **stack)
{
	int	i;

	i = 0;
	while (stack[i] && stack[i][0] != 'x')
		i++;
	return (i);
}

int	stack_max_value(char **stack)
{
	int	i;
	int	max;

	i = 0;
	max = ft_atoi(stack[0]);
	while (stack[i] && stack[i][0] != 'x')
	{
		if (ft_atoi(stack[i]) > max)
			max = ft_atoi(stack[i]);
		i++;
	}
	return (max);
}

int	stack_min_value(char **stack)
{
	int	i;
	int	min;

	i = 0;
	min = ft_atoi(stack[0]);
	while (stack[i] && stack[i][0] != 'x')
	{
		if (ft_atoi(stack[i]) < min)
			min = ft_atoi(stack[i]);
		i++;
	}
	return (min);
}
