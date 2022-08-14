/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:29:51 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 15:29:55 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *b)
{
	int	i;
	int	min;
	int	ind;

	i = 0;
	min = 2147483647;
	while (i < b->size)
	{
		if (b->stack[i] < min)
		{
			min = b->stack[i];
			ind = i;
		}
		++i;
	}
	return (ind);
}

int	find_max_index(t_stack *b)
{
	int	i;
	int	max;
	int	ind;

	i = 0;
	ind = 0;
	max = -2147483648;
	while (i < b->size)
	{
		if (b->stack[i] > max)
		{
			max = b->stack[i];
			ind = i;
		}
		++i;
	}
	return (ind);
}

int	which_index(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == num)
			return (i);
		++i;
	}
	return (0);
}

int	find_max_index_with_upper_bound(t_stack *stack, int upper)
{
	int	i;
	int	max;
	int	max_ind;

	i = 0;
	max = -2147483648;
	while (i < stack->size)
	{
		if (stack->stack[i] < upper && stack->stack[i] > max)
		{
			max = stack->stack[i];
			max_ind = i;
		}
		++i;
	}
	if (max == -2147483648)
		return (find_max_index(stack));
	return (max_ind);
}

int	find_min_index_with_lower_bound(t_stack *stack, int lower)
{
	int	i;
	int	min;
	int	min_ind;

	i = 0;
	min = 2147483647;
	while (i < stack->size)
	{
		if (stack->stack[i] > lower && stack->stack[i] < min)
		{
			min = stack->stack[i];
			min_ind = i;
		}
		++i;
	}
	if (min == 2147483647)
		return (find_min_index(stack));
	return (min_ind);
}
