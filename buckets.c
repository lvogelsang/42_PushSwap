/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:29:21 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/28 16:30:37 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_bucket(char **stack_a, char **stack_b)
{
	int	min;
	int	i;
	int	bucket_size;
	int	max;
	
	min = stack_min_value(stack_a);
	bucket_size = 0;
	max = min + BUCKET_SIZE;
	//---------
	int	steps = 0;
	//---------
//	printf("%s\n", "test1");
	while (bucket_size < BUCKET_SIZE)
	{
//		printf("%d\n", stack_length(stack_a));
		//-------
		steps = push_bucket_item(stack_a, stack_b, min, max, steps);
	//	push_bucket_item(stack_a, stack_b, min, max);
		bucket_size++;
	}
//	printf("Bucketsteps: %d\n", steps);
/*	i = 0;
	while (i < stack_length(stack_b))
	{
		printf("%s\n", stack_b[i]);
		i++;
	}*/
}
/*
void	find_index(char **stack_a, char **stack_b, int i)
{
	int	j;

	j = 0;
	if (stack_length(stack_b) > 2)
	{
	while (j < stack_length(stack_b))
	{
	//	printf("%s\n", "test index");
		// make stacka0 a int variable insteand of inserting the entire stack.
		if ((ft_atoi(stack_a[0]) > ft_atoi(stack_b[0]) && ft_atoi(stack_a[0]) < ft_atoi(stack_b[stack_length(stack_b) - 1])) \
			|| ((ft_atoi(stack_a[0]) == 0 || ft_atoi(stack_a[0]) > stack_max_value(stack_b)) && ft_atoi(stack_b[0]) == stack_max_value(stack_b)))
		{
//			push_b(stack_a, stack_b);
			break ;
		}
		else if ((ft_atoi(stack_a[0]) > ft_atoi(stack_b[j + 1]) && ft_atoi(stack_a[0]) < ft_atoi(stack_b[j])) \
			|| ((ft_atoi(stack_a[0]) == 0 || ft_atoi(stack_a[0]) > stack_max_value(stack_b)) && ft_atoi(stack_b[j + 1]) == stack_max_value(stack_b)))
		{
			while (j > 0)
			{
				push_swap_b(stack_b, RB);
				j--;
			}
//			push_b(stack_a, stack_b);
			break ;
		}
		else if ((ft_atoi(stack_a[0]) > ft_atoi(stack_b[stack_length(stack_b) - 2 - j]) && ft_atoi(stack_a[0]) < ft_atoi(stack_b[stack_length(stack_b) - 1 - j])) \
			|| ((ft_atoi(stack_a[0]) == 0 || ft_atoi(stack_a[0]) > stack_max_value(stack_b)) && ft_atoi(stack_b[stack_length(stack_b) - 1 - j]) == stack_max_value(stack_b)))
		{
			while (j >= 0)
			{
				push_swap_b(stack_b, RRB);
				j--;
			}
//			push_b(stack_a, stack_b);
			break ;
		}
		j++;
	}
	}
}

*/
// void	push_bucket_item(char **stack_a, char **stack_b, int min, int max)
int	push_bucket_item(char **stack_a, char **stack_b, int min, int max, int steps)
{
	int	i;
	int	len;
	int	i_copy;

	i = 0;
	len = stack_length(stack_a);
	while (i < len / 2)
	{
//		printf("%s\n", "test3");
		i_copy = i;
		if (ft_atoi(stack_a[i]) >= min && ft_atoi(stack_a[i]) < max)
		{
			while (i > 0)
			{
				push_swap_a(stack_a, RA);
				i--;
				//-----
				steps++;
				//-----
			}
	//		printf("%s\n", "test");
			//-----
	//		find_index(stack_a, stack_b, i_copy);
	//		printf("%s\n", "seg fault :(");
			push_b(stack_a, stack_b);
	//		if (stack_length(stack_b) == 2 && stack_b[0] < stack_b[1])
	//			push_swap_b(stack_b, SB);
			//-----
			steps++;
			return (steps);
			//-----
			//break;
		}
		else if (ft_atoi(stack_a[len - i - 1]) >= min \
			&& ft_atoi(stack_a[len - i - 1]) < max)
		{
			while (i >= 0)
			{
				push_swap_a(stack_a, RRA);
				i--;
				//-----
				steps++;
				//-----
			}
	//		printf("%s\n", "seg fault");
	//		find_index(stack_a, stack_b, i_copy);
	//		printf("%s\n", "fault");
			push_b(stack_a, stack_b);
	//		if (stack_length(stack_b) == 2 && stack_b[0] < stack_b[1])
	//			push_swap_b(stack_b, SB);
			//-----
			steps++;
			return (steps);
			//-----
			//break;
		}
		i++;
	}
	//------
	return (steps);
	//------
}
/*
// Don't need this if changing the algorithm for large number sets. 
int	max_bucket_item(char **stack_a, int min, int bucket_size)
{
	char	**stack_a_copy;
	int	i;
	int	max;
	
//	printf("%d\n", min);
	stack_a_copy = (char **)malloc((stack_length(stack_a) + 1) * sizeof(char *));
	if (stack_a_copy == NULL)
		return (0);
	// This could cause a problem (return (0));
	i = 0;
	while (i < stack_length(stack_a))
	{
		stack_a_copy[i] = stack_a[i];
		i++;
	}
	stack_a_copy[i] = NULL;
	max = min;
	while (bucket_size < BUCKET_SIZE)
	{
		stack_remove_min(stack_a_copy, max);
		max = stack_min_value(stack_a_copy);
		bucket_size++;
	}
//	printf("%d\n", max);
	free (stack_a_copy);
	return (max);
}*/
