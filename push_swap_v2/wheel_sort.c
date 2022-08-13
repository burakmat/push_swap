#include "lib.h"

int step_to_get_num_top_rotate(int index)
{
	return index;
}

int step_to_get_num_top_rev_rotate(int index, int size)
{
	return -(size - index);
}

int second_stack_rotate_step(t_stack *b, int num)
{
	return find_max_index_with_upper_bound(b, num);
}

int second_stack_rev_rotate_step(t_stack *b, int num)
{
	return -(b->size - find_max_index_with_upper_bound(b, num));
}

int find_total_step(int first_stack_step, int second_stack_step)
{
	if (!first_stack_step)
		return abs_val(second_stack_step);
	else if (!second_stack_step)
		return abs_val(first_stack_step);
	else if (first_stack_step > 0 && second_stack_step > 0)
	{
		if (first_stack_step < second_stack_step)
			return abs_val(second_stack_step);
		return abs_val(first_stack_step); 
	}
	else if (first_stack_step < 0 && second_stack_step > 0)
		return (second_stack_step - first_stack_step);
	else if (first_stack_step > 0 && second_stack_step < 0)
		return (first_stack_step - second_stack_step);
	else if (first_stack_step < 0 && second_stack_step < 0)
	{
		if (first_stack_step > second_stack_step)
			return abs_val(second_stack_step);
		return abs_val(first_stack_step);
	}
	return (0);
}


int find_rr_num(int first_stack_step, int second_stack_step)
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

int find_rrr_num(int first_stack_step, int second_stack_step)
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

int find_step_num(int size, int index, int apply, char name)
{
	if (name == 'a')
	{
		if (apply == 1 || apply == 2)
			return (step_to_get_num_top_rotate(index));
		else if (apply == 3 || apply == 4)
			return -(step_to_get_num_top_rev_rotate(index, size));
	}
	else
	{
		if (apply == 1 || apply == 3)
			return (step_to_get_num_top_rotate(index));
		else if (apply == 2 || apply == 4)
			return -(step_to_get_num_top_rev_rotate(index, size));
	}
	return (0);
}

void handle_zeros(t_stack *a, t_stack *b, int a_step_num, int b_step_num, int apply_case)
{
	if (a_step_num == 0 && b_step_num == 0)
		return ;
	else if (a_step_num == 0 && (apply_case == 1 || apply_case == 3))
	{	
		while (b_step_num--)
			rotate(b, 1);
	}
	else if (a_step_num == 0 && (apply_case == 2 || apply_case == 4))
	{
		while (b_step_num--)
			reverse_rotate(b, 1);
	}
	else if (b_step_num == 0 && (apply_case == 1 || apply_case == 2))
	{
		while (a_step_num--)
			rotate(a, 1);
	}
	else if (b_step_num == 0 && (apply_case == 3 || apply_case == 4))
	{
		while (a_step_num--)
			reverse_rotate(a, 1);
	}
}

void send_data_to_b(t_stack *a, t_stack *b, int min_apply, int a_index, int b_index)
{
	int a_step_num;
	int b_step_num;

	a_step_num = find_step_num(a->size, a_index, min_apply, a->name);
	b_step_num = find_step_num(b->size, b_index, min_apply, b->name);
	if (a_step_num == 0 || b_step_num == 0)
		handle_zeros(a, b, a_step_num, b_step_num, min_apply);
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

void set_conditions(int tmp, int *min_step, int *which_to_apply, int apply_value)
{
	*which_to_apply = apply_value;
	*min_step = tmp;
}

int find_best_way_to_send_a_data(t_stack *a, t_stack *b, int i, int *which_to_apply)
{
	int min_step;
	int tmp;

	min_step = 2147483647;
	tmp = find_total_step(step_to_get_num_top_rotate(i), second_stack_rotate_step(b, a->stack[i]));
	if (tmp < min_step)
		set_conditions(tmp, &min_step, which_to_apply, 1);
	tmp = find_total_step(step_to_get_num_top_rotate(i), second_stack_rev_rotate_step(b, a->stack[i]));
	if (tmp < min_step)
		set_conditions(tmp, &min_step, which_to_apply, 2);
	tmp = find_total_step(step_to_get_num_top_rev_rotate(i, a->size), second_stack_rotate_step(b, a->stack[i]));
	if (tmp < min_step)
		set_conditions(tmp, &min_step, which_to_apply, 3);
	tmp = find_total_step(step_to_get_num_top_rev_rotate(i, a->size), second_stack_rev_rotate_step(b, a->stack[i]));
	if (tmp < min_step)
		set_conditions(tmp, &min_step, which_to_apply, 4);
	return min_step;
}

void find_and_send_best_data(t_stack *a, t_stack *b)
{
	int min_step;
	int i;
	int min_step_index;
	int which_to_apply;
	int min_apply;
	int tmp;

	min_step = 2147483647;
	i = 0;
	while (i < a->size)
	{
		tmp = find_best_way_to_send_a_data(a, b, i, &which_to_apply);
		if (tmp < min_step)
		{
			min_apply = which_to_apply;
			min_step = tmp;
			min_step_index = i;
		}
		++i;
	}
	send_data_to_b(a, b, min_apply, min_step_index, find_max_index_with_upper_bound(b, a->stack[min_step_index]));
}

void get_sorted(t_stack *a, t_stack *b)
{
	while (a->size)
		find_and_send_best_data(a, b);
	set_max_base(b);
	while (b->size)
		push(a, b);
}