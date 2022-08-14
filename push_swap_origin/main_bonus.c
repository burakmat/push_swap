/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:49:18 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 18:49:21 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_same(char *str1, char *str2)
{
	int	i;

	if (!str1 || !(*str1))
		return (0);
	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		++i;
	}
	return (1);
}

void	choose_function(char *str, t_stack *a, t_stack *b)
{
	if (are_same(str, "sa\n"))
		swap_checker(a);
	else if (are_same(str, "sb\n"))
		swap_checker(b);
	else if (are_same(str, "ss\n"))
		double_swap_checker(a, b);
	else if (are_same(str, "pa\n"))
		push_checker(a, b);
	else if (are_same(str, "pb\n"))
		push_checker(b, a);
	else if (are_same(str, "ra\n"))
		rotate_checker(a);
	else if (are_same(str, "rb\n"))
		rotate_checker(b);
	else if (are_same(str, "rr\n"))
		double_rotate_checker(a, b);
	else if (are_same(str, "rra\n"))
		reverse_rotate_checker(a);
	else if (are_same(str, "rrb\n"))
		reverse_rotate_checker(b);
	else if (are_same(str, "rrr\n"))
		double_reverse_rotate_checker(a, b);
	else
		free_and_terminate(a, b);
}

void	check_return_val(t_stack *a, t_stack *b, int return_val, char *str)
{
	if (return_val == -1)
		free_and_terminate(a, b);
	else if (return_val)
	{
		str[return_val] = '\0';
		choose_function(str, a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	str[5];
	int		return_val;

	if (ac > 1)
	{
		check_input(++av);
		create_stack(av, get_total_size(av), &a, &b);
		return_val = 1;
		while (return_val > 0)
		{
			return_val = read(0, str, 5);
			check_return_val(&a, &b, return_val, str);
		}
		if (is_sorted(&a) && !b.size)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}
