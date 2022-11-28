/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_buckets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:55:23 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/28 16:34:21 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_buckets(char **stack_a, char **stack_b, int bucket_count)
{
	int	i;
	int	j;
	int	x;
	int	steps;

	steps = 0;
		j = 0;
		x = 0;
		while (j < BUCKET_SIZE)
		{
			while (ft_atoi(stack_b[0]) != stack_max_value(stack_b))
			{
				push_swap_b(stack_b, RB);
				x++;
				steps++;
			}
			push_a(stack_b, stack_a);
			steps++;
			// can imporvwe by checking if I pass the next max (need to keep x in mind though!!!)
			while (x > 0 && (ft_atoi(stack_b[0]) != stack_max_value(stack_b))) 
			{
				push_swap_b(stack_b, RRB);
				x--;
				steps++;
			}
			j++;
		}
//	printf("Sorting Bucket: %d\n", steps);
}
