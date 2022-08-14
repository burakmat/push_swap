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

#endif