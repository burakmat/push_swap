#include "lib.h"

int is_sorted(t_stack *stack)
{
	int i;

	if (stack->size == 1 || stack->size == 0)
		return (1);
	if (stack->stack[0] > stack->stack[stack->size - 1])
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
	{
		i = 0;
		while (i < stack->size - 1)
		{
			if (stack->stack[i] < stack->stack[i + 1])
				return (0);
			++i;
		}
		return (-1);
	}
}

void reverse(t_stack *stack)
{
	int i;

	i = 1;
	while (i++ < stack->size)
		rotate(stack);
}

//***********************************************************

int find_chunk_max(t_stack *stack, int min, int chunk_size)
{
	int i;
	int tmp_min;

	tmp_min = 2147483647;
	while (chunk_size--)
	{
		i = 0;
		while (i < stack->size)
		{
			if (stack->stack[i] >= min && stack->stack[i] < tmp_min)
				tmp_min = stack->stack[i];
			++i;
		}
		min = tmp_min;
	}
	return (min) + 1;
}

void find_to_send(t_stack *a, t_stack *b, int upper_bound, int lower_bound)
{
	int i;

	i = 0;
	while (1)
	{
		if (a->stack[i] < upper_bound && a->stack[i] >= lower_bound)
		{
			while (i--)
			{
				rotate(a);
			}
			push(b, a);
			return ;
		}
		else if (a->stack[a->size - i - 1] < upper_bound && a->stack[a->size - i - 1] >= lower_bound)
		{
			while (1 + i--)
			{
				reverse_rotate(a);
			}
			push(b, a);
			return ;
		}
		++i;
	}
}

void send_next_chunk(t_stack *a, t_stack *b, int num_of_chunk, int chunk_size, int *min)
{
	int upper_bound;

	upper_bound = find_chunk_max(a, *min, chunk_size);
	while (chunk_size-- > 0)
	{
		find_to_send(a, b, upper_bound, *min);
	}
	*min = upper_bound;
}

void send_last(t_stack *a, t_stack *b, int lower_bound)
{
	int i;

	i = 0;
	while (1)
	{
		if (a->stack[i] >= lower_bound)
		{
			while (i--)
			{
				rotate(a);
			}
			push(b, a);
			return ;
		}
		else if (a->stack[a->size - i - 1] >= lower_bound)
		{
			while (1 + i--)
			{
				reverse_rotate(a);
			}
			push(b, a);
			return ;
		}
		++i;
	}
}

void send_last_chunk(t_stack *a, t_stack *b, int lower_bound, int chunk_size, int num_of_chunks)
{
	int i;
	int last_chunk_size;

	i = 0;
	last_chunk_size = chunk_size + (a->size % num_of_chunks);
	while (last_chunk_size--)
	{
		send_last(a, b, lower_bound);
	}	
}

void sort_three(t_stack *stack)
{
	if (stack->stack[0] > stack->stack[1] && stack->stack[1] > stack->stack[2])
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if (stack->stack[2] > stack->stack[0] && stack->stack[0] > stack->stack[1])
		swap(stack);
	else if (stack->stack[1] > stack->stack[2] && stack->stack[2] > stack->stack[0])
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->stack[2] > stack->stack[1] && stack->stack[0] > stack->stack[2])
		rotate(stack);
	else if (stack->stack[0] > stack->stack[2] && stack->stack[1] > stack->stack[0])
		reverse_rotate(stack);

}

void get_sorted(t_stack *a, t_stack *b)
{
	int chunk_size;
	int number_of_chunks;
	int min;

	min = -2147483648;
	number_of_chunks = 3;
	chunk_size = a->size / number_of_chunks;
	if (is_sorted(a) == -1)
		reverse(a);
	else if (a->size == 3)
		sort_three(a);
	else
	{
		while (number_of_chunks-- > 0)
		{
			if (number_of_chunks)
				send_next_chunk(a, b, number_of_chunks, chunk_size, &min);
			else
				send_last_chunk(a, b, min, chunk_size, 3);///review num of chunks (last parameter)
		}
		
	}
}
