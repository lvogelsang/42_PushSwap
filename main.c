/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:58:44 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/01 16:34:10 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	main(int argc, char **argv)
{
	push_swap_execution(argc, argv);
	return (0);
}*/

// combine those with the checker functions.
void	*split_input(char **argv);
int	push_swap_execution(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	int	i = 0;
	while (argc == 2 && argv[1][i])
	{
	//	printf("hi");
		if (ft_isdigit(argv[1][i]) == 0)
		{
				split_input(argv);
				return (0);
		}
		i++;
	}
	if (errors(argc, argv, 1) == 1)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	create_stacks(argc, argv);
	return (1);
}

void	*split_input(char **argv)
{
	char	**stack_a;

	stack_a = ft_split(argv[1], ' ');
	int	len;

	len = 0;
	while (stack_a[len])
	{
//		ft_printf("%s\n", split[len]);
		len++;
	}
//	printf("%d\n", len);
//	need to modify error function to incorporate if I input len or argc.
	if (errors(len, stack_a, 0) == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
//	create_stacks(len, split);
	create_stack_a_copies(stack_a, len + 1);
	char **stack_b = (char **)malloc((len + 1) * sizeof(char *));
	create_stack_b(len + 1, stack_b);
	push_swap(stack_a, stack_b);
	return (0);
}

void	push_swap(char **stack_a, char **stack_b)
{
	int	bucket_size;
	int	i;
	int	x;
	int	y;
	
	int	len = stack_length(stack_a);
	while (1)
	{
		bucket_size = get_bucket_size(stack_a);
		if (stack_sorted_ascend(stack_a) == 1 && stack_length(stack_b) == 0)
			break;
		else if (stack_sorted_ascend(stack_a) == 1 && \
			stack_sorted_descend(stack_b) == 1)
		{
				push_a(stack_b, stack_a);
				ft_printf("pa\n");
		}
		else if (stack_length(stack_a) > bucket_size)
		{	
			buckets(stack_a, stack_b, bucket_size);
			sort_buckets(stack_a, stack_b, bucket_size);
			break ;
		}
		else
			sort_short(stack_a, stack_b);
	}
}
/*	int	z = 0;
	while (z < stack_length(stack_a))
	{
		printf("%s ", stack_a[z]);
		z++;
	}*/
