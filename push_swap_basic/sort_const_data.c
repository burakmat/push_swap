#include "lib.h"

int median(t_stack *stack)
//returns mid value, lower one if there are even num of data
{
	int med;
	int tmp_min;
	int min_num;
	int i;

	min_num = stack->size / 2;
	if (min_in_stack(stack->stack, stack->size))
		--min_num;
	med = -2147483648;
	while (min_num--)
	{
		i = 0;
		tmp_min = 2147483647;
		while (i < stack->size)
		{
			if (stack->stack[i] < tmp_min && stack->stack[i] > med)
				tmp_min = stack->stack[i];
			++i;
		}
		med = tmp_min;
	}
	return (med);
}

int determine_condition(t_stack *b, int i, int max_ind, int min_ind)
{
	if (i == max_ind || i == min_ind)
	{	
		if (i == max_ind)
			return 1;
		else if (i == min_ind)
			return 0;
	}
	else if (b->size - i - 1 == max_ind || b->size - i - 1 == min_ind)
	{
		if (b->size - i - 1 == max_ind)
			return 1;
		else if (b->size - i - 1 == min_ind)
			return 0;
	}
	return (0);
}

int send_next_data_from_b(t_stack *b, t_stack *a, int max_ind, int min_ind)
{
	int i;
	int return_value;

	i = 0;
	while (1)
	{
		if (i == max_ind || i == min_ind)
		{
			return_value = determine_condition(b, i, max_ind, min_ind);
			while (i--)
				rotate(b);
			push(a, b);
			return return_value;
		}
		else if (b->size - i - 1 == max_ind || b->size - i - 1 == min_ind)
		{
			return_value = determine_condition(b, i, max_ind, min_ind);
			while (1 + i--)
				reverse_rotate(b);
			push(a, b);
			return return_value;
		}
		++i;
	}
}

void send_all_data_to_a(t_stack *b, t_stack *a)
{
	int med;
	int position;

	med = median(b);
	while (b->size)
	{
		position = send_next_data_from_b(b, a, find_max_index(b), find_min_index(b));
		if (!position)
			rotate(a);
	}
}

void set_min_to_base(t_stack *a, int max, t_stack *b)
{
	int min_ind;

	unnecessary_function(a, b);
	min_ind = which_index(a, max);
	if (a->size - min_ind - 1 <= min_ind)
	{
		while (a->size - 1 - min_ind++)
			reverse_rotate(a);
	}
	else
	{
		while (1 + min_ind--)
			rotate(a);
	}
}

void organize_main_stack(t_stack *a ,int min, t_stack *b)
{
	static int chunk_number;
	static int last_min;

	if (chunk_number)
		set_min_to_base(a, last_min, b);
	last_min = min;
	++chunk_number;
}