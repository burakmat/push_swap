#include "lib.h"

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

int find_max(t_stack *a, int min, int chunk_size)
{
	int i;
	int tmp_min;

	if (min == -2147483648 && min_in_stack(a, chunk_size))
		chunk_size -= 1;
	while (chunk_size--)
	{
		tmp_min = 2147483647;
		i = 0;
		while (i < a->size)
		{
			if (a->stack[i] > min && a->stack[i] < tmp_min)
				tmp_min = a->stack[i];
			++i;
		}
		min = tmp_min;
	}
	return (min);
}








int find_chunk_max(t_stack *stack, int min, int chunk_size)///PROBLEM!!!!
{
	int i;
	int tmp_min;

	tmp_min = 2147483647;
	//printf("chunksize: %d\n", chunk_size);
	while (chunk_size--)
	{
		i = 0;
		while (i < stack->size)
		{
			if (stack->stack[i] >= min && stack->stack[i] < tmp_min)////////////////////
				tmp_min = stack->stack[i];
			++i;
		}
		min = tmp_min;
		printf("tmpmin: %d\n", tmp_min);
	}
	//printf("---%d---\n", min);
	return (min) + 1;
}