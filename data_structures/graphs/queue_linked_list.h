#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

/*I had to define the node and queue struct here, due to the fact that the main file
 *needs to know the fields in the struct before it can use malloc to allocate space,
 *If I had just placed only the signature of the struct, this would make the struct opaque
 */

typedef struct queue_node {
    int value;
    struct queue_node *next;
}queue_node;

typedef struct queue {
    queue_node *head;
    queue_node *tail;
} queue;

bool enqueue(queue **my_queue, int val);
int dequeue(queue **my_queue);

#endif