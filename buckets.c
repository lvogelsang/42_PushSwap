/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:29:21 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/15 17:24:51 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bucket_size(char **stack_a)
{
	int	bucket_size;
	int	len;

	len = stack_length(stack_a);
	bucket_size = 5;
	if (len > 5 && len <= 50)
		bucket_size = len / 2;
	else if (len > 50 && len <= 80)
		bucket_size = len / 3;
	else if (len > 80 && len <= 200)
		bucket_size = len / 5;
	else if (len > 200 && len <= 500)
		bucket_size = len / 7;
	else if (len > 500)
		bucket_size = len / 10;
	return (bucket_size);
}

void	buckets(char **stack_a, char **stack_b, int bucket_size)
{
	int	x;

	create_bucket(stack_a, stack_b, bucket_size);
	bucket_size = get_bucket_size(stack_a);
	if (stack_length(stack_a) <= bucket_size || stack_sorted_ascend(stack_a) == 1)
	{
		while (stack_sorted_ascend(stack_a) == 0)
		{
			x = operation_a(stack_a, 1);
			push_swap_a(stack_a, x);
		}
	}		
	else
		push_swap(stack_a, stack_b);
	//------
//	ft_printf("Finish bucket\n");
}

void	create_bucket(char **stack_a, char **stack_b, int bucket_size)
{
	int	i;
	int	max;
	int	min;

	min = stack_min_value(stack_a);
	max = min + bucket_size;
	i = 0;
	while (i < bucket_size)
	{
		push_bucket_item(stack_a, stack_b, min, max);
		i++;
	}
}

void	push_bucket_item(char **stack_a, char **stack_b, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = stack_length(stack_a);
	while (i < len / 2 + 1)
	{
		if (ft_atoi(stack_a[i]) >= min && ft_atoi(stack_a[i]) < max)
		{
			push_bucket_item_exec(stack_a, stack_b, i, RA);
			break ;
		}
		else if (ft_atoi(stack_a[len - i - 1]) >= min \
			&& ft_atoi(stack_a[len - i - 1]) < max)
		{
			push_bucket_item_exec(stack_a, stack_b, i, RRA);
			break ;
		}
		i++;
	}
}

void	push_bucket_item_exec(char **stack_a, char **stack_b, int i, int op)
{
	if (op == RA)
		i--;
	while (i >= 0)
	{
		push_swap_a(stack_a, op);
		i--;
	}
	push_b(stack_a, stack_b);
	ft_printf("pb\n");
}

void	sort_buckets(char **stack_a, char **stack_b, int bucket_size)
{
	int	best_index;
	int	index_a;
	int	sort_technique;
	int	i;
	int	a;
	int	b;

	i = 0;
	while (i < bucket_size)
	{
		best_index = get_best_index(stack_a, stack_b);
		index_a = get_target_position_stack_a(stack_a, ft_atoi(stack_b[best_index]));
		sort_technique = get_sort_technique(index_a, best_index, stack_length(stack_a), stack_length(stack_b));
		a = ft_atoi(stack_a[index_a]);
		b = ft_atoi(stack_b[best_index]);
		//------
//		ft_printf("B_I: %d A_I: %d SORT: %d A: %d B: %d\n", best_index, index_a, sort_technique, a, b);
		//-----
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
		i++;
	}
	sort_stack_a(stack_a);
}

int	get_best_index(char **stack_a, char **stack_b)
{
	int	best_index;
	int	index_b;
	int	min_costs;
	int	index_a;
	int	costs;

	index_b = 0;
	min_costs = stack_length(stack_b) / 2 + stack_length(stack_a) / 2 + 2;
	best_index = 0;
	while (index_b < stack_length(stack_b))
	{
		index_a = get_target_position_stack_a(stack_a, ft_atoi(stack_b[index_b]));
		costs = get_costs_total(index_a, index_b, stack_length(stack_a), stack_length(stack_b));
		//------
//		ft_printf("BEST: %d B: %d A: %d COSTS: %d\n", best_index, index_b, index_a, costs);
		if (costs < min_costs)
		{
			min_costs = costs;
			best_index = index_b;
		}
		index_b++;
	}
	return (best_index);
}

int	get_target_position_stack_a(char **stack_a, int	b)
{
	int	index_a;
	int	i;

	index_a = 0;
	while (index_a + 1 < stack_length(stack_a))
	{
		if (b < stack_min_value(stack_a))
		{
			i = 0;
			while (ft_atoi(stack_a[i]) != stack_max_value(stack_a))
				i++;
			index_a = i;
			break;
		}
		if (b > ft_atoi(stack_a[index_a]) && b < ft_atoi(stack_a[index_a + 1]))
			break;
		index_a++;
	}
	return (index_a);
}

int	get_costs_total(int index_a, int index_b, int len_a, int len_b)
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
	//-----
//	ft_printf("A_ROT: %d A_REV: %d B_ROT: %d B_REV: %d\n", costs_stack_a_rotate, costs_stack_a_reverse, costs_stack_b_rotate, costs_stack_b_reverse);
	costs_total = get_costs_total_two(costs_stack_a_rotate, costs_stack_a_reverse, \
	costs_stack_b_rotate, costs_stack_b_reverse);
	return (costs_total);
}

int	get_costs_total_two(int costs_stack_a_rotate, int costs_stack_a_reverse, \
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
	if (costs_rotate <= costs_reverse && costs_rotate <= costs_a_rotate_b_reverse \
		&& costs_rotate <= costs_a_reverse_b_rotate)
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
	sort_technique = get_sort_technique_two(costs_stack_a_rotate, costs_stack_a_reverse, \
	costs_stack_b_rotate, costs_stack_b_reverse);
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
	if (costs_rotate <= costs_reverse && costs_rotate <= costs_a_rotate_b_reverse \
		&& costs_rotate <= costs_a_reverse_b_rotate)
		return (ROTATE);
	else if (costs_reverse <= costs_a_rotate_b_reverse \
		&& costs_reverse <= costs_a_reverse_b_rotate)
		return (REVERSE_ROTATE);
	else if (costs_a_rotate_b_reverse <= costs_a_reverse_b_rotate)
		return (A_ROTATE_B_REVERSE);
	else
		return (A_REVERSE_B_ROTATE);
}
/*
void	sort_buckets(char **stack_a, char **stack_b, int bucket_size)
{
	int	i;
	int	max_index;
	int	med;

	i = 0;
	while (i < bucket_size)
	{
		med = stack_length(stack_b) / 2;
		max_index = bucket_max_values(stack_b, med);
		sort_buckets_exec(stack_a, stack_b, med, max_index);
		sort_stack_a_top(stack_a);
		i++;
	}
}

void	sort_buckets_exec(char **stack_a, char **stack_b, int med, \
int max_index)
{
	if (max_index <= med)
	{
		while (max_index > 0)
		{
			push_swap_b(stack_b, RB);
			max_index--;
		}
	}
	else
	{
		while (max_index < stack_length(stack_b))
		{
			push_swap_b(stack_b, RRB);
			max_index++;
		}
	}
	push_a(stack_b, stack_a);
	ft_printf("pa\n");
}

int	bucket_max_values(char **stack_b, int med)
{
	int	i;
	int	j;
	int	k;
	int	max;

	max = stack_max_value(stack_b);
	i = 0;
	while (ft_atoi(stack_b[i]) != max)
		i++;
	j = 0;
	while (j < stack_length(stack_b) && ft_atoi(stack_b[j]) != max - 1)
		j++;
	if (j == stack_length(stack_b))
		j = -1;
	k = 0;
	while (k < stack_length(stack_b) && ft_atoi(stack_b[k]) != max - 2)
		k++;
	if (k == stack_length(stack_b))
		k = -1;
	return (compare_index(i, j, k, med));
}

int	compare_index(int i, int j, int k, int med)
{
	int	x;
	int	y;
	int	z;

	x = standardize_index(i, med);
	y = standardize_index(j, med);
	z = standardize_index(k, med);
	if ((x <= y || y == -1) && (x <= z || z == -1))
		return (i);
	else if (y <= x && (y <= z || z == -1) && y != -1)
		return (j);
	else
		return (k);
}

int	standardize_index(int index, int med)
{
	if (index <= med)
		return (index);
	else
		return ((med * 2) - index);
}

void	sort_stack_a_top(char **stack_a)
{
	while (stack_sorted_ascend(stack_a) == 0)
	{
		if (ft_atoi(stack_a[0]) > ft_atoi(stack_a[1]))
			push_swap_a(stack_a, SA);
		else if (ft_atoi(stack_a[1]) > ft_atoi(stack_a[2]))
			push_swap_a(stack_a, RA);
		else
			push_swap_a(stack_a, RRA);
	}
}*/
