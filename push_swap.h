/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:23:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/28 17:10:01 by lvogelsa         ###   ########.fr       */
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
# define PA	4

# define BUCKET_SIZE	45

void    *create_stacks(int argc, char **argv);
void	create_stack_a(int argc, char **argv, char **stack_a);
void	*create_stack_a_copies(char **stack_a, int argc);
void	normalize_stack_a(char **stack_a, char **stack_a_index, char **stack_a_reduced);
void	stack_remove_min(char **stack_a_reduced, int min);
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

void	create_bucket(char **stack_a, char **stack_b);
int	push_bucket_item(char **stack_a, char **stack_b, int min, int max, int steps);
//void	push_bucket_item(char **stack_a, char **stack_b, int min, int max);
int	max_bucket_item(char **stack_a, int min, int bucket_size);

void	push_swap_execution(char **stack_a, char **stack_b);

int		operation_b(char **stack_b);
int		operation_a(char **stack_a, int op);

void	push_swap_a_b(char **stack_a, char **stack_b, int operation);
void	push_swap_b(char **stack_b, int operation);
void	push_swap_a(char **stack_a, int operation);

void	swap(char **stack);
void	rotate(char **stack);
void	reverse_rotate(char **stack);
void	push_a(char **stack_b, char **stack_a);
void	push_b(char **stack_a, char **stack_b);
void	push_a_b(char **stack_a, char **stack_b, int x, int y);

#endif
