#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
}node;

typedef struct queue {
    node *head;
    node *tail;
}queue;

bool enqueue(queue **my_queue, int val) {
    node *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) return false;

    new_node->value = val;
    new_node->next = NULL;

    if ((*my_queue)->tail != NULL) {
        (*my_queue)->tail->next = new_node;
    }
    (*my_queue)->tail = new_node; // moving the tail pointer to point to the newly enqueued node.
    if ((*my_queue)->head == NULL) {
        (*my_queue)->head = new_node;
    }

    return true;
}
int dequeue(queue **my_queue) {
    if ((*my_queue)->head == NULL) return QUEUE_EMPTY;
    int result = (*my_queue)->head->value;
    node *dequeued_node = (*my_queue)->head;
    (*my_queue)->head = (*my_queue)->head->next;
    free(dequeued_node);
    if ((*my_queue)->head == NULL) {
        (*my_queue)->tail = NULL; // to avoid our tail pointer dangling.
    }
    return result;
}

int main() {
    // prompted Gemini to generate the code in the main function for testing the enqueue and dequeue

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