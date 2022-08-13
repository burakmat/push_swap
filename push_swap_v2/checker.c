#include "lib.h"

void check_input(char **str)
{
	char *ptr;
	short allspace;

	ptr = *str;
	while (ptr)
	{
		allspace = 1;
		while (*ptr)
		{
			if (ft_isdigit(*ptr))
			{
				ptr += 1;
				allspace = 0;
			}
			else if (ft_isspace(*ptr))
				ptr += 1;
			else if ((*ptr == '+' || *ptr == '-') && ft_isdigit(*(ptr + 1)) && !ft_isalnum(*(ptr - 1)))
				ptr += 1;
			else
				terminate();
		}
		if (allspace)
			terminate();
		ptr = *(++str);
	}
}

int get_total_size(char **str)
{
	int i;

	i = 0;
	while (*str)
	{
		i += wordnum(*str);
		++str;
	}
	return (i);
}

void set_object(t_stack *obj, int size, t_stack *b)
{
	obj->stack = malloc(sizeof(int) * size);
	if (!(obj->stack))
		terminate();
	obj->size = size;
	obj->name = 'a';
	b->size = 0;
	b->name = 'b';
}

void create_stack(char **av, int size, t_stack *obj, t_stack *b)
{
	char *ptr;
	int i;

	set_object(obj, size, b);
	i = 0;
	ptr = *av;
	while (ptr)
	{
		while (*ptr)
		{
			while (*ptr && ft_isspace(*ptr))
				++ptr;
			if (!ft_isspace(*ptr))
			{
				obj->stack[i] = ft_atoi(ptr, obj->stack);
				check_double(obj->stack, obj->stack[i], i);
				i++;
			}
			while (*ptr && !ft_isspace(*ptr))
				++ptr;
		}
		ptr = *(++av);
	}
}

//------------------------------------------------------------------------
int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	char arr[5];
	int return_val;

	if (ac > 1)
	{
		check_input(++av);
		create_stack(av, get_total_size(av), &a, &b);
		while (return_val > 0)
		{
			return_val = read(0, arr, 10);
		printf("return val: %d\n", return_val);
		}
		if (return_val == -1)
			write(1, "Error\n", 6);
		free(a.stack);
	}
	return 0;
}