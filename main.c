/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:58:44 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/23 16:52:49 by lvogelsa         ###   ########.fr       */
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
// Make disticntion for bucket size.
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
			// Probably don't need descend == 1.
			if (stack_length(stack_a) > BUCKET_SIZE && stack_sorted_descend(stack_b) == 1)
			{
				create_bucket(stack_a, stack_b);
				while (stack_sorted_descend(stack_b) == 0)
					push_swap_execution(stack_a, stack_b);
			}
			else
				push_swap_execution(stack_a, stack_b);
		}
	}
}

void	push_swap_execution(char **stack_a, char **stack_b)
{
	int	x;
	int	y;

	x = operation_a(stack_a);
	y = operation_b(stack_b);
	// Might have to delete/modify the PB/PA functions?
	if (x == 4 || y == 4)
		push_a_b(stack_a, stack_b, x, y);
	else if (x == y)
		push_swap_a_b(stack_a, stack_b, x);
	else
	{
		push_swap_a(stack_a, x);
		push_swap_b(stack_b, y);
	}
}
