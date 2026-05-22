// ensure to pop all elements to free up all memory used.
#include <stdlib.h>
#include "stack_linked_list.h"

bool push(stack_node **my_stack, int val) {
    /* the logic of linking here is backward linking to make the time comp. of pushing O(1) rather than O(n)
       looping everytime to before you can push onto the stack*/
    stack_node *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) return false; // safety net for malloc
    new_node->val = val;
    new_node->next = *my_stack;

    *my_stack = new_node;

    return true;
}

int pop(stack_node **my_stack) {
    if (*my_stack == NULL) return STACK_EMPTY;
    int result = (*my_stack)->val;
    stack_node *popped_add = *my_stack;
    *my_stack = (*my_stack)->next;
    free(popped_add);
    return result;
}

