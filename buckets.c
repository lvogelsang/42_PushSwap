/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:39:09 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/16 14:08:32 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bucket_size(char **stack_a)
{
	int	bucket_size;
	int	len;

	len = stack_length(stack_a);
	bucket_size = 5;
	if (len > 5)
		bucket_size = len / 2;
	return (bucket_size);
}

void	buckets(char **stack_a, char **stack_b, int bucket_size)
{
	int	x;

	create_bucket(stack_a, stack_b, bucket_size);
	bucket_size = get_bucket_size(stack_a);
	if (stack_length(stack_a) <= bucket_size \
		|| stack_sorted_ascend(stack_a) == 1)
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
