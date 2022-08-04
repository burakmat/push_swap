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

void reverse(t_stack *stack)
{
	int i;

	i = 1;
	while (i++ < stack->size)
		rotate(stack);
}

int find_min_index(t_stack *b)
{
	int i;
	int min;
	int ind;

	i = 0;
	min = 2147483647;
	while (i < b->size)
	{
		if (b->stack[i] < min)
		{
			min = b->stack[i];
			ind = i;
		}
		++i;
	}
	return (ind);
}

int find_max_index(t_stack *b)
{
	int i;
	int max;
	int ind;

	i = 0;
	max = -2147483648;
	while (i < b->size)
	{
		if (b->stack[i] > max)
		{
			max = b->stack[i];
			ind = i;
		}
		++i;
	}
	return (ind);
}