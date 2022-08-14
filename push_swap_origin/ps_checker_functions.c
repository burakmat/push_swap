/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:17:01 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 20:17:04 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_checker(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack[1];
	stack->stack[1] = stack->stack[0];
	stack->stack[0] = tmp;
}

void	push_checker(t_stack *to, t_stack *from)
{
	append_stack(to, from->stack[0], from);
	shrink_stack(from, to);
}

void	rotate_checker(t_stack *stack)
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
}

void	reverse_rotate_checker(t_stack *stack)
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
}
