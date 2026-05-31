#include "graph_adj_list.h"
#include <stdio.h>
#include <stdlib.h>
#include "../queue_linked_list.h"
#include "../stack_linked_list.h"

typedef struct graph_node { /*this would be the linked list of nodes that have a connection the head
    would be the originator*/
    int vertex_num;
    struct graph_node *next;
}graph_node;

// leaving the list struct, incase I wish to add more info i.e. degree of the head node.
typedef struct list { // this would store the head node of each of the linked lists
    graph_node *head;
}list;

list** create_graph(int nodes) {
    list **my_graph = malloc(sizeof(list*) * nodes);

    for (int i = 0; i < nodes; i++) {
        my_graph[i] = malloc(sizeof(list));
        if (my_graph[i] == NULL) {
            // Clean up everything allocated so far to prevent leaks
            for (int j = 0; j < i; j++) free(my_graph[j]);
            free(my_graph);
            return NULL;
        }; // Safety check
        my_graph[i]->head = NULL;          // Ensure the "bottom" of the neighbor list is NULL
    }
    return my_graph;
}

bool add_node(list **adj_list, int s, int d) {
    //for an undirected graph, you would actually have to link it in two ways not one.
    graph_node *dst = malloc(sizeof(*dst));
    if (dst == NULL) return false; // Safety check

    dst->vertex_num = d;
    dst->next= adj_list[s]->head;

    adj_list[s]->head = dst;
    return true;
}

void print_graph(list **adj_list, int nodes) {
    //this function gets piped into the viz program to help visualize the graph.
    printf("digraph{\n");
    for (int from=0; from<nodes;from++) {
        graph_node *current_ll_node = adj_list[from]->head;
        while (current_ll_node) {
            printf("%i -> %i\n", from, current_ll_node->vertex_num );
            current_ll_node = current_ll_node->next;
        }
    }
    printf("}\n");
}

void destroy_graph(list **adj_list, int nodes) {
    for (int i=0; i<nodes;i++) {
        while (adj_list[i]->head) {
            graph_node *temp = adj_list[i]->head;
            adj_list[i]->head = temp->next;
            free(temp);
        }
        free(adj_list[i]);
    }
    free(adj_list);
}

void dfs_iterative(list **adj_list, int num_nodes ,int start_node) {
    // the self-implemented stack being used here is a struct that has a value field and a pointer to the
    // next node in the stack
    bool *visited = malloc(sizeof(bool) * num_nodes);
    for (int i = 0; i < num_nodes;i++) {
        visited[i] = false;
    }
    stack_node *s = NULL;

    push(&s, start_node);

    while (s != NULL) {
        int current = pop(&s);

        if (!visited[current]) {
            fprintf(stderr,"Visited: %d\n", current);
            visited[current] = true;

            // Add neighbors to stack
            graph_node *neighbor = adj_list[current]->head;
            while (neighbor) {
                if (!visited[neighbor->vertex_num]) {
                    push(&s, neighbor->vertex_num);
                }
                neighbor = neighbor->next;
            }
        }
    }
    free(visited);
}

void bfs(list **adj_list, int num_nodes, int start_node) {
    bool *visited = malloc(sizeof(bool) * num_nodes);
    if (visited == NULL) return; // safety net

    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }

    // Instantiating and initializing your queue structure on the heap
    queue *q = malloc(sizeof(queue));
    if (q == NULL) {
        free(visited);
        return;
    }
    q->head = NULL;
    q->tail = NULL;

    // 3. Kickstart the BFS
    enqueue(&q, start_node);
    visited[start_node] = true;

    while (q->head != NULL) {
        // Dequeue the next node in line (FIFO)
        int current = dequeue(&q);
        fprintf(stderr,"Visited: %d\n", current);

        // 4. Explore all immediate neighbors
        graph_node *neighbor = adj_list[current]->head;
        while (neighbor != NULL) {
            int neighbor_val = neighbor->vertex_num;

            // If the neighbor hasn't been discovered yet
            if (!visited[neighbor_val]) {
                visited[neighbor_val] = true; // Mark it now so it isn't enqueued twice
                enqueue(&q, neighbor_val);
            }
            neighbor = neighbor->next;
        }
    }
    // memory allocation clean up.
    free(q);
    free(visited);
}
