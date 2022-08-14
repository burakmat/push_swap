/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:42:49 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 15:42:54 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size == 1 || stack->size == 0)
		return (1);
	if (stack->stack[0] < stack->stack[stack->size - 1])
	{
		i = 0;
		while (i < stack->size - 1)
		{
			if (stack->stack[i] > stack->stack[i + 1])
				return (0);
			++i;
		}
		return (1);
	}
	else
		return (0);
}

void	append_stack(t_stack *stack, int num, t_stack *second_stack)
{
	int	*new_stack;
	int	i;

	new_stack = malloc(sizeof(int) * (stack->size + 1));
	if (!new_stack)
		free_and_terminate(stack, second_stack);
	i = 0;
	while (i < stack->size)
	{
		new_stack[i + 1] = stack->stack[i];
		++i;
	}
	new_stack[0] = num;
	if (stack->size)
		free(stack->stack);
	stack->stack = new_stack;
	stack->size += 1;
}

void	shrink_stack(t_stack *stack, t_stack *second_stack)
{
	int	i;
	int	*new_stack;

	if (stack->size == 1)
	{
		free(stack->stack);
		stack->size -= 1;
		return ;
	}
	new_stack = malloc(sizeof(int) * (stack->size - 1));
	if (!new_stack)
		free_and_terminate(stack, second_stack);
	i = 0;
	while (i < stack->size - 1)
	{
		new_stack[i] = stack->stack[i + 1];
		++i;
	}
	free(stack->stack);
	stack->stack = new_stack;
	stack->size -= 1;
}

void	check_double(int *ptr, int i, int ind)
{
	int	n;

	n = 0;
	while (n < ind)
	{
		if (ptr[n++] == i)
		{
			free(ptr);
			terminate();
		}
	}
}
