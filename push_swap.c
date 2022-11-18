/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:05:28 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/18 15:43:43 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_a_b(char **stack_a, char **stack_b, int operation)
{
	if (operation == 1)
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("%s\n", "ss");
	}
	else if (operation == 2)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("%s\n", "rr");
	}
	else if (operation == 3)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("%s\n", "rrr");
	}
}

void	push_swap_b(char **stack_b, int operation)
{
	if (operation == 1)
	{
		swap(stack_b);
		ft_printf("%s\n", "sb");
	}
	else if (operation == 2)
	{
		rotate(stack_b);
		ft_printf("%s\n", "rb");
	}
	else if (operation == 3)
	{
		reverse_rotate(stack_b);
		ft_printf("%s\n", "rrb");
	}
}

void	push_swap_a(char **stack_a, int operation)
{
	if (operation == 1)
	{
		swap(stack_a);
		ft_printf("%s\n", "sa");
	}
	else if (operation == 2)
	{
		rotate(stack_a);
		ft_printf("%s\n", "ra");
	}
	else if (operation == 3)
	{
		reverse_rotate(stack_a);
		ft_printf("%s\n", "rra");
	}
}

void	push_a_b(char **stack_a, char **stack_b, int x, int y)
{
	if (x == 4 && stack_sorted_ascend(stack_a) == 0)
	{
		push_swap_b(stack_b, y);
		push_b(stack_a, stack_b);
	}
	else if (y == 4 && stack_sorted_descend(stack_b) == 0)
	{
		push_swap_a(stack_a, x);
		push_a(stack_b, stack_a);
	}
	else
	{
		push_swap_a(stack_a, x);
		push_swap_b(stack_b, y);
	}
}
