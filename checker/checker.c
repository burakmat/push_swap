#include "lib.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_isspace(int c)
{
    if ((c <= 13 && c >= 9) || c == 32)
        return (1);
    return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

void terminate()
{
	write(2, "Error\n", 6);
	exit(0);
}

void free_and_terminate(t_stack *a, t_stack *b)
{
	if (a->size)
		free(a->stack);
	if (b->size)
		free(b->stack);
	terminate();
}

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

static int	max_value(long long n, int *ptr)
{
	if (n > 2147483647 || n < -2147483648)
	{
		free(ptr);
		terminate();
		return (0);
	}
	else
		return (n);
}

int	ft_atoi(const char *str, int *ptr)
{
	long	i;
	long long	result;
	long	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i++] - '0';
		if (result > 2147483647)
			return (max_value(result * sign, ptr));
	}
	return (result * sign);
}

void check_double(int *ptr, int i, int ind)
{
	int n;

	n = 0;
	while (n < ind)
	{
		if (ptr[n++] == i)
		{
			free(ptr);
			terminate();
		}
	}
}

int	wordnum(const char *s)
{
	int	i;
	int	num;
	int	sp;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] && ((s[i] == 32) || (s[i] <= 13 && s[i] >= 9)))
			i++;
		sp = 1;
		while (s[i] && s[i] != 32 && (s[i] > 13 || s[i] < 9))
		{
			if (sp == 1)
			{
				num++;
				sp = 0;
			}
			i++;
		}
	}
	return (num);
}

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


void swap(t_stack *stack)
{
	int tmp;

	tmp = stack->stack[1];
	stack->stack[1] = stack->stack[0];
	stack->stack[0] = tmp;
}

void push(t_stack *to, t_stack *from)
{
	append_stack(to, from->stack[0], from);
	shrink_stack(from, to);
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

void double_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void double_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

int are_same(char *str1, char *str2)
{
	int i;

	if (!str1 || !(*str1))
		return (0);
	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
		{
	//		printf("i:%d, str1[i]: %c, str2[i]: %c\n", i, str1[i], str2[i]);
			return (0);
		}
		++i;
	}
	return (1);
}

void choose_function(char *str, t_stack *a, t_stack *b)
{
	printf("choosefunc get: %s\n", str);
	if (are_same(str, "sa\n"))
		swap(a);
	else if (are_same(str, "sb\n"))
		swap(b);
	else if (are_same(str, "ss\n"))
		double_swap(a, b);
	else if (are_same(str, "pa\n"))
		push(a, b);
	else if (are_same(str, "pb\n"))
		push(b, a);
	else if (are_same(str, "ra\n"))
		rotate(a);
	else if (are_same(str, "rb\n"))
		rotate(b);
	else if (are_same(str, "rr\n"))
		double_rotate(a, b);
	else if (are_same(str, "rra\n"))
		reverse_rotate(a);
	else if (are_same(str, "rrb\n"))
		reverse_rotate(b);
	else if (are_same(str, "rrr\n"))
		double_reverse_rotate(a, b);
	else
		free_and_terminate(a, b);
}

void unnecessary_function(t_stack *obj, t_stack *b)
{
	int i = 0;

	while (i < obj->size)
	{
		printf("%d\n", obj->stack[i]);
		++i;
	}
	printf("a size: %d\n-------------------------\n", obj->size);
	i = 0;
	while (i < b->size)
	{
		printf("%d\n", b->stack[i]);
		++i;
	}
	printf("b size: %d\n-------------------------\n", b->size);
} 

int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	char str[5];
	int return_val;

	if (ac > 1)
	{
		check_input(++av);
		create_stack(av, get_total_size(av), &a, &b);
		unnecessary_function(&a, &b);
		return_val = 1;
		while (return_val > 0)
		{
			return_val = read(0, str, 5);
			if (return_val == -1)
				free_and_terminate(&a, &b);
			else if (return_val)
			{
			str[return_val] = '\0';
			choose_function(str, &a, &b);
			}
			unnecessary_function(&a, &b);
		}
		if (is_sorted(&a) && !b.size)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return 0;
}