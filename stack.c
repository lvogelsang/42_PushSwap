/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:13:18 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/23 14:55:32 by lvogelsa         ###   ########.fr       */
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
	push_swap(stack_a, stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}

void	create_stack_a(int argc, char **argv, char **stack_a)
{
	char	**stack_a_copy;
	int	i;
	
	i = 0;
	while (i < argc - 1)
	{
		stack_a[i] = argv[i + 1];
		i++;
	}
	stack_a[i] = NULL;
	create_stack_a_copies(stack_a, argc);	
}

void	*create_stack_a_copies(char **stack_a, int argc)
{
	char	**stack_a_index;
	char	**stack_a_reduced;
	int	i;

	stack_a_index = (char **)malloc(argc * sizeof(char *));
	if (stack_a_index == NULL)
		return (0);
	stack_a_reduced = (char **)malloc(argc * sizeof(char *));
	if (stack_a_reduced == NULL)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		stack_a_index[i] = stack_a[i];
		stack_a_reduced[i] = stack_a[i];
		i++;
	}
	stack_a_index[i] = NULL;
	stack_a_reduced[i] = NULL;
	normalize_stack_a(stack_a, stack_a_index, stack_a_reduced);
	free (stack_a_index);
	free (stack_a_reduced);
	return (0);
}

void	normalize_stack_a(char **stack_a, char **stack_a_index, char **stack_a_reduced)
{
	int		i;
	int	j;
	int		len;
	int		min;

	len = stack_length(stack_a);
	i = 0;
	while (i < len)
	{
		min = stack_min_value(stack_a_reduced);
		j = 0;
		while (j < len)
		{
			if (ft_atoi(stack_a_index[j]) == min)
			{
				stack_a[j] = ft_itoa(i);
				stack_remove_min(stack_a_reduced, min);
				break;
			}
			j++;
		}
		i++;
	}
//	normalize_stack_a_2(stack_a, stack_a_copy, len, min);
}

void	stack_remove_min(char **stack_a_reduced, int min)
{
	int	i;
	int	len;

	i = 0;
	while (ft_atoi(stack_a_reduced[i]) != min)
			i++;
	len = stack_length(stack_a_reduced);
	while (i < len - 1)
	{
		stack_a_reduced[i] = stack_a_reduced[i + 1];
		i++;
	}
	stack_a_reduced[i] = "x";
}
// move forward adn equal the small numbe to x;

/*
void	normalize_stack_a_2(char **stack_a, char **stack_a_copy, int len, int min)
{
	int	i;
	int	index;
	int	j;
	int	num;
	int	x;
	
	i = 1;
	index = 0;
	while (i < len)
	{
//		printf("%d\n+\n", min);
		index = 0;
		num = ft_atoi(stack_a_copy[0]);
		min += 1;
		j = 0;
		while (j < len)
		{
			if (ft_atoi(stack_a_copy[j]) > min && num > ft_atoi(stack_a_copy[j]))
			{
				num = ft_atoi(stack_a_copy[j]);
				index = j;
			}
			j++;
		}
		min = ft_atoi(stack_a_copy[index]);
//		printf("%d\n+\n", min);
		stack_a[index] = ft_itoa(i);
		i++;
		//-------------------------
		x = 0;
		while (x < stack_length(stack_a))
		{
			printf("%s\n", stack_a[x]);
	//	printf("%s\n", stack_a_copy[i]);
			x++;
		}
		printf("%s\n", "-");
	//-------------------------
	}
	//-------------------------
	x = 0;
	while (x < stack_length(stack_a))
	{
		printf("%s\n", stack_a[x]);
	//	printf("%s\n", stack_a_copy[i]);
		x++;
	}
	printf("%s\n", "-");
	//-------------------------
}*/

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
