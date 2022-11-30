/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:12:00 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/30 13:42:57 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	stack_a[i] = NULL:
	stack_b = (char **)malloc(argc * sizeof(char *));
	if (stack_b == NULL)
		return (0);
	create_stack_b(argc, stack_b);
	read_instructions(stack_a, stack_b);
	checker(stack_a, stack_b);
	free (stack_a);
	free (stack_b);
}

void	*read_instructions(int argc, char **stack_a, char **stack_b)
{
	char	*instruction;
	int	i;

	instruction = (char *)malloc(4 * sizeof(char));
	if (instruction == NULL)
		return (0);
	i = 1;
	while (i < argc)
	{
		instruction = get_next_line(0);
		execute_operation(instruction, stack_a, stack_b);
		i++;
	}
}

void	execute_operation(char *instruction, char **stack_a, char **stack_b)
{
	if (instruction == "sa" || instruction == "ss")
		swap(stack_a);
	if (instruction == "sb" || instruction == "ss")
		swap(stack_b)
	if 






