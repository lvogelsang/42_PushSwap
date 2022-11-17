/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_attributes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:43:33 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/17 15:57:39 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted_ascend(char **stack)
{
	int	i;

	i = 0;
	while (stack[i + 1] && stack[i][0] != 'x')
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
	while (stack[i + 1] && stack[i][0] != 'x')
	{
		if (ft_atoi(stack[i]) < ft_atoi(stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	stack_empty(char **stack)
{
	if (stack[0][0] == 'x')
		return (1);
	return (0);
}
