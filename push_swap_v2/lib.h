#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef PUSH_H
#define PUSH_H

typedef struct s_stack
{
	int *stack;
	int size;
	char name;
}		t_stack;

//utils
int	wordnum(const char *s);
int	ft_isdigit(int c);
int ft_isspace(int c);
int	ft_isalnum(int c);
int	ft_atoi(const char *str, int *ptr);
void check_double(int *ptr, int i, int ind);
void terminate();
void free_and_terminate(t_stack *a, t_stack *b);
int find_max(t_stack *stack);
int abs_val(int num);

//ps_functions
void swap(t_stack *stack, int single);
void double_swap(t_stack *a, t_stack *b);
void push(t_stack *to, t_stack *from);
void rotate(t_stack *stack, int single);
void double_rotate(t_stack *a, t_stack *b);
void reverse_rotate(t_stack *stack, int single);
void double_reverse_rotate(t_stack *a, t_stack *b);

//sort_utils
int is_sorted(t_stack *stack);
int find_max_index(t_stack *b);
int find_min_index(t_stack *b);
int which_index(t_stack *stack, int num);
int find_max_index_with_upper_bound(t_stack *stack, int upper);
int find_min_index_with_lower_bound(t_stack *stack, int lower);
void set_min_base(t_stack *a);
void set_max_base(t_stack *b);

//apply
void apply_one(t_stack *a, t_stack *b, int a_step_num, int b_step_num);
void apply_two(t_stack *a, t_stack *b, int a_step_num, int b_step_num);
void apply_three(t_stack *a, t_stack *b, int a_step_num, int b_step_num);
void apply_four(t_stack *a, t_stack *b, int a_step_num, int b_step_num);

//wheel_sort
int step_to_get_num_top_rev_rotate(int index, int size);
void send_data_to_b(t_stack *a, t_stack *b, int min_apply, int a_index, int b_index);
int find_best_way_to_send_a_data(t_stack *a, t_stack *b, int i, int *which_to_apply);
int find_total_step(int first_stack_step, int second_stack_step);
int find_step_num(int size, int index, int apply, char name);
int find_rr_num(int first_stack_step, int second_stack_step);
void get_sorted(t_stack *a, t_stack *b);
int second_stack_rev_rotate_step(t_stack *b, int num);

//short_sort
void find_and_send_best_data_short(t_stack *a, t_stack *b);
void sort_short(t_stack *a, t_stack *b);

//main_sort
void sort_three(t_stack *stack);
void sort(t_stack *a, t_stack *b);

//main
void unnecessary_function(t_stack *obj, t_stack *b);

#endif