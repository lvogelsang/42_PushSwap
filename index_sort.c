/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:38:57 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/15 16:33:20 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_b(char **stack_a, char **stack_b, int a, int b)
{
	int	len;

	len = stack_length(stack_a);
	while (ft_atoi(stack_a[len - 1]) != a && ft_atoi(stack_b[0]) != b)
		push_swap_a_b(stack_a, stack_b, RR);
	while (ft_atoi(stack_a[len - 1]) != a)
		push_swap_a(stack_a, RA);
	while (ft_atoi(stack_b[0]) != b)
		push_swap_b(stack_b, RB);
}

void	reverse_rotate_a_b(char **stack_a, char **stack_b, int a, int b)
{
	int	len;

	len = stack_length(stack_a);
	while (ft_atoi(stack_a[len - 1]) != a && ft_atoi(stack_b[0]) != b)
		push_swap_a_b(stack_a, stack_b, RRR);
	while (ft_atoi(stack_a[len - 1]) != a)
		push_swap_a(stack_a, RRA);
	while (ft_atoi(stack_b[0]) != b)
		push_swap_b(stack_b, RRB);
}

void	rotate_a_reverse_b(char **stack_a, char **stack_b, int a, int b)
{
	int	len;

	len = stack_length(stack_a);
	while (ft_atoi(stack_a[len - 1]) != a)
		push_swap_a(stack_a, RA);
	while (ft_atoi(stack_b[0]) != b)
		push_swap_b(stack_b, RRB);
}

void	reverse_a_rotate_b(char **stack_a, char **stack_b, int a, int b)
{
	int	len;

	len = stack_length(stack_a);
	while (ft_atoi(stack_a[len - 1]) != a)
		push_swap_a(stack_a, RRA);
	while (ft_atoi(stack_b[0]) != b)
		push_swap_b(stack_b, RB);
}
