#include "lib.h"

int median(t_stack *stack)
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

void send_next_data_from_b(t_stack *b, t_stack *a)
{
	int max_ind;
	int min_ind;
	int i;

	i = 0;
	max_ind = find_max_index(b);
	min_ind = find_min_index(b);
	while (1)
	{
		if (i == max_ind || i == min_ind)
		{	
			while (i--)
				rotate(b);
			push(a, b);
			return ;
		}
		else if (b->size - i - 1 == max_ind || b->size - i - 1 == min_ind)
		{
			while (1 + i--)
				reverse_rotate(b);
			push(a, b);
			return ;
		}
		++i;
	}
}