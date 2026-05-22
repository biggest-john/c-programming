#include "queue_linked_list.h"
#include "stack_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /*****************************************************
     *      STACK tests.
     * ****************************************************/
    // Initializing to NULL so the 'bottom' of the stack is defined
    stack_node *my_test_stack = NULL;

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

    /*****************************************************
     *      QUEUE tests.
     * ****************************************************/

    // 1. Initialize the queue structure
    queue *q = malloc(sizeof(queue));
    if (q == NULL) return 1;

    // Crucial: Initialize pointers to NULL to start the "empty" state
    q->head = NULL;
    q->tail = NULL;

    printf("--- Enqueueing Values (FIFO) ---\n");
    for (int i = 1; i <= 5; i++) {
        int val = i * 10;
        if (enqueue(&q, val)) {
            printf("Enqueued: %d\n", val);
        }
    }

    printf("\n--- Queue State After Enqueueing ---\n");
    printf("Head points to: %d\n", q->head->value);
    printf("Tail points to: %d\n", q->tail->value);

    printf("\n--- Dequeueing Values ---\n");
    // We keep dequeueing until we hit our sentinel value QUEUE_EMPTY
    int result;
    while ((result = dequeue(&q)) != QUEUE_EMPTY) {
        printf("Dequeued: %d\n", result);
    }

    // 2. Test the "Dangling Tail" fix
    printf("\n--- Post-Dequeue State ---\n");
    if (q->head == NULL && q->tail == NULL) {
        printf("Success: Head and Tail are both NULL.\n");
    }

    // Clean up the queue structure itself
    free(q);

    return 0;
}