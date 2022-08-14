/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:53:47 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:53:49 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->stack[0] > stack->stack[1] \
	&& stack->stack[1] > stack->stack[2])
	{
		swap(stack, 1);
		reverse_rotate(stack, 1);
	}
	else if (stack->stack[2] > stack->stack[0] \
	&& stack->stack[0] > stack->stack[1])
		swap(stack, 1);
	else if (stack->stack[1] > stack->stack[2] \
	&& stack->stack[2] > stack->stack[0])
	{
		swap(stack, 1);
		rotate(stack, 1);
	}
	else if (stack->stack[2] > stack->stack[1] \
	&& stack->stack[0] > stack->stack[2])
		rotate(stack, 1);
	else if (stack->stack[0] > stack->stack[2] \
	&& stack->stack[1] > stack->stack[0])
		reverse_rotate(stack, 1);
}

void	sort_short(t_stack *a, t_stack *b)
{
	while (a->size != 3)
		push(b, a);
	sort_three(a);
	while (b->size)
		send_next_data_to_a(a, b);
	set_min_base(a);
}

void	get_sorted(t_stack *a, t_stack *b)
{
	while (a->size)
		find_and_send_best_data(a, b);
	set_max_base(b);
	while (b->size)
		push(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == 1)
		return ;
	else if (a->size == 2)
		swap(a, 1);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size > 3 && a->size <= 6)
		sort_short(a, b);
	else
		get_sorted(a, b);
}
