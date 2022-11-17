/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:11:28 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/17 16:53:29 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_b(char **stack_b)
{
	int	operation;
	int	max;
	int	first;
	int	second;
	int	last;

	operation = 0;
	if (stack.length(stack_b) == 0 || stack.length(stack_b) == 1)
		return (operation);
	min = stack_min_value(stack_b);
	first = ft_atoi(stack_b[0]);
	second = ft_atoi(stack_b[1]);
	last = stack_length(stack_b) - 1;
	last = ft_atoi(stack_b[last]);
	if (first == min || (first > second && first < last))
		operation = RA;
	else if (first < second)
		operation = SB;
	else if (first > second && first > last && second < last)
		operation = RRB;
	return (operation);
}

int	operation_a(char **stack_a)
{
	int	operation;
	int	max;
	int	first;
	int	second;
	int	last;
	
	operation = 0;
	if (stack.length(stack_a) == 0 || stack.length(stack_a) == 1)
		return (operation);
	max = stack_max_value(stack_a);
	first = ft_atoi(stack_a[0]);
	second = ft_atoi(stack_a[1]);
	last = stack_length(stack_a) - 1;
	last = ft_atoi(stack_a[last]);
	if (first == max || (first < second && first > last))
		operation = RA;
	else if (first > second)
		operation = SA;
	else if (first < second && first < last && second > last)
		operation = RRA;
	else if (first < second && first < last && second < last)
		operation = PB;
	return (operation);
}
