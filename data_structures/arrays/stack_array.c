#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGHT 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN // would use this to rep. lowest possible value to signify bottom of stack

typedef struct stack {
    int values[STACK_LENGHT];
    int top; // to track the top element in the stack
} stack;


bool push(stack* my_stack, int val) {
    if (my_stack->top >= STACK_LENGHT-1) return false;

    my_stack->values[++(my_stack->top)] = val; // be mindful of pre-increment.
    return true;
}

int pop(stack *my_stack) {
    // 0 reps. popped elements
    if (my_stack->top == EMPTY) return STACK_EMPTY;
    int result = my_stack->values[my_stack->top];
    my_stack->values[my_stack->top] = 0; // setting to zero tot rep. popped elements.
    (my_stack->top)--;
    return result; // bad readability, but why not.

}

int main () {
    // gave gemini the task of generating code to test out the push and pop implementation.
    // 1. Instantiate the stack
    stack s1;

    // 2. Initialize the stack top to EMPTY (-1)
    // In an array-based stack, this is the equivalent of setting a pointer to NULL
    s1.top = EMPTY;

    printf("--- Pushing to Array Stack ---\n");
    for (int i = 0; i < 7; i++) {
        int val_to_push = (i + 1) * 5;
        if (push(&s1, val_to_push)) {
            printf("Pushed %d. Current top index: %d\n", val_to_push, s1.top);
        } else {
            printf("Failed to push %d: Stack Overflow!\n", val_to_push);
        }
    }

    printf("\n--- Popping from Array Stack ---\n");
    // We keep popping until the pop function returns our STACK_EMPTY sentinel
    int popped_val;
    while ((popped_val = pop(&s1)) != STACK_EMPTY) {
        printf("Popped %d. New top index: %d\n", popped_val, s1.top);
    }

    // Double check if it's actually empty
    if (pop(&s1) == STACK_EMPTY) {
        printf("\nConfirmed: Stack is empty.\n");
    }

    return 0;
}

