/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:05:28 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/18 10:50:20 by lvogelsa         ###   ########.fr       */
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
	int	x;
	int	y;

	while (1)
	{
		if (stack_sorted_ascend(stack_a) == 1 && stack_length(stack_b) == 0)
			break;
		else if (stack_sorted_ascend(stack_a) == 1 && \
			stack_sorted_descend(stack_b) == 1)
				push_a(stack_b, stack_a);
		else
		{
			x = operation_b(stack_b);
			y = operation_a(stack_a);
			if (x == y)
				push_swap_a_b(stack_a, stack_b, x);
			else
			{
				push_swap_b(stack_b, x);
				push_swap_a(stack_a, y);
			}
		}
	}
}
