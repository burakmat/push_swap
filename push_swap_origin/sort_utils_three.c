/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:17:22 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 15:17:24 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	step_to_get_num_top_rotate(int index)
{
	return (index);
}

int	step_to_get_num_top_rev_rotate(int index, int size)
{
	return (-(size - index));
}

int	second_stack_rotate_step(t_stack *b, int num)
{
	return (find_max_index_with_upper_bound(b, num));
}

int	second_stack_rev_rotate_step(t_stack *b, int num)
{
	return (-(b->size - find_max_index_with_upper_bound(b, num)));
}
