/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:28:40 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:28:44 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac > 1)
	{
		check_input(++av);
		create_stack(av, get_total_size(av), &a, &b);
		sort(&a, &b);
		free(a.stack);
	}
	return (0);
}
