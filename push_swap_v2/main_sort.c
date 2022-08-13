#include "lib.h"

void sort_three(t_stack *stack)
{
	if (stack->stack[0] > stack->stack[1] && stack->stack[1] > stack->stack[2])
	{
		swap(stack, 1);
		reverse_rotate(stack, 1);
	}
	else if (stack->stack[2] > stack->stack[0] && stack->stack[0] > stack->stack[1])
		swap(stack, 1);
	else if (stack->stack[1] > stack->stack[2] && stack->stack[2] > stack->stack[0])
	{
		swap(stack, 1);
		rotate(stack, 1);
	}
	else if (stack->stack[2] > stack->stack[1] && stack->stack[0] > stack->stack[2])
		rotate(stack, 1);
	else if (stack->stack[0] > stack->stack[2] && stack->stack[1] > stack->stack[0])
		reverse_rotate(stack, 1);

}

void sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == 1)
		return ;
	else if (a->size == 2)
		swap(a, 1);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size > 3 && a->size <= 6)
		sort_short(a, b);
	else
		get_sorted(a, b);
}