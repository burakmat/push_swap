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

int optimal_num_of_chunks(int num)//////////////////////////////
{
	int i;

	i = 0;
	while (i * i < num)
		++i;
	return (--i);
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

//***********************************************************

int min_in_stack(int *stack, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (stack[i++] == -2147483648)
			return (1);
	}
	return (0);
}

int find_chunk_max(t_stack *a, int min, int chunk_size)
{
	int i;
	int tmp_min;

	if (min == -2147483648 && min_in_stack(a->stack, chunk_size))
		chunk_size -= 1;
	while (chunk_size--)
	{
		tmp_min = 2147483647;
		i = 0;
		while (i < a->size)
		{
			if (a->stack[i] > min && a->stack[i] < tmp_min)
				tmp_min = a->stack[i];
			i += 1;
		}
		min = tmp_min;
	}
	return (min);
}

void find_to_send(t_stack *a, t_stack *b, int upper_bound, int lower_bound)
{
	int i;

	i = 0;
	//printf("upper: %d, lower: %d\n", upper_bound, lower_bound);
	while (1)
	{
		if (a->stack[i] <= upper_bound && a->stack[i] >= lower_bound)///////
		{
			//printf("a->stack[i]: %d, i: %d\n", a->stack[i], i);
			while (i--)
			{
				rotate(a);
			}
			push(b, a);
			return ;
		}
		else if (a->stack[a->size - i - 1] <= upper_bound && a->stack[a->size - i - 1] >= lower_bound)///////////
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

void send_next_chunk(t_stack *a, t_stack *b, int chunk_size, int *min)
{
	int upper_bound;

	upper_bound = find_chunk_max(a, *min, chunk_size);
	while (chunk_size-- > 0)
	{
		find_to_send(a, b, upper_bound, (*min) + 1);
	}
	*min = upper_bound;
}

void send_last(t_stack *a, t_stack *b, int lower_bound)
{
	int i;

	i = 0;
	while (1)
	{
		//printf("last push\n");
		if (a->stack[i] > lower_bound)
		{
			while (i--)
			{
				rotate(a);
			}
			push(b, a);
			return ;
		}
		else if (a->stack[a->size - i - 1] > lower_bound)
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

void send_last_chunk(t_stack *a, t_stack *b, int lower_bound, int chunk_size)///////////////num_of_chunks
{
	int i;
	int last_chunk_size;

	i = 0;
	last_chunk_size = chunk_size + (a->size % chunk_size);
	//printf("last_chunk_size: %d\n", last_chunk_size);
	while (last_chunk_size--)
	{
		send_last(a, b, lower_bound);
	}	
}

void get_sorted(t_stack *a, t_stack *b)
{
	int chunk_size;
	int number_of_chunks;
	int min;

	min = -2147483648;
	number_of_chunks = optimal_num_of_chunks(a->size);//may be different after
	chunk_size = a->size / number_of_chunks;
	if (is_sorted(a) == -1)
		reverse(a);
	else if (a->size == 3)
		sort_three(a);
	else
	{
		//printf("chunk_size: %d\n", chunk_size);
		while (number_of_chunks-- > 0)
		{
			if (number_of_chunks)
				send_next_chunk(a, b, chunk_size, &min);
			else
			{
				//printf("entering last\n");
				send_last_chunk(a, b, min, chunk_size);///review num of chunks (last parameter)

			}
			unnecessary_function(a, b);
		}
		
	}
}
