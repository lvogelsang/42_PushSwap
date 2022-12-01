/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:07:12 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/01 15:08:34 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# define INSTRUCTIONS	["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]

void	*create_checker_stacks(int argc, char **argv);
int	read_instructions(int argc, char **stack_a, char **stack_b, char **argv);
int	validate_operation(char *instruction);
void	execute_operation(char *instruction, char **stack_a, char **stack_b);
void	checker(char **stack_a, char **stack_b);

#endif
