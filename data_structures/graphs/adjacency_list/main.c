// I prompted gemini to generate code for the main function to test my implementation.
#include <stdio.h>
#include "graph_adj_list.h"

int main() {
    // 1. Create a graph with 4 nodes (0, 1, 2, 3)
    int nodes = 4;
    list **my_adj_list = create_graph(nodes);

    if (my_adj_list == NULL) {
        fprintf(stderr, "Failed to allocate graph memory.\n");
        return 1;
    }

    // 2. Add some undirected edges
    // Edge 0-1
    add_node(my_adj_list, 0, 1);
    add_node(my_adj_list, 1, 0);

    // Edge 0-2
    add_node(my_adj_list, 0, 2);
    add_node(my_adj_list, 2, 0);

    // Edge 1-2
    add_node(my_adj_list, 1, 2);
    add_node(my_adj_list, 2, 1);

    // Edge 2-3
    add_node(my_adj_list, 2, 3);
    add_node(my_adj_list, 3, 2);

    // 3. Visualize the graph
    print_graph(my_adj_list, nodes);

    // 4. Cleanup
    fprintf(stderr, "\nDestroying graph and freeing memory...\n");
    destroy_graph(my_adj_list, nodes);

    fprintf(stderr,"Test complete.\n");
    return 0;
}