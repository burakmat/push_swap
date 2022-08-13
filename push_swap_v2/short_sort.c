#include "lib.h"

void send_next_data_to_a(t_stack *a, t_stack *b)
{
	int ind;

	ind = find_min_index_with_lower_bound(a, b->stack[0]);
	if (ind <= (a->size / 2))
	{
		while (ind--)
			rotate(a, 1);
	}
	else
	{
		while (a->size - ind++)
			reverse_rotate(a, 1);
	}
	push(a, b);
}

void sort_short(t_stack *a, t_stack *b)
{
	while (a->size != 3)
		push(b, a);
	sort_three(a);
	while (b->size)
		send_next_data_to_a(a, b);
	set_min_base(a);
}