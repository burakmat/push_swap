#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef PUSH_H
#define PUSH_H

typedef struct s_stack
{

	int *stack;
	int size;

}		t_stack;

//utils
int	wordnum(const char *s);
int	ft_isdigit(int c);
int ft_isspace(int c);
int	ft_isalnum(int c);
int	ft_atoi(const char *str, int *ptr);
void check_double(int *ptr, int i, int ind);
void terminate();

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

//sort_utils
int find_max_index(t_stack *b);
int find_min_index(t_stack *b);

//main_sort
void sort(t_stack *a, t_stack *b);

//main
void unnecessary_function(t_stack *obj, t_stack *b);

#endif