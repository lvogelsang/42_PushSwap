/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:13:18 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/18 11:39:50 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*create_stacks(int argc, char **argv)
{
	char	**stack_a;
	char	**stack_b;

	stack_a = (char **)malloc(argc * sizeof(char *));
	if (stack_a == NULL)
		return (0);
	create_stack_a(argc, argv, stack_a);
	stack_b = (char **)malloc(argc * sizeof(char *));
	if (stack_b == NULL)
		return (0);
	create_stack_b(argc, stack_b);
	stack_b[0] = "12";
	stack_b[1] = "1";
	printf("%s\n", stack_b[0]);
	push_a(stack_a, stack_b);
	int	i = 0;
	while (i < stack_length(stack_a))
	{
		printf("%s\n", stack_a[i]);
		i++;
	}
//	push_swap(stack_a, stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}

void	create_stack_a(int argc, char **argv, char **stack_a)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		stack_a[i] = argv[i + 1];
		i++;
	}
	stack_a[i] = NULL;
}

void	create_stack_b(int argc, char **stack_b)
{
	int i;
	
	i = 0;
	while (i < argc - 1)
	{
		stack_b[i] = "x";
		i++;
	}
	stack_b[i] = NULL;
}
