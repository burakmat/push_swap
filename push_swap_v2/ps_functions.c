#include "lib.h"

void append_stack(t_stack *stack, int num, t_stack *second_stack)
{
	int *new_stack;
	int i;

	new_stack = malloc(sizeof(int) * (stack->size + 1));
	if (!new_stack)
		free_and_terminate(stack, second_stack);
	i = 0;
	while (i < stack->size)
	{
		new_stack[i + 1] = stack->stack[i];
		++i;
	}
	new_stack[0] = num;
	if (stack->size)
		free(stack->stack);
	stack->stack = new_stack;
	stack->size += 1;
}

void shrink_stack(t_stack *stack, t_stack *second_stack)
{
	int i;
	int *new_stack;

	if (stack->size == 1)
	{
		free(stack->stack);
		stack->size -= 1;
		return ;
	}
	new_stack = malloc(sizeof(int) * (stack->size - 1));
	if (!new_stack)
		free_and_terminate(stack, second_stack);
	i = 0;
	while (i < stack->size - 1)
	{
		new_stack[i] = stack->stack[i + 1];
		++i;
	}
	free(stack->stack);
	stack->stack = new_stack;
	stack->size -= 1;
}

//**************************************

void swap(t_stack *stack, int single)
{
	int tmp;

	tmp = stack->stack[1];
	stack->stack[1] = stack->stack[0];
	stack->stack[0] = tmp;
	if (single)
	{
		write(1, "s", 1);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
}

void push(t_stack *to, t_stack *from)
{
	append_stack(to, from->stack[0], from);
	shrink_stack(from, to);
	write(1, "p", 1);
	write(1, &(to->name), 1);
	write(1, "\n", 1);
}

void rotate(t_stack *stack, int single)
{
	int tmp;
	int i;

	tmp = stack->stack[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		++i;
	}
	stack->stack[i] = tmp;
	if (single)
	{
		write(1, "r", 1);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
}


void reverse_rotate(t_stack *stack, int single)
{
	int tmp;
	int i;

	i = stack->size - 1;
	tmp = stack->stack[i];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		--i;
	}
	stack->stack[i] = tmp;
	if (single)
	{
		write(1, "rr", 2);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
}

void double_swap(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}

void double_rotate(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
}