/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:11:28 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/28 12:59:05 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char **stack)
{
	char	*temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	rotate(char **stack)
{
	char	*temp;
	int		len;
	int		i;

	temp = stack[0];
	len = stack_length(stack);
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = temp;
}

void	reverse_rotate(char **stack)
{
	char	*temp;
	int		len;
	int		i;

	len = stack_length(stack);
	temp = stack[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}	

void	push_a(char **stack_b, char **stack_a)
{
	int		len;
	int		i;
	
	len = stack_length(stack_a);
	i = len;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	len = stack_length(stack_b);
	i = 0;
	while (i < len)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	ft_printf("%s\n", "pa");
}

void	push_b(char **stack_a, char **stack_b)
{
	int	len;
	int	i;

	len = stack_length(stack_b);
	i = len;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	len = stack_length(stack_a);
	i = 0;
	while (i < len)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	ft_printf("%s\n", "pb");
}

// Potentially refine the following function?

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
