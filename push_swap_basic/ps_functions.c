#include "lib.h"

void append_stack(t_stack *stack, int num)
{
	int *new_stack;
	int i;

	new_stack = malloc(sizeof(int) * (stack->size + 1));
	i = 0;
	while (i < stack->size)
	{
		new_stack[i + 1] = stack->stack[i];
		++i;
	}
	new_stack[0] = num;
	free(stack->stack);
	stack->stack = new_stack;
	stack->size += 1;
}

void shrink_stack(t_stack *stack)
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

void swap(t_stack *stack)
{
	int tmp;

	tmp = stack->stack[1];
	stack->stack[1] = stack->stack[0];
	stack->stack[0] = tmp;
}

void double_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void push(t_stack *to, t_stack *from)
{
	append_stack(to, from->stack[0]);
	shrink_stack(from);
}

void rotate(t_stack *stack)
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
}

void double_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void reverse_rotate(t_stack *stack)
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
}

void double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}