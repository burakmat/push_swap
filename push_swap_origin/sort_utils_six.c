/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:08:50 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 21:08:52 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_base(t_stack *a)
{
	int	min_index;

	min_index = find_min_index(a);
	if (min_index <= (a->size / 2))
	{
		while (min_index--)
			rotate(a, 1);
	}
	else
	{
		while (a->size - min_index++)
			reverse_rotate(a, 1);
	}
}

void	set_max_base(t_stack *b)
{
	int	max_index;

	max_index = find_max_index(b);
	if (max_index <= b->size / 2)
	{
		while (max_index--)
			rotate(b, 1);
	}
	else
	{
		while (b->size - max_index++)
			reverse_rotate(b, 1);
	}
}
