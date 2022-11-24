/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:29:21 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/24 12:30:00 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_bucket(char **stack_a, char **stack_b)
{
	int	min;
	int	i;
	int	bucket_size;
	int	max;
	
	min = stack_min_value(stack_a);
	bucket_size = 0;
	max = max_bucket_item(stack_a, min, bucket_size);
	while (bucket_size < BUCKET_SIZE)
	{
		push_bucket_item(stack_a, stack_b, min, max);
//		push_swap_execution(stack_a, stack_b);
		bucket_size++;
	}
/*	i = 0;
	while (i < stack_length(stack_b))
	{
		printf("%s\n", stack_b[i]);
		i++;
	}*/
}
			
void	push_bucket_item(char **stack_a, char **stack_b, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = stack_length(stack_a);
	while (i < len / 2)
	{
		if (ft_atoi(stack_a[i]) >= min && ft_atoi(stack_a[i]) < max)
		{
			while (i > 0)
			{
				push_swap_a(stack_a, RA);
				i--;
			}
			push_b(stack_a, stack_b);
			break;
		}
		else if (ft_atoi(stack_a[len - i - 1]) >= min \
			&& ft_atoi(stack_a[len - i - 1]) < max)
		{
			while (i >= 0)
			{
				push_swap_a(stack_a, RRA);
				i--;
			}
			push_b(stack_a, stack_b);
			break;
		}
		i++;
	}
}

// Don't need this if changing the algorithm for large number sets. 
int	max_bucket_item(char **stack_a, int min, int bucket_size)
{
	char	**stack_a_copy;
	int	i;
	int	max;
	
//	printf("%d\n", min);
	stack_a_copy = (char **)malloc((stack_length(stack_a) + 1) * sizeof(char *));
	if (stack_a_copy == NULL)
		return (0);
	// This could cause a problem (return (0));
	i = 0;
	while (i < stack_length(stack_a))
	{
		stack_a_copy[i] = stack_a[i];
		i++;
	}
	stack_a_copy[i] = NULL;
	max = min;
	while (bucket_size < BUCKET_SIZE)
	{
		stack_remove_min(stack_a_copy, max);
		max = stack_min_value(stack_a_copy);
		bucket_size++;
	}
//	printf("%d\n", max);
	free (stack_a_copy);
	return (max);
}
