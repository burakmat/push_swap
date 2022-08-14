/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:58:45 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:58:50 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_next_data_to_a(t_stack *a, t_stack *b)
{
	int	ind;

	ind = find_min_index_with_lower_bound(a, b->stack[0]);
	if (ind <= (a->size / 2))
	{
		while (ind--)
			rotate(a, 1);
	}
	else
	{
		while (a->size - ind++)
			reverse_rotate(a, 1);
	}
	push(a, b);
}

void	send_data_to_b(t_stack *a, t_stack *b, \
int min_apply, int *index)
{
	int	a_step_num;
	int	b_step_num;
	int	steps[2];

	a_step_num = find_step_num(a->size, index[0], min_apply, a->name);
	b_step_num = find_step_num(b->size, index[1], min_apply, b->name);
	steps[0] = a_step_num;
	steps[1] = b_step_num;
	if (a_step_num == 0 || b_step_num == 0)
		handle_zeros(a, b, steps, min_apply);
	else if (min_apply == 1)
		apply_one(a, b, a_step_num, b_step_num);
	else if (min_apply == 2)
		apply_two(a, b, a_step_num, b_step_num);
	else if (min_apply == 3)
		apply_three(a, b, a_step_num, b_step_num);
	else if (min_apply == 4)
		apply_four(a, b, a_step_num, b_step_num);
	push(b, a);
}

void	set_conditions(int tmp, int *min_step, \
int *which_to_apply, int apply_value)
{
	*which_to_apply = apply_value;
	*min_step = tmp;
}

int	find_best_way_to_send_a_data(t_stack *a, t_stack *b, \
int i, int *which_to_apply)
{
	int	min_step;
	int	tmp;

	min_step = 2147483647;
	tmp = find_total_step(step_to_get_num_top_rotate(i), \
	second_stack_rotate_step(b, a->stack[i]));
	if (tmp < min_step)
		set_conditions(tmp, &min_step, \
		which_to_apply, 1);
	tmp = find_total_step(step_to_get_num_top_rotate(i), \
	second_stack_rev_rotate_step(b, a->stack[i]));
	if (tmp < min_step)
		set_conditions(tmp, &min_step, \
		which_to_apply, 2);
	tmp = find_total_step(step_to_get_num_top_rev_rotate(i, a->size), \
	second_stack_rotate_step(b, a->stack[i]));
	if (tmp < min_step)
		set_conditions(tmp, &min_step, \
		which_to_apply, 3);
	tmp = find_total_step(step_to_get_num_top_rev_rotate(i, a->size), \
	second_stack_rev_rotate_step(b, a->stack[i]));
	if (tmp < min_step)
		set_conditions(tmp, &min_step, which_to_apply, 4);
	return (min_step);
}

void	find_and_send_best_data(t_stack *a, t_stack *b)
{
	int	min_step;
	int	i;
	int	apply[2];
	int	tmp;
	int	index[2];

	min_step = 2147483647;
	i = 0;
	while (i < a->size)
	{
		tmp = find_best_way_to_send_a_data(a, b, i, &(apply[0]));
		if (tmp < min_step)
		{
			apply[1] = apply[0];
			min_step = tmp;
			index[0] = i;
		}
		++i;
	}
	index[1] = find_max_index_with_upper_bound(b, a->stack[index[0]]);
	send_data_to_b(a, b, apply[1], index);
}
