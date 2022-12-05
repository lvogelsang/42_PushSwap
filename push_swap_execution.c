/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_execution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:05:28 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/05 20:08:09 by lvogelsa         ###   ########.fr       */
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
