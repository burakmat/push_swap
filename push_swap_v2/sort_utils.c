#include "lib.h"

int is_sorted(t_stack *stack)
{
	int i;

	if (stack->size == 1 || stack->size == 0)
		return (1);
	if (stack->stack[0] < stack->stack[stack->size - 1])
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
	ind = 0;
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

int which_index(t_stack *stack, int num)
//returns the given number's index in stack
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == num)
			return (i);
		++i;
	}
	return (0);
}

int find_max_index_with_upper_bound(t_stack *stack, int upper)
//returns the max number's index that lower than upper bound in a stack
{
	int i;
	int max;
	int max_ind;

	i = 0;
	max = -2147483648;
	while (i < stack->size)
	{
		if (stack->stack[i] < upper && stack->stack[i] > max)
		{
			max = stack->stack[i];
			max_ind = i;
		}
		++i;
	}
	if (max == -2147483648)
		return (find_max_index(stack));
	return max_ind;
}

int find_min_index_with_lower_bound(t_stack *stack, int lower)
{
	int i;
	int min;
	int min_ind;

	i = 0;
	min = 2147483647;
	while (i < stack->size)
	{
		if (stack->stack[i] > lower && stack->stack[i] < min)
		{
			min = stack->stack[i];
			min_ind = i;
		}
		++i;
	}
	if (min == 2147483647)
		return (find_min_index(stack));
	return min_ind;
}

void set_min_base(t_stack *a)
{
	int min_index;

	min_index = find_min_index(a);
	if (min_index <= (a->size / 2))
	{
		while (min_index--)
			rotate(a, 1);
	}
	else
	{
		while (a->size - min_index++)
			reverse_rotate(a, 1);
	}
}

void set_max_base(t_stack *b)
{
	int max_index;

	max_index = find_max_index(b);
	if (max_index <= b->size / 2)
	{
		while (max_index--)
			rotate(b, 1);
	}
	else
	{
		while (b->size - max_index++)
			reverse_rotate(b, 1);
	}
}
