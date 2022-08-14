/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_double_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:21:00 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 20:21:02 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap_checker(t_stack *a, t_stack *b)
{
	swap_checker(a);
	swap_checker(b);
}

void	double_rotate_checker(t_stack *a, t_stack *b)
{
	rotate_checker(a);
	rotate_checker(b);
}

void	double_reverse_rotate_checker(t_stack *a, t_stack *b)
{
	reverse_rotate_checker(a);
	reverse_rotate_checker(b);
}
