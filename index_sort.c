/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:30:12 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/16 14:18:32 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_sort(char **stack_a, char **stack_b, int bucket_size)
{
	int	i;
	int	index_b;
	int	index_a;

	i = 0;
	while (i < bucket_size)
	{
		index_b = get_best_index(stack_a, stack_b, bucket_size);
		index_a = get_target_position_stack_a(stack_a, \
		ft_atoi(stack_b[index_b]));
		index_sort_exec(stack_a, stack_b, index_a, index_b);
		i++;
	}
}

void	index_sort_exec(char **stack_a, char **stack_b, int index_a, \
int index_b)
{
	int	a;
	int	b;
	int	sort_technique;

	sort_technique = get_sort_technique(index_a, index_b, \
	stack_length(stack_a), stack_length(stack_b));
	a = ft_atoi(stack_a[index_a]);
	b = ft_atoi(stack_b[index_b]);
	if (sort_technique == ROTATE)
		rotate_a_b(stack_a, stack_b, a, b);
	else if (sort_technique == REVERSE_ROTATE)
		reverse_rotate_a_b(stack_a, stack_b, a, b);
	else if (sort_technique == A_ROTATE_B_REVERSE)
		rotate_a_reverse_b(stack_a, stack_b, a, b);
	else if (sort_technique == A_REVERSE_B_ROTATE)
		reverse_a_rotate_b(stack_a, stack_b, a, b);
	push_a(stack_b, stack_a);
	ft_printf("pa\n");
}

int	get_best_index(char **stack_a, char **stack_b, int bucket_size)
{
	int	index_b;
	int	index_best;

	index_b = 0;
	index_best = 0;
	while (index_b < bucket_size && index_b < stack_length(stack_b))
	{
		index_best = get_best_index_two(stack_a, stack_b, index_best, index_b);
		index_b++;
	}
	index_b = stack_length(stack_b) - 1;
	while (index_b > stack_length(stack_b) - bucket_size - 1 \
		&& index_b >= bucket_size)
	{
		index_best = get_best_index_two(stack_a, stack_b, index_best, index_b);
		index_b--;
	}
	return (index_best);
}

int	get_best_index_two(char **stack_a, char **stack_b, int index_best, \
int index_b)
{
	int			costs;
	int			index_a;
	static int	min_costs;

	index_a = get_target_position_stack_a(stack_a, ft_atoi(stack_b[index_b]));
	costs = get_total_costs(index_a, index_b, stack_length(stack_a), \
	stack_length(stack_b));
	if (index_b == 0)
		min_costs = costs;
	if (costs < min_costs)
	{
		min_costs = costs;
		return (index_b);
	}
	return (index_best);
}

int	get_target_position_stack_a(char **stack_a, int b)
{
	int	index_a;

	index_a = 0;
	if (b < stack_min_value(stack_a))
	{
		while (ft_atoi(stack_a[index_a]) != stack_max_value(stack_a))
			index_a++;
	}
	else if (b > ft_atoi(stack_a[stack_length(stack_a) - 1]) \
		&& b < ft_atoi(stack_a[0]))
		index_a = stack_length(stack_a) - 1;
	else
		index_a = get_target_position_stack_a_two(stack_a, b, index_a);
	return (index_a);
}

int	get_target_position_stack_a_two(char **stack_a, int b, int index_a)
{
	while (index_a + 1 < stack_length(stack_a))
	{
		if (b > ft_atoi(stack_a[index_a]) && b < ft_atoi(stack_a[index_a + 1]))
			break ;
		if (b > ft_atoi(stack_a[stack_length(stack_a) - 2 - index_a]) \
			&& b < ft_atoi(stack_a[stack_length(stack_a) - 1 - index_a]))
		{
			index_a = stack_length(stack_a) - 2 - index_a;
			break ;
		}
		index_a++;
	}
	return (index_a);
}

int	get_total_costs(int index_a, int index_b, int len_a, int len_b)
{
	int	costs_stack_a_rotate;
	int	costs_stack_a_reverse;
	int	costs_stack_b_rotate;
	int	costs_stack_b_reverse;
	int	costs_total;

	costs_stack_a_rotate = index_a + 1;
	costs_stack_a_reverse = len_a - index_a - 1;
	costs_stack_b_rotate = index_b;
	costs_stack_b_reverse = len_b - index_b;
	costs_total = get_total_costs_two(costs_stack_a_rotate, \
	costs_stack_a_reverse, costs_stack_b_rotate, costs_stack_b_reverse);
	return (costs_total);
}

int	get_total_costs_two(int costs_stack_a_rotate, int costs_stack_a_reverse, \
	int costs_stack_b_rotate, int costs_stack_b_reverse)
{
	int	costs_rotate;
	int	costs_reverse;
	int	costs_a_rotate_b_reverse;
	int	costs_a_reverse_b_rotate;

	if (costs_stack_a_rotate > costs_stack_b_rotate)
		costs_rotate = costs_stack_a_rotate;
	else
		costs_rotate = costs_stack_b_rotate;
	if (costs_stack_a_reverse > costs_stack_b_reverse)
		costs_reverse = costs_stack_a_reverse;
	else
		costs_reverse = costs_stack_b_reverse;
	costs_a_rotate_b_reverse = costs_stack_a_rotate + costs_stack_b_reverse;
	costs_a_reverse_b_rotate = costs_stack_a_reverse + costs_stack_b_rotate;
	if (costs_rotate <= costs_reverse && costs_rotate <= \
		costs_a_rotate_b_reverse && costs_rotate <= costs_a_reverse_b_rotate)
		return (costs_rotate);
	else if (costs_reverse <= costs_a_rotate_b_reverse \
		&& costs_reverse <= costs_a_reverse_b_rotate)
		return (costs_reverse);
	else if (costs_a_rotate_b_reverse <= costs_a_reverse_b_rotate)
		return (costs_a_rotate_b_reverse);
	else
		return (costs_a_reverse_b_rotate);
}

int	get_sort_technique(int index_a, int index_b, int len_a, int len_b)
{
	int	costs_stack_a_rotate;
	int	costs_stack_a_reverse;
	int	costs_stack_b_rotate;
	int	costs_stack_b_reverse;
	int	sort_technique;

	costs_stack_a_rotate = index_a + 1;
	costs_stack_a_reverse = len_a - index_a - 1;
	costs_stack_b_rotate = index_b;
	costs_stack_b_reverse = len_b - index_b;
	sort_technique = get_sort_technique_two(costs_stack_a_rotate, \
	costs_stack_a_reverse, costs_stack_b_rotate, costs_stack_b_reverse);
	return (sort_technique);
}

int	get_sort_technique_two(int costs_stack_a_rotate, int costs_stack_a_reverse, \
	int costs_stack_b_rotate, int costs_stack_b_reverse)
{
	int	costs_rotate;
	int	costs_reverse;
	int	costs_a_rotate_b_reverse;
	int	costs_a_reverse_b_rotate;

	if (costs_stack_a_rotate > costs_stack_b_rotate)
		costs_rotate = costs_stack_a_rotate;
	else
		costs_rotate = costs_stack_b_rotate;
	if (costs_stack_a_reverse > costs_stack_b_reverse)
		costs_reverse = costs_stack_a_reverse;
	else
		costs_reverse = costs_stack_b_reverse;
	costs_a_rotate_b_reverse = costs_stack_a_rotate + costs_stack_b_reverse;
	costs_a_reverse_b_rotate = costs_stack_a_reverse + costs_stack_b_rotate;
	if (costs_rotate <= costs_reverse && costs_rotate <= \
		costs_a_rotate_b_reverse && costs_rotate <= costs_a_reverse_b_rotate)
		return (ROTATE);
	else if (costs_reverse <= costs_a_rotate_b_reverse \
		&& costs_reverse <= costs_a_reverse_b_rotate)
		return (REVERSE_ROTATE);
	else if (costs_a_rotate_b_reverse <= costs_a_reverse_b_rotate)
		return (A_ROTATE_B_REVERSE);
	else
		return (A_REVERSE_B_ROTATE);
}
