/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_buckets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:55:23 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/28 16:57:39 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	stack_max_index(char **stack);
void	sort_buckets(char **stack_a, char **stack_b, int bucket_count)
{
	int	i;
	int	j;
	int	x;
	int	steps;
	int	max_index;
	int	med;
	steps = 0;
		j = 0;
		x = 0;
		while (j < BUCKET_SIZE)
		{
			max_index = stack_max_index(stack_b);
			med = stack_length(stack_b) / 2;
			// check to what side the max value is, then move based on that information.
			if (max_index <= med)
			{
				while (ft_atoi(stack_b[0]) != stack_max_value(stack_b))
				{
					push_swap_b(stack_b, RB);
				//	x++;
					steps++;
				}
			}
			else
			{
				// can imporvwe by checking if I pass the next max (need to keep x in mind though!!!)
				while (ft_atoi(stack_b[0]) != stack_max_value(stack_b)) 
				{
					push_swap_b(stack_b, RRB);
				//	x--;
					steps++;
				}
			}
			push_a(stack_b, stack_a);
			steps++;;
			j++;
		}
//	printf("Sorting Bucket: %d\n", steps);
}
