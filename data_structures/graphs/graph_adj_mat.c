#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "graph_adj_mat.h"

typedef struct mygraph {
    int num_nodes;
    bool **edges;
} graph;


graph* create_graph(int num_nodes) {
    // below, no need to make any initializations as calloc automatically set the mem space to zero
    graph *g = malloc(sizeof(*g));
    if (g == NULL) {
        return NULL; //checking if no allocation by malloc.
    }
    g->num_nodes = num_nodes;

    //allocation of memory for the edges.
    g->edges = calloc(sizeof(bool*), g->num_nodes); //creating the outer pointers and setting them to NULL
    if ( g->edges ==NULL) {
        // clean up block if calloc fails to get enough space.
        free(g);
        return NULL;
    }

    for (int i=0; i<g->num_nodes;i++) {
        g->edges[i] = calloc(sizeof(bool), g->num_nodes);
        if (g->edges[i] ==NULL) {
            //clean up just incase calloc fails to give memery at any point in time.
            destroy_graph(g); //due to nested fashion, would have to free edges first before freeing g
            return NULL;
        }
    }
    return g;

};

void destroy_graph(graph* g) {
    // destroying the graph from the inside out, to avoid segmentation fault.
    if (g->edges == NULL) {
        free(g);
        return;
    }

    for (int i=0; i<g->num_nodes;i++) {
        if (g->edges[i] != NULL) {
            free(g->edges[i]);
        }
    }
    free(g->edges);
    free(g);
    g = NULL;   // avoiding dangling pointers
};

void print_graph(graph* g) {
    // this function is not necessary, but I would love to be able to visualize my graph.
    printf("digraph{\n");

    for (int from=0; from<g->num_nodes;from++) {
        for (int to=0; to<g->num_nodes;to++) {
            if (g->edges[from][to]) {
                printf("%i -> %i\n", from, to);
            }
        }
    }
    printf("}\n");
};

bool add_edge(graph* g, unsigned int from_node, unsigned int to_node) {
    // add an edge
    assert(g != NULL);
    assert(from_node < g->num_nodes);
    assert(to_node < g->num_nodes);

    if (has_edge(g, from_node, to_node)) {
        return false;
    }
    g->edges[from_node][to_node] = true;
    return true;
};
bool has_edge(graph* g, unsigned int from_node, unsigned int to_node) {
    //edge look up
    assert(g != NULL);
    assert(from_node < g->num_nodes);
    assert(to_node < g->num_nodes);

    return g->edges[from_node][to_node];
};