#ifndef GRAPH_ADJ_LIST_H
#define GRAPH_ADJ_LIST_H
#include <stdbool.h>

typedef struct node node;
typedef struct list list;
list** create_graph(int nodes);
bool add_node(list **adj_list, int s, int d);
void print_graph(list **adj_list, int nodes);
void destroy_graph(list **adj_list, int nodes);
void dfs_iterative(list **adj_list, int num_nodes, int start_node);
void bfs(list **adj_list, int num_nodes, int start_node);



#endif