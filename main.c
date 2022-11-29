/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:58:44 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/29 13:01:15 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (errors(argc, argv) == 1)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	create_stacks(argc, argv);
	return (0);
}

void	push_swap(char **stack_a, char **stack_b)
{
	int	bucket_size;
	int	i;
	int	x;
	int	y;
	
	while (1)
	{
		bucket_size = get_bucket_size(stack_a);
		if (stack_sorted_ascend(stack_a) == 1 && stack_length(stack_b) == 0)
			break;
		else if (stack_sorted_ascend(stack_a) == 1 && \
			stack_sorted_descend(stack_b) == 1)
				push_a(stack_b, stack_a);
		else if (stack_length(stack_a) > bucket_size && stack_sorted_ascend(stack_a) == 0)
			buckets(stack_a, stack_b, bucket_size);
		else if (stack_length(stack_a) + stack_length(stack_b) <= bucket_size)
				sort_short(stack_a, stack_b);
		if (stack_length(stack_b) >= bucket_size)
		{
			sort_buckets(stack_a, stack_b, bucket_size);
			break ;
		}
	}
}
