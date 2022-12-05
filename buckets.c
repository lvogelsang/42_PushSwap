/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:29:21 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/05 20:05:38 by lvogelsa         ###   ########.fr       */
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
	if (stack_length(stack_a) <= bucket_size)
	{
		while (stack_sorted_ascend(stack_a) == 0)
		{
			x = operation_a(stack_a, 1);
			push_swap_a(stack_a, x);
		}
	}		
	else
		push_swap(stack_a, stack_b);
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
	int	i;
	int	max_index;
	int	med;

	i = 0;
	while (i < bucket_size)
	{
		med = stack_length(stack_b) / 2;
		max_index = bucket_max_values(stack_b, med);
		sort_buckets_exec(stack_a, stack_b, med, max_index);
		if (ft_atoi(stack_a[0]) > ft_atoi(stack_a[1]))
			push_swap_a(stack_a, SA);
		i++;
	}
}

void	sort_buckets_exec(char **stack_a, char **stack_b, int med, \
int max_index)
{
	if (max_index <= med)
	{
		while (ft_atoi(stack_b[0]) != stack_max_value(stack_b) \
			&& ft_atoi(stack_b[0]) != stack_max_value(stack_b) - 1)
			push_swap_b(stack_b, RB);
	}
	else
	{
		while (ft_atoi(stack_b[0]) != stack_max_value(stack_b) \
			&& ft_atoi(stack_b[0]) != stack_max_value(stack_b) - 1)
			push_swap_b(stack_b, RRB);
	}
	push_a(stack_b, stack_a);
	ft_printf("pa\n");
}

int	bucket_max_values(char **stack_b, int med)
{
	int	i;
	int	j;
	int	max;

	max = stack_max_value(stack_b);
	i = 0;
	while (ft_atoi(stack_b[i]) != max)
		i++;
	j = 0;
	while (j < stack_length(stack_b) && ft_atoi(stack_b[j]) != max - 1)
		j++;
	if (j == stack_length(stack_b))
		return (i);
	return (compare_index(i, j, med));
}

int	compare_index(int i, int j, int med)
{
	int	x;
	int	y;

	x = i;
	y = j;
	if (x <= med)
		x = x + med;
	else
		x = x - med;
	if (y <= med)
		y = y + med;
	else
		y = y - med;
	if (x - med <= y - med)
		return (i);
	else
		return (j);
}
