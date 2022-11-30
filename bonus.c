/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:12:00 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/30 16:59:49 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int	i;

	i = push_swap_execution(argc, argv);
	if (i == 0)
		return (0);
	create_checker_stacks(argc, argv);
}
//	use get next line:
// 	perform operations on stack. (if operation does not exist, return Error).
//	check if a is sorted ascendingly and if b is empty.

void	*create_checker_stacks(int argc, char **argv)
{
	char	**stack_a;
	char	**stack_b;
	int	i;

	stack_a = (char **)malloc(argc * sizeof(char*));
	if (stack_a == NULL)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		stack_a[i] = argv[i + 1];
		i++;
	}
	stack_a[i] = NULL;
	stack_b = (char **)malloc(argc * sizeof(char *));
	if (stack_b == NULL)
		return (0);
	create_stack_b(argc, stack_b);
/*	int	x = 0;
	while (x < stack_length(stack_a))
	{
		printf("%s\n", stack_a[x]);
		x++;
	}*/
	read_instructions(argc, stack_a, stack_b);
	printf("Hey!");
	checker(stack_a, stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}

void	*read_instructions(int argc, char **stack_a, char **stack_b)
{
	char	*instruction;
	int	i;

//	instruction = (char *)malloc(4 * sizeof(char));
//	if (instruction == NULL)
//		return (0);
	while (1)
	{
		printf("%s\n","Hi");
	//	instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		printf("%s\n", instruction);
		if (validate_operation(instruction) == 0)
		{
			ft_printf("Error\n");
			break ;
		}
		execute_operation(instruction, stack_a, stack_b);
	}
//	free (instruction);
	return (0);
}

int	validate_operation(char *instruction)
{
	if (ft_strncmp(instruction, "sa", 2) == 0 || ft_strncmp(instruction, "ss", 2) == 0 \
		|| ft_strncmp(instruction, "sb", 2) == 0 || ft_strncmp(instruction, "ss", 2) == 0 \
		|| ft_strncmp(instruction, "pa", 2) == 0 || ft_strncmp(instruction, "pb", 2) == 0 \
		|| ft_strncmp(instruction, "ra", 2) == 0 || ft_strncmp(instruction, "rr", 2) == 0 \
		|| ft_strncmp(instruction, "rb", 2) == 0 || ft_strncmp(instruction, "rr", 2) == 0 \
		|| ft_strncmp(instruction, "rra", 3) == 0 || ft_strncmp(instruction, "rrr", 3) == 0 \
		|| ft_strncmp(instruction, "rrb", 3) == 0 || ft_strncmp(instruction, "rrr", 3) == 0)
	{
		return (1);
	}
	else
		return (0);
}

void	execute_operation(char *instruction, char **stack_a, char **stack_b)
{
	if (ft_strncmp(instruction, "sa", 2) == 0 || ft_strncmp(instruction, "ss", 2) == 0)
		swap(stack_a);
	if (ft_strncmp(instruction, "sb", 2) == 0 || ft_strncmp(instruction, "ss", 2) == 0)
		swap(stack_b);
	if (ft_strncmp(instruction, "pa", 2) == 0)
		push_a(stack_b, stack_a);
	if (ft_strncmp(instruction, "pb", 2) == 0)
		push_b(stack_a, stack_b);
	if (ft_strncmp(instruction, "ra", 2) == 0 || ft_strncmp(instruction, "rr", 2) == 0)
		rotate(stack_a);
	if (ft_strncmp(instruction, "rb", 2) == 0 || ft_strncmp(instruction, "rr", 2) == 0)
		rotate(stack_b);
	if (ft_strncmp(instruction, "rra", 3) == 0 || ft_strncmp(instruction, "rrr", 3) == 0)
		reverse_rotate(stack_a);
	if (ft_strncmp(instruction, "rrb", 3) == 0 || ft_strncmp(instruction, "rrr", 3) == 0)
		reverse_rotate(stack_b);
}

void	checker(char **stack_a, char **stack_b)
{
	if (stack_sorted_ascend(stack_a) == 1 && stack_length(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
