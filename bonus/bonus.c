/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:12:00 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/01 16:27:44 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	*split_input_1(char **argv);
void	*create_checker_stacks1(int argc, char **argv);
int	main(int argc, char **argv)
{
	int	i;

	create_checker_stacks(argc, argv);	
}

void	*create_checker_stacks(int argc, char **argv)
{
	char	**stack_a;
	char	**stack_b;
	int	i;
	
	if (argc == 1)
		return (0);
	i = 0;
	while (argc == 2 && argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) == 0)
		{
				split_input_1(argv);
				return (0);
		}
		i++;
	}
	if (errors(argc, argv, 1) == 1)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	create_checker_stacks1(argc, argv);
	return (0);
}

void	*split_input_1(char **argv)
{
	char	**stack_a;

	stack_a = ft_split(argv[1], ' ');
	int	len;

	len = 0;
	while (stack_a[len])
	{
		len++;
	}
	//need to modify error functions to incorporate if I input len or argc.
	if (errors(len, stack_a, 0) == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	char **stack_b = (char **)malloc((len + 1) * sizeof(char *));
	create_stack_b(len + 1, stack_b);
/*	int	z = 0;
	while (z < stack_length(stack_a))
	{
		ft_printf("%s\n", stack_a[z]);
		z++;
	}*/
//	printf("%d\n", read_instructions(len + 1, stack_a, stack_b, argv));
	if (read_instructions(len + 1, stack_a, stack_b, argv) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
/*	z = 0;
	while (z < stack_length(stack_a))
	{
		ft_printf("%s\n", stack_a[z]);
		z++;
	}*/
	checker(stack_a, stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}

void	*create_checker_stacks1(int argc, char **argv)
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
	if (read_instructions(argc, stack_a, stack_b, argv) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
/*	int	z = 0;
	while (z < stack_length(stack_a))
	{
		ft_printf("%s\n", stack_a[z]);
		z++;
	}*/
	checker(stack_a, stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}

#include <stdio.h>
#include <fcntl.h>
int	read_instructions(int argc, char **stack_a, char **stack_b, char **argv)
{
	char	*instruction;
	int	i;

	instruction = (char *)malloc(4 * sizeof(char));
	if (instruction == NULL)
		return (0);
	i = 0;
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
//		printf("%d\n", validate_operation(instruction));
		if (validate_operation(instruction) == 0)
		{
		//	ft_printf("Error\n");
			free (instruction);
			return (0) ;
		}
//		printf("%s\n", instruction);
		execute_operation(instruction, stack_a, stack_b);
/*		int	j = 0;
		while (j < stack_length(stack_a))
		{
			printf("%s ", stack_a[j]);
			j++;
		}
		printf("\n");*/
	}
	free (instruction);
	return (1);
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
	if (ft_strncmp(instruction, "ra", 2) == 0 || ft_strncmp(instruction, "rr", 3) == 0)
		rotate(stack_a);
	if (ft_strncmp(instruction, "rb", 2) == 0 || ft_strncmp(instruction, "rr", 3) == 0)
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
