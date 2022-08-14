/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:21:58 by bmat              #+#    #+#             */
/*   Updated: 2022/08/14 14:22:00 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct second_stack_rev_rotate_step
{
	int		*stack;
	int		size;
	char	name;
}			t_stack;

void	check_input(char **str);
int		get_total_size(char **str);
void	set_object(t_stack *obj, int size, t_stack *b);
void	create_stack(char **av, int size, t_stack *obj, t_stack *b);
int		wordnum(const char *s);
int		ft_isalpha(int c);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
void	check_double(int *ptr, int i, int ind);
int		ft_atoi(const char *str, int *ptr);
void	terminate(void);
void	free_and_terminate(t_stack *a, t_stack *b);
int		find_max(t_stack *stack);
int		abs_val(int num);
void	scan_chars(char *ptr);
void	swap(t_stack *stack, int single);
void	push(t_stack *to, t_stack *from);
void	rotate(t_stack *stack, int single);
void	reverse_rotate(t_stack *stack, int single);
void	double_swap(t_stack *a, t_stack *b);
void	double_rotate(t_stack *a, t_stack *b);
void	double_reverse_rotate(t_stack *a, t_stack *b);
void	apply_one(t_stack *a, t_stack *b, int a_step_num, int b_step_num);
void	apply_two(t_stack *a, t_stack *b, int a_step_num, int b_step_num);
void	apply_three(t_stack *a, t_stack *b, int a_step_num, int b_step_num);
void	apply_four(t_stack *a, t_stack *b, int a_step_num, int b_step_num);
void	sort_three(t_stack *stack);
void	sort_short(t_stack *a, t_stack *b);
void	get_sorted(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
void	send_next_data_to_a(t_stack *a, t_stack *b);
void	send_data_to_b(t_stack *a, t_stack *b, int min_apply, int *index);
void	set_conditions(int tmp, int *min_step, int *which_to_apply, \
int apply_value);
int		find_best_way_to_send_a_data(t_stack *a, t_stack *b, int i, \
int *which_to_apply);
void	find_and_send_best_data(t_stack *a, t_stack *b);
int		find_total_step(int first_stack_step, int second_stack_step);
int		find_rr_num(int first_stack_step, int second_stack_step);
int		find_rrr_num(int first_stack_step, int second_stack_step);
int		find_step_num(int size, int index, int apply, char name);
void	handle_zeros(t_stack *a, t_stack *b, int *steps, int apply_case);
int		step_to_get_num_top_rotate(int index);
int		step_to_get_num_top_rev_rotate(int index, int size);
int		second_stack_rotate_step(t_stack *b, int num);
int		second_stack_rev_rotate_step(t_stack *b, int num);
int		is_sorted(t_stack *stack);
int		find_min_index(t_stack *b);
int		find_max_index(t_stack *b);
int		which_index(t_stack *stack, int num);
int		find_max_index_with_upper_bound(t_stack *stack, int upper);
int		find_min_index_with_lower_bound(t_stack *stack, int lower);
void	set_min_base(t_stack *a);
void	set_max_base(t_stack *b);
void	append_stack(t_stack *stack, int num, t_stack *second_stack);
void	shrink_stack(t_stack *stack, t_stack *second_stack);
void	swap_checker(t_stack *stack);
void	push_checker(t_stack *to, t_stack *from);
void	rotate_checker(t_stack *stack);
void	reverse_rotate_checker(t_stack *stack);
void	double_swap_checker(t_stack *a, t_stack *b);
void	double_rotate_checker(t_stack *a, t_stack *b);
void	double_reverse_rotate_checker(t_stack *a, t_stack *b);

#endif