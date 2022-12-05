/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/05 14:45:48 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	normalize_stack_a(stack_a, len);
	stack_b = create_stack_b(len);
	if (stack_b == NULL)
		return (0);
	push_swap(stack_a, stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}

void	push_swap(char **stack_a, char **stack_b)
{
	int	bucket_size;

	while (1)
	{
		bucket_size = get_bucket_size(stack_a);
		if (stack_sorted_ascend(stack_a) == 1 && stack_length(stack_b) == 0)
			break ;
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
