/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:50:00 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:50:02 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	max = -2147483648;
	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		++i;
	}
	return (max);
}

int	abs_val(int num)
{
	if (num >= 0)
		return (num);
	else
		return (-(num));
}

void	scan_chars(char *ptr)
{
	short	allspace;

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
		else if ((*ptr == '+' || *ptr == '-') && \
		ft_isdigit(*(ptr + 1)) && !ft_isalnum(*(ptr - 1)))
			ptr += 1;
		else
			terminate();
	}
	if (allspace)
		terminate();
}
