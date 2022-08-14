/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:44:39 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:44:40 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	long		i;
	long long	result;
	long		sign;

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

void	terminate(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_and_terminate(t_stack *a, t_stack *b)
{
	if (a->size)
		free(a->stack);
	if (b->size)
		free(b->stack);
	terminate();
}
