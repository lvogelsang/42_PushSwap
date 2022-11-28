/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:57:58 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/28 15:42:44 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(char **stack_b);
void	test_2(char **stack_b);

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
	/*
	if (first == min || (first > second && first < last && last < med))
		operation = RB;
	else if (first > second && first < last && last >= med)
		operation = RRB;*/
	if ((first == min && second == stack_max_value(stack_b)) || (first > second && last == min) ||(first > second && first < last))
		operation = RB;
	else if (first < second)
		operation = SB;
	else if (first > second && first > last && second < last)
//		operation = RRB;
		test_2(stack_b);
	else if (first > second && first > last && second > last)
//		operation = PA;
//		operation = RB;
		test(stack_b);
	return (operation);
}

void	test_2(char **stack_b)
{
	push_swap_b(stack_b, RRB);
	push_swap_b(stack_b, SB);
}
// This is a test:
void	test(char **stack_b)
{
	push_swap_b(stack_b, RRB);
	push_swap_b(stack_b, SB);
	push_swap_b(stack_b, RB);
	push_swap_b(stack_b, SB);
}
// modify this as well??????? one for bucket sorting / one for the normal one?

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
	if (first == max || (first < second && first > last))
		operation = RA;
	else if (first > second)
		operation = SA;
	else if (first < second && first < last && second > last)
		operation = RRA;
	else if (first < second && first < last && second < last)
	{
		if (op == 0)
			operation = PB;
		else if (op == 1)
			operation = RA;
	}
	return (operation);
}
