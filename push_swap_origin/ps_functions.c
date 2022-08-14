/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:37:55 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:37:57 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int single)
{
	int	tmp;

	tmp = stack->stack[1];
	stack->stack[1] = stack->stack[0];
	stack->stack[0] = tmp;
	if (single)
	{
		write(1, "s", 1);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack *to, t_stack *from)
{
	append_stack(to, from->stack[0], from);
	shrink_stack(from, to);
	write(1, "p", 1);
	write(1, &(to->name), 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, int single)
{
	int	tmp;
	int	i;

	tmp = stack->stack[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		++i;
	}
	stack->stack[i] = tmp;
	if (single)
	{
		write(1, "r", 1);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_stack *stack, int single)
{
	int	tmp;
	int	i;

	i = stack->size - 1;
	tmp = stack->stack[i];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		--i;
	}
	stack->stack[i] = tmp;
	if (single)
	{
		write(1, "rr", 2);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
}
