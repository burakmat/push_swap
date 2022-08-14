/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:42:28 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:42:30 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isspace(int c)
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
