/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:58:44 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/28 12:58:36 by lvogelsa         ###   ########.fr       */
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
// Make distinction for bucket size based on length.
void	push_swap(char **stack_a, char **stack_b)
{
	int	x;
	int	y;
	
	while (1)
	{
		//----
		int	steps = 0;
		//----
		if (stack_sorted_ascend(stack_a) == 1 && stack_length(stack_b) == 0)
			break;
		else if (stack_sorted_ascend(stack_a) == 1 && \
			stack_sorted_descend(stack_b) == 1)
				push_a(stack_b, stack_a);
		//modify bucket size based on stack size.
		// stack_b == descend ?
		else if (stack_length(stack_a) > BUCKET_SIZE)
		{
			create_bucket(stack_a, stack_b);
			while (stack_sorted_descend(stack_b) == 0)
			{
			//	y = operation_b(stack_b);
				y = operation_b(stack_b);
				push_swap_b(stack_b, y);
				//----
				steps++;
				//----
			}
			if (stack_length(stack_a) <= BUCKET_SIZE)
			{
				while (stack_sorted_ascend(stack_a) == 0)
				{
					x = operation_a(stack_a, 1);
					push_swap_a(stack_a, x);
					//----
					steps++;
					//----
				}
			}
			//----
//			printf("Sortingsteps: %d\n", steps);
			//combine commands?
		}
		else
			push_swap_execution(stack_a, stack_b);
	}
}
// optimize it with 4 for a
void	push_swap_execution(char **stack_a, char **stack_b)
{
	int	x;
	int	y;

	x = operation_a(stack_a, 0);
	y = operation_b(stack_b);
	// Modify push function as push a is not needed here anymore. 
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
