/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:51:55 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:51:57 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_one(t_stack *a, t_stack *b, int a_step_num, int b_step_num)
{
	int	rr;
	int	other;

	rr = find_rr_num(a_step_num, b_step_num);
	other = a_step_num - b_step_num;
	while (rr--)
		double_rotate(a, b);
	if (other > 0)
	{
		while (other--)
			rotate(a, 1);
	}
	else
	{
		while (other++)
			rotate(b, 1);
	}
}

void	apply_two(t_stack *a, t_stack *b, int a_step_num, int b_step_num)
{
	while (a_step_num--)
		rotate(a, 1);
	while (b_step_num--)
		reverse_rotate(b, 1);
}

void	apply_three(t_stack *a, t_stack *b, int a_step_num, int b_step_num)
{
	while (a_step_num--)
		reverse_rotate(a, 1);
	while (b_step_num--)
		rotate(b, 1);
}

void	apply_four(t_stack *a, t_stack *b, int a_step_num, int b_step_num)
{
	int	rrr;
	int	other;

	rrr = find_rr_num(a_step_num, b_step_num);
	other = a_step_num - b_step_num;
	while (rrr--)
		double_reverse_rotate(a, b);
	if (other > 0)
	{
		while (other--)
			reverse_rotate(a, 1);
	}
	else
	{
		while (other++)
			reverse_rotate(b, 1);
	}
}
