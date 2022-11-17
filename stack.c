/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:13:18 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/17 13:31:34 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack_a(int argc, char **argv, char **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		stack_a[i] = argv[i];
		i++;
	}
	stack_a[i] = NULL;
}		
