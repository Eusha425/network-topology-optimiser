//main.c

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// primary main method
int main() {
    int V = 6; // Number of vertices (tower locations)
    Graph* graph = create_graph(V);

    // Test Case 1: Basic graph with no constraints
    add_edge(graph, 0, 1, 2, 3);
    add_edge(graph, 0, 2, 4, 1);
    add_edge(graph, 1, 2, 5, 2);
    add_edge(graph, 1, 3, 3, 4);
    add_edge(graph, 2, 3, 1, 2);
    add_edge(graph, 3, 4, 4, 3);
    add_edge(graph, 4, 5, 2, 1);

    int max_interference = 10; // Maximum allowed interference (high value)
    int max_cost = 100;        // Maximum allowed cost (high value)

    printf("Test Case 1: Basic graph with no constraints\n");
    kruskal_MST(graph, max_interference, max_cost);

    // Free allocated memory
    free(graph);

    // Test Case 2: Graph with interference and cost constraints
    graph = create_graph(V);
    add_edge(graph, 0, 1, 2, 3);
    add_edge(graph, 0, 2, 4, 1);
    add_edge(graph, 1, 2, 5, 2);
    add_edge(graph, 1, 3, 3, 4);
    add_edge(graph, 2, 3, 1, 2);
    add_edge(graph, 3, 4, 4, 3);
    add_edge(graph, 4, 5, 2, 1);

    max_interference = 3; // Maximum allowed interference
    max_cost = 7;         // Maximum allowed cost

    printf("\nTest Case 2: Graph with interference and cost constraints\n");
    kruskal_MST(graph, max_interference, max_cost);

    // Free allocated memory
    free(graph);

    return 0;
}

int mai1() {
    int V = 6; // Number of vertices
    int E = 9; // Number of edges
    int cost_limit = 10; // Maximum allowed cost (high value)
    int maxInterference = 5; // Maximum allowed interference (high value)

    Graph* graph = create_graph(V);
    
    // Adding edges with pre-entered values
    add_edge(graph, 0, 1, 2, 5); // Edge from vertex 0 to 1, interference = 2, cost = 5
    add_edge(graph, 0, 2, 3, 6);
    add_edge(graph, 1, 2, 1, 4);
    add_edge(graph, 1, 3, 4, 7);
    add_edge(graph, 1, 4, 5, 8);
    add_edge(graph, 2, 4, 6, 9);
    add_edge(graph, 3, 5, 2, 3);
    add_edge(graph, 4, 5, 3, 6);
    add_edge(graph, 0, 5, 4, 10);

    primMST(graph, cost_limit, maxInterference);

    return 0;
}