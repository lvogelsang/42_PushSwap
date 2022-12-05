/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:13:18 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/05 13:10:47 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_stack_a(int argc, char **argv)
{
	char	**stack_a;
	int		i;

	stack_a = (char **)malloc(argc * sizeof(char *));
	if (stack_a == NULL)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		stack_a[i] = argv[i + 1];
		i++;
	}
	stack_a[i] = NULL;
	return (stack_a);
}

void	*normalize_stack_a(char **stack_a, int len)
{
	char	**stack_a_index;
	char	**stack_a_reduced;
	int		i;

	stack_a_index = (char **)malloc((len + 1) * sizeof(char *));
	if (stack_a_index == NULL)
		return (0);
	stack_a_reduced = (char **)malloc((len + 1) * sizeof(char *));
	if (stack_a_reduced == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		stack_a_index[i] = stack_a[i];
		stack_a_reduced[i] = stack_a[i];
		i++;
	}
	stack_a_index[i] = NULL;
	stack_a_reduced[i] = NULL;
	normalize_stack_a_two(stack_a, stack_a_index, stack_a_reduced, len);
	free (stack_a_index);
	free (stack_a_reduced);
	return (0);
}

void	normalize_stack_a_two(char **stack_a, char **stack_a_index, \
char **stack_a_reduced, int len)
{
	int	i;
	int	j;
	int	min;

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
				break ;
			}
			j++;
		}
		i++;
	}
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

char	**create_stack_b(int len)
{
	char	**stack_b;
	int		i;

	stack_b = (char **)malloc((len + 1) * sizeof(char *));
	if (stack_b == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		stack_b[i] = "x";
		i++;
	}
	stack_b[i] = NULL;
	return (stack_b);
}
