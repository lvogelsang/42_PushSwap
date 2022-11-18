/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:23:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/18 10:53:27 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/ft_printf.h"

# include <stdio.h>
# include <stdlib.h>

# define SA	1
# define SB	1
# define RA	2
# define RB	2
# define RRA	3
# define RRB	3
# define PB	4

void    *create_stacks(int argc, char **argv);
void	create_stack_a(int argc, char **argv, char **stack_a);
void    create_stack_b(int argc, char **stack_b);

int		errors(int argc, char **argv);
int		error_non_integer(int argc, char **argv);
int		error_min_max_integer(int argc, char **argv);
int		error_duplicate(int argc, char **argv);

void	push_swap(char **stack_a, char **stack_b);

int     stack_sorted_ascend(char **stack);
int     stack_sorted_descend(char **stack);
int		stack_length(char **stack);
int		stack_max_value(char **stack);
int		stack_min_value(char **stack);

int		operation_b(char **stack_b);
int		operation_a(char **stack_a);

#endif
