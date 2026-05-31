#include "queue_linked_list.h"
#include <stdlib.h>


bool enqueue(queue **my_queue, int val) {
    queue_node *new_node = malloc(sizeof(*new_node));
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
    queue_node *dequeued_node = (*my_queue)->head;
    (*my_queue)->head = (*my_queue)->head->next;
    free(dequeued_node);
    if ((*my_queue)->head == NULL) {
        (*my_queue)->tail = NULL; // to avoid our tail pointer dangling.
    }
    return result;
}