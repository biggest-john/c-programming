// ensure to pop all elements to free up all memory used.
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
# define STACK_EMPTY INT_MIN

typedef struct node {
    int val;
    struct node *next;
}node;


bool push(node **my_stack, int val) {
    /* the logic of linking here is backward linking to make the time comp. of pushing O(1) rather than O(n)
       looping everytime to before you can push onto the stack*/
    node *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) return false; // safety net for malloc
    new_node->val = val;
    new_node->next = *my_stack;

    *my_stack = new_node;

    return true;
}

int pop(node **my_stack) {
    if (*my_stack == NULL) return STACK_EMPTY;
    int result = (*my_stack)->val;
    node *popped_add = *my_stack;
    *my_stack = (*my_stack)->next;
    free(popped_add);
    return result;
}

int main() {
    // Initializing to NULL so the 'bottom' of the stack is defined
    node *my_test_stack = NULL;

    printf("--- Pushing Values ---\n");
    for (int i = 10; i <= 50; i += 10) {
        if (push(&my_test_stack, i)) {
            printf("Pushed: %d\n", i);
        }
    }

    printf("\n--- Popping Values (LIFO Order) ---\n");
    // We loop while the stack head is NOT NULL
    while (my_test_stack != NULL) {
        int val = pop(&my_test_stack);
        printf("Popped: %d\n", val);
    }

    // Testing your NULL check in pop
    printf("\n--- Testing Empty Pop ---\n");
    int empty_val = pop(&my_test_stack);
    if (empty_val == false) { // Based on your 'return false' in pop
        printf("Successfully caught empty stack!\n");
    }

    return 0;
}