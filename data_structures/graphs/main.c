#include "graph_adj_mat.h"

int main () {
    graph *g = create_graph(10);

    add_edge(g,0, 1);
    add_edge(g,0, 2);
    add_edge(g,0, 0);
    add_edge(g,9, 4);
    add_edge(g,3, 1);
    add_edge(g,5, 7);
    add_edge(g,8, 0);


    print_graph(g);

    destroy_graph(g);

    return 0;
}