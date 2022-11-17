/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:05:28 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/17 13:46:59 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**stack_a;

	if (argc == 1)
		return (0);
	if (standard_error(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = (char **)malloc(argc * sizeof(char *));
	if (stack_a == NULL)
		return (0);
	create_stack_a(argc, argv, stack_a);
}
