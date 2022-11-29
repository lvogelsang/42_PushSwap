/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:29:21 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/30 09:58:53 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bucket_size(char **stack_a)
{
	int	len;
	int	bucket_size;

	len = stack_length(stack_a);
	if (len <= 10)
		bucket_size = 10;
	else if (len > 10 && len <= 50)
		bucket_size = len / 2;
	else if (len > 50 && len <= 100)
		bucket_size = len / 4;
	else if (len > 100 && len <= 200)
		bucket_size = len / 5;
	else if (len > 200 && len <= 500)
		bucket_size = len / 8;
	else if (len > 500)
		bucket_size = len / 20;
	return (bucket_size);
}

void	buckets(char **stack_a, char **stack_b, int bucket_size)
{
	int	x;
	
//	printf("\nBucket: %d\n", bucket_size);
	create_bucket(stack_a, stack_b, bucket_size);
//	printf("Len A:%d\nLen B:%d\n", stack_length(stack_a), stack_length(stack_b));
	bucket_size = get_bucket_size(stack_a);
//	printf("New Bucket: %d\n", bucket_size);
//	static int y;
	if (stack_length(stack_a) <= bucket_size)
	{
		while (stack_sorted_ascend(stack_a) == 0)
		{
			x = operation_a(stack_a, 1);
			push_swap_a(stack_a, x);
		}
	}
/*	else
	{
		int	i = 0;
		while (i < stack_length(stack_a))
		{
			printf("%s ", stack_a[i]);
			i++;
		}
		printf("\n");
		i = 0;
		while (i < stack_length(stack_b))
		{
			printf("%s ", stack_b[i]);
			i++;
		}
		y++;
		if (y == 3)
			printf("the end");
*/		else
		{
//			printf("recursive push_swap");
			push_swap(stack_a, stack_b);
		}
//	}
}

void	create_bucket(char **stack_a, char **stack_b, int bucket_size)
{
	int	i;
	int	min;
	int	max;
	
	min = stack_min_value(stack_a);
	max = min + bucket_size;
//	printf("Min: %d\n", min);
//	printf("Max: %d\n", max);
	i = 0;
	while (i < bucket_size)
	{
//		printf("Hello?\n");
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
//		printf("The process ran: %d times\n", i);
		if (ft_atoi(stack_a[i]) >= min && ft_atoi(stack_a[i]) < max)
		{
			while (i > 0)
			{
				push_swap_a(stack_a, RA);
				i--;
			}
			push_b(stack_a, stack_b);
			break ;
		}
		else if (ft_atoi(stack_a[len - i - 1]) >= min && ft_atoi(stack_a[len - i - 1]) < max)
		{
			while (i >= 0)
			{
				push_swap_a(stack_a, RRA);
				i--;
			}
			push_b(stack_a, stack_b);
			break ;
		}
		i++;
	}
}

void	sort_buckets(char **stack_a, char **stack_b, int bucket_size)
{
	int	i;
	int	j;
	int	max_index;
	int	med;
	
	j = 0;
	while (j < bucket_size)
	{
		max_index = stack_max_index(stack_b);
		med = stack_length(stack_b) / 2;
		if (max_index <= med)
		{
			while (ft_atoi(stack_b[0]) != stack_max_value(stack_b))
					push_swap_b(stack_b, RB);
		}
		else
		{
			while (ft_atoi(stack_b[0]) != stack_max_value(stack_b))
				push_swap_b(stack_b, RRB);
		}
		push_a(stack_b, stack_a);
		j++;
	}
}
