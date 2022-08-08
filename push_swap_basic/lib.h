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
int find_max(t_stack *stack);

//ps_functions
void swap(t_stack *stack);
void double_swap(t_stack *a, t_stack *b);
void push(t_stack *to, t_stack *from);
void rotate(t_stack *stack);
void double_rotate(t_stack *a, t_stack *b);
void reverse_rotate(t_stack *stack);
void double_reverse_rotate(t_stack *a, t_stack *b);

//send_chunks
int is_sorted(t_stack *stack);
int min_in_stack(int *stack, int size);
void get_sorted(t_stack *a, t_stack *b);

//sort_const_data
int send_next_data_from_b(t_stack *b, t_stack *a, int max_ind, int min_ind);
void send_all_data_to_a(t_stack *b, t_stack *a);
void set_min_to_base(t_stack *a, int max, t_stack *b);
void organize_main_stack(t_stack *a ,int min, t_stack *b);

//sort_utils
int find_max_index(t_stack *b);
int find_min_index(t_stack *b);
int which_index(t_stack *stack, int num);
void sort_three(t_stack *stack);
void reverse(t_stack *stack);

//main_sort
void sort(t_stack *a, t_stack *b);

//main
void unnecessary_function(t_stack *obj, t_stack *b);

#endif