#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <limits.h>

# define STACK_EMPTY INT_MIN


typedef struct stack_node {
    int val;
    struct stack_node *next;
}stack_node;
bool push(stack_node **my_stack, int val);
int pop(stack_node **my_stack);


#endif