/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:23:45 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/11/17 14:23:02 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/ft_printf.h"

# include <stdio.h>
# include <stdlib.h>

# define MAX_INT	2147483647
# define MIN_INT	-2147483648

void	create_stack_a(int argc, char **argv, char **stack_a);

int	standard_error(int argc, char **argv);
int	error_non_integer(int argc, char **argv);
int     error_min_max_integer(int argc, char **argv);
int     error_duplicate(int argc, char **argv);

#endif
