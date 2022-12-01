/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:19:55 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/12/01 16:27:50 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errors(int argc, char **argv, int i)
{
	if (error_non_integer(argc, argv, i) == 1)
		return (1);
	if (error_min_max_integer(argc, argv, i) == 1)
		return (1);
	if (error_duplicate(argc, argv, i) == 1)
		return (1);
	return (0);
}

int	error_non_integer(int argc, char **argv, int i)
{
//	int	i;
	int	j;

//	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_min_max_integer(int argc, char **argv, int i)
{
//	int	i;
	int	num;

//	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (ft_itoa(num)[0] != argv[i][0])
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicate(int argc, char **argv, int i)
{
//	int	i;
	int	j;
	
//	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
