/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:12:51 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 15:12:55 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_total_step(int first_stack_step, int second_stack_step)
{
	if (!first_stack_step)
		return (abs_val(second_stack_step));
	else if (!second_stack_step)
		return (abs_val(first_stack_step));
	else if (first_stack_step > 0 && second_stack_step > 0)
	{
		if (first_stack_step < second_stack_step)
			return (abs_val(second_stack_step));
		return (abs_val(first_stack_step));
	}
	else if (first_stack_step < 0 && second_stack_step > 0)
		return (second_stack_step - first_stack_step);
	else if (first_stack_step > 0 && second_stack_step < 0)
		return (first_stack_step - second_stack_step);
	else if (first_stack_step < 0 && second_stack_step < 0)
	{
		if (first_stack_step > second_stack_step)
			return (abs_val(second_stack_step));
		return (abs_val(first_stack_step));
	}
	return (0);
}

int	find_rr_num(int first_stack_step, int second_stack_step)
{
	if (first_stack_step > 0 && second_stack_step > 0)
	{
		if (first_stack_step > second_stack_step)
			return (second_stack_step);
		else
			return (first_stack_step);
	}
	return (0);
}

int	find_rrr_num(int first_stack_step, int second_stack_step)
{
	if (first_stack_step > 0 && second_stack_step > 0)
	{
		if (first_stack_step > second_stack_step)
			return (second_stack_step);
		else
			return (first_stack_step);
	}
	return (0);
}

int	find_step_num(int size, int index, int apply, char name)
{
	if (name == 'a')
	{
		if (apply == 1 || apply == 2)
			return (step_to_get_num_top_rotate(index));
		else if (apply == 3 || apply == 4)
			return (-(step_to_get_num_top_rev_rotate(index, size)));
	}
	else
	{
		if (apply == 1 || apply == 3)
			return (step_to_get_num_top_rotate(index));
		else if (apply == 2 || apply == 4)
			return (-(step_to_get_num_top_rev_rotate(index, size)));
	}
	return (0);
}

void	handle_zeros(t_stack *a, t_stack *b, int *steps, int apply_case)
{
	if (steps[0] == 0 && steps[1] == 0)
		return ;
	else if (steps[0] == 0 && (apply_case == 1 || apply_case == 3))
	{	
		while (steps[1]--)
			rotate(b, 1);
	}
	else if (steps[0] == 0 && (apply_case == 2 || apply_case == 4))
	{
		while (steps[1]--)
			reverse_rotate(b, 1);
	}
	else if (steps[1] == 0 && (apply_case == 1 || apply_case == 2))
	{
		while (steps[0]--)
			rotate(a, 1);
	}
	else if (steps[1] == 0 && (apply_case == 3 || apply_case == 4))
	{
		while (steps[0]--)
			reverse_rotate(a, 1);
	}
}
