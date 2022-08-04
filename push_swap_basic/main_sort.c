#include "lib.h"

void sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == -1)
		reverse(a);
	else if (a->size == 3)
		sort_three(a);
	else
		get_sorted(a, b);
}