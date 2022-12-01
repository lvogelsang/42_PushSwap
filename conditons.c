/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:57:58 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/01 15:09:48 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_short(char **stack_a, char **stack_b)
{
	int	x;
	int	y;

	x = operation_a(stack_a, 0);
	y = operation_b(stack_b);
	if (x == 4)
	{
		push_b(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else if (x == y)
		push_swap_a_b(stack_a, stack_b, x);
	else
	{
		push_swap_a(stack_a, x);
		push_swap_b(stack_b, y);
	}
}

int	operation_b(char **stack_b)
{
	int	operation;
	int	min;
	int	first;
	int	second;
	int	last;

	operation = 0;
	if (stack_length(stack_b) == 0 || stack_length(stack_b) == 1)
		return (operation);
	min = stack_min_value(stack_b);
	first = ft_atoi(stack_b[0]);
	second = ft_atoi(stack_b[1]);
	last = stack_length(stack_b) - 1;
	last = ft_atoi(stack_b[last]);
	if ((first == min && second == stack_max_value(stack_b)) \
			|| (first > second && last == min && stack_length(stack_b) > 2) || (first > second && first < last))
		operation = RB;
	else if (first < second)
		operation = SB;
	else if (first > second && first > last && second < last)
		operation = RRB;
	else if (first > second && first > last && second > last)
		operation = RB;
	return (operation);
}

int	operation_a(char **stack_a, int op)
{
	int	operation;
	int	max;
	int	first;
	int	second;
	int	last;

	operation = 0;
	if (stack_length(stack_a) == 0 || stack_length(stack_a) == 1)
		return (operation);
	max = stack_max_value(stack_a);
	first = ft_atoi(stack_a[0]);
	second = ft_atoi(stack_a[1]);
	last = stack_length(stack_a) - 1;
	last = ft_atoi(stack_a[last]);
	if (first == max \
			|| (first < second && first > last) \
			|| (first < second && first < last && second < last && op == 1))
		operation = RA;
	else if (first > second)
		operation = SA;
	else if (first < second && first < last && second > last)
		operation = RRA;
	else if (first < second && first < last && second < last && op == 0)
		operation = PB;
	return (operation);
}
