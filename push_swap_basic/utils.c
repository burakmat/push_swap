#include "lib.h"

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
	/* printf("%d\n", num); */
	return (num);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int ft_isspace(int c)
{
    if ((c <= 13 && c >= 9) || c == 32)
        return (1);
    return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

static int	max_value(long n, int *ptr)
{
	if (n > 2147483647 || n < -2147483648)
	{
		free(ptr);
		terminate();
	}
	else
		return (n);
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

int	ft_atoi(const char *str, int *ptr)
{
	long	i;
	long	result;
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

void terminate()
{
	write(2, "Error\n", 6);
	exit(0);
}

int find_max(t_stack *stack)
{
	int i;
	int max;

	max = -2147483647;
	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		++i;
	}
	return max;
}