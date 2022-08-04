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

void set_object(t_stack *obj, int size)
{
	obj->stack = malloc(sizeof(int) * size);
	if (!obj->stack)
		terminate();
	obj->size = size;
}

void create_stack(char **av, int size, t_stack *obj)
{
	char *ptr;
	int i;

	set_object(obj, size);
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

//************************************

void unnecessary_function(t_stack *obj, t_stack *b)
{
	int i = 0;

	while (i < obj->size)
	{
		printf("%d\n", obj->stack[i]);
		i++;
	}
	printf("a size: %d\n-------------------------\n", obj->size);
	i = 0;
	while (i < b->size)
	{
		printf("%d\n", b->stack[i]);
		i++;
	}
	printf("b size: %d\n-------------------------\n", b->size);
} 
//************************************


int main(int ac, char **av)
{
	t_stack a;
	t_stack b;

	check_input(++av);
	create_stack(av, get_total_size(av), &a);
	b.size = 0;
	unnecessary_function(&a, &b);
	sort(&a, &b);
	return 0;
}