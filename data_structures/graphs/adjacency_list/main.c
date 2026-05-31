// I prompted gemini to generate code for the main function to test my implementation.
// note, I am currently printing out to stderr stream due to the fact that vis is reading from stdout
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

    // --- Traversal tests (DFS and BFS) ---
    fprintf(stderr, "\n--- DFS iterative starting at node 0 ---\n");
    dfs_iterative(my_adj_list, nodes, 0);

    fprintf(stderr, "\n--- BFS starting at node 0 ---\n");
    bfs(my_adj_list, nodes, 0);

    // Also test starting from a different node (node 2)
    fprintf(stderr, "\n--- DFS iterative starting at node 2 ---\n");
    dfs_iterative(my_adj_list, nodes, 2);

    fprintf(stderr, "\n--- BFS starting at node 2 ---\n");
    bfs(my_adj_list, nodes, 2);

    // 4. Cleanup
    fprintf(stderr, "\nDestroying graph and freeing memory...\n");
    destroy_graph(my_adj_list, nodes);

    // 5. Additional test: disconnected graph
    fprintf(stderr, "\n--- Creating disconnected graph (6 nodes) for traversal tests ---\n");
    int nodes2 = 6;
    list **g2 = create_graph(nodes2);
    if (g2 == NULL) {
        fprintf(stderr, "Failed to allocate second graph memory.\n");
        return 1;
    }

    // Component A: 0-1-2
    add_node(g2, 0, 1);
    add_node(g2, 1, 0);
    add_node(g2, 1, 2);
    add_node(g2, 2, 1);

    // Component B: 3-4
    add_node(g2, 3, 4);
    add_node(g2, 4, 3);

    // Node 5 is isolated

    fprintf(stderr, "\n--- DFS on disconnected graph starting at node 0 ---\n");
    dfs_iterative(g2, nodes2, 0);

    fprintf(stderr, "\n--- BFS on disconnected graph starting at node 3 ---\n");
    bfs(g2, nodes2, 3);

    destroy_graph(g2, nodes2);

    fprintf(stderr,"Test complete.\n");
    return 0;
}