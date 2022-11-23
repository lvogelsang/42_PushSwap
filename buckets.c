/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:29:21 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/23 16:52:46 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_bucket(char **stack_a, char **stack_b)
{
	int	min;
	int	i;
	int	bucket_size;
	int	len;
	
	min = stack_min_value(stack_a);
	bucket_size = 0;
	while (bucket_size < BUCKET_SIZE)
	{
		len = stack_length(stack_a);
		push_bucket_item(stack_a, stack_b, len, min);
		bucket_size++;
	}
/*	i = 0;
	while (i < stack_length(stack_b))
	{
		printf("%s\n", stack_b[i]);
		i++;
	}*/
}
			
void	push_bucket_item(char **stack_a, char **stack_b, int len, int min)
{
	int	i;

	i = 0;
	while (i < len / 2)
	{
		if (ft_atoi(stack_a[i]) >= min && ft_atoi(stack_a[i]) < min + BUCKET_SIZE)
		{
			while (i > 0)
			{
				push_swap_a(stack_a, RA);
				i--;
			}
			push_b(stack_a, stack_b);
			break;
		}
		else if (ft_atoi(stack_a[len - i - 1]) >= min && ft_atoi(stack_a[len - i - 1]) < min + BUCKET_SIZE)
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

