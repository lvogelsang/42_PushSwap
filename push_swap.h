/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:23:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/16 11:24:47 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# include <stdlib.h>

# define SA	1
# define SB	1
# define SS	1
# define RA	2
# define RB	2
# define RR	2
# define RRA	3
# define RRB	3
# define RRR	3
# define PB	4
# define PA	4

# define ROTATE	0
# define REVERSE_ROTATE 1
# define A_ROTATE_B_REVERSE 2
# define A_REVERSE_B_ROTATE 3

// STACK.C

char	**create_stack_a(int argc, char **argv);
void	*normalize_stack_a(char **stack_a, int len);
void	normalize_stack_a_two(char **stack_a, char **stack_a_index, \
char **stack_a_reduced, int len);
void	stack_remove_min(char **stack_a_reduced, int min);
char	**create_stack_b(int len);

// ERROR.C

int		errors(char **stack_a, int len);
int		error_non_integer(char **stack_a, int len);
int		error_min_max_integer(char **stack_a, int len);
int		error_duplicate(char **stack_a, int len);

// PUSH_SWAP.C

void	push_swap(char **stack_a, char **stack_b);

// STACK_ATTRIBUTES.C

int		stack_sorted_ascend(char **stack);
int		stack_sorted_descend(char **stack);
int		stack_length(char **stack);
int		stack_max_value(char **stack);
int		stack_max_index(char **stack);
int		stack_min_value(char **stack);

// BUCKETS.C

int		get_bucket_size(char **stack_a);
void	buckets(char **stack_a, char **stack_b, int bucket_size);
void	create_bucket(char **stack_a, char **stack_b, int bucket_size);
void	push_bucket_item(char **stack_a, char **stack_b, int min, int max);
void	push_bucket_item_exec(char **stack_a, char **stack_b, int i, int op);
void	sort_buckets(char **stack_a, char **stack_b, int bucket_size);
/*void	sort_buckets_exec(char **stack_a, char **stack_b, int med, \
int max_index);
int		bucket_max_values(char **stack_b, int med);
int		compare_index(int i, int j, int k, int med);
int		standardize_index(int index, int med);
void	sort_stack_a_top(char **stack_a);*/

//-------

int		get_best_index(char **stack_a, char **stack_b, int bucket_size);
int		get_target_position_stack_a(char **stack_a, int b);
int		get_costs_total(int index_a, int index_b, int len_a, int len_b);
int	get_costs_total_two(int costs_stack_a_rotate, int costs_stack_a_reverse, \
	int costs_stack_b_rotate, int costs_stack_b_reverse);
int	get_sort_technique(int index_a, int index_b, int len_a, int len_b);
int	get_sort_technique_two(int costs_stack_a_rotate, int costs_stack_a_reverse, \
	int costs_stack_b_rotate, int costs_stack_b_reverse);

// INDEX_SORT.C

void	rotate_a_b(char **stack_a, char **stack_b, int a, int b);
void	reverse_rotate_a_b(char **stack_a, char **stack_b, int a, int b);
void	rotate_a_reverse_b(char **stack_a, char **stack_b, int a, int b);
void	reverse_a_rotate_b(char **stack_a, char **stack_b, int a, int b);

void	sort_stack_a(char **stack_a);

//--------

// SORT_SHORT.C

void	sort_short(char **stack_a, char **stack_b);
int		operation_b(char **stack_b);
int		operation_a(char **stack_a, int op);

// PUSH_SWAP_EXECUTION.C

void	push_swap_a_b(char **stack_a, char **stack_b, int operation);
void	push_swap_b(char **stack_b, int operation);
void	push_swap_a(char **stack_a, int operation);

// OPERATIONS.C

void	swap(char **stack);
void	rotate(char **stack);
void	reverse_rotate(char **stack);
void	push_a(char **stack_b, char **stack_a);
void	push_b(char **stack_a, char **stack_b);
void	push_a_b(char **stack_a, char **stack_b, int x, int y);

#endif
