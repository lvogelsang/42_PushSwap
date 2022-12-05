/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:07:12 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/05 16:29:47 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

// CHECKER.C

void	*checker(char **stack_a, char **stack_b);
int		execute_operation(char **stack_a, char **stack_b);
int		validate_operation(char *instruction);
void	push_swap_operation(char *instruction, char **stack_a, char **stack_b);

#endif
