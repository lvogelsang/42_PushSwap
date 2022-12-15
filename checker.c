/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:12:00 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/15 13:08:27 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char	**stack_a;
	char	**stack_b;
	int		len;

	if (argc == 2)
		stack_a = ft_split(argv[1], ' ');
	if (argc > 2)
		stack_a = create_stack_a(argc, argv);
	if (argc == 1 || stack_a == NULL)
		return (0);
	len = stack_length(stack_a);
	if (errors(stack_a, len) == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_b = create_stack_b(len);
	if (stack_b == NULL)
		return (0);
	checker(stack_a, stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}

void	*checker(char **stack_a, char **stack_b)
{
	if (execute_operation(stack_a, stack_b) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (stack_sorted_ascend(stack_a) == 1 && stack_length(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

int	execute_operation(char **stack_a, char **stack_b)
{
	char	*instruction;

	instruction = (char *)malloc(4 * sizeof(char));
	if (instruction == NULL)
		return (0);
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		if (validate_operation(instruction) == 0)
		{
			free (instruction);
			return (0);
		}
		push_swap_operation(instruction, stack_a, stack_b);
	}
	free (instruction);
	return (1);
}

int	validate_operation(char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0 \
		|| ft_strncmp(instruction, "ss\n", 3) == 0 \
		|| ft_strncmp(instruction, "sb\n", 3) == 0 \
		|| ft_strncmp(instruction, "pa\n", 3) == 0 \
		|| ft_strncmp(instruction, "pb\n", 3) == 0 \
		|| ft_strncmp(instruction, "ra\n", 3) == 0 \
		|| ft_strncmp(instruction, "rb\n", 3) == 0 \
		|| ft_strncmp(instruction, "rr\n", 3) == 0 \
		|| ft_strncmp(instruction, "rra\n", 4) == 0 \
		|| ft_strncmp(instruction, "rrr\n", 4) == 0 \
		|| ft_strncmp(instruction, "rrb\n", 4) == 0)
	{
		return (1);
	}
	else
		return (0);
}

void	push_swap_operation(char *instruction, char **stack_a, char **stack_b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0 \
		|| ft_strncmp(instruction, "ss\n", 3) == 0)
		swap(stack_a);
	if (ft_strncmp(instruction, "sb\n", 3) == 0 \
		|| ft_strncmp(instruction, "ss\n", 3) == 0)
		swap(stack_b);
	if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push_a(stack_b, stack_a);
	if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push_b(stack_a, stack_b);
	if (ft_strncmp(instruction, "ra\n", 3) == 0 \
		|| ft_strncmp(instruction, "rr\n", 3) == 0)
		rotate(stack_a);
	if (ft_strncmp(instruction, "rb\n", 3) == 0 \
		|| ft_strncmp(instruction, "rr\n", 3) == 0)
		rotate(stack_b);
	if (ft_strncmp(instruction, "rra\n", 4) == 0 \
		|| ft_strncmp(instruction, "rrr\n", 4) == 0)
		reverse_rotate(stack_a);
	if (ft_strncmp(instruction, "rrb\n", 4) == 0 \
		|| ft_strncmp(instruction, "rrr\n", 4) == 0)
		reverse_rotate(stack_b);
}
