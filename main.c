//main.c

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// primary main method
int main() {
    int V = 6; // Number of vertices (tower locations)
    Graph* graph = createGraph(V);

    // Test Case 1: Basic graph with no constraints
    addEdge(graph, 0, 1, 2, 3);
    addEdge(graph, 0, 2, 4, 1);
    addEdge(graph, 1, 2, 5, 2);
    addEdge(graph, 1, 3, 3, 4);
    addEdge(graph, 2, 3, 1, 2);
    addEdge(graph, 3, 4, 4, 3);
    addEdge(graph, 4, 5, 2, 1);

    int maxInterference = 10; // Maximum allowed interference (high value)
    int maxCost = 100;        // Maximum allowed cost (high value)

    printf("Test Case 1: Basic graph with no constraints\n");
    kruskalMST(graph, maxInterference, maxCost);

    // Free allocated memory
    free(graph);

    // Test Case 2: Graph with interference and cost constraints
    graph = createGraph(V);
    addEdge(graph, 0, 1, 2, 3);
    addEdge(graph, 0, 2, 4, 1);
    addEdge(graph, 1, 2, 5, 2);
    addEdge(graph, 1, 3, 3, 4);
    addEdge(graph, 2, 3, 1, 2);
    addEdge(graph, 3, 4, 4, 3);
    addEdge(graph, 4, 5, 2, 1);

    maxInterference = 3; // Maximum allowed interference
    maxCost = 7;         // Maximum allowed cost

    printf("\nTest Case 2: Graph with interference and cost constraints\n");
    kruskalMST(graph, maxInterference, maxCost);

    // Free allocated memory
    free(graph);

    return 0;
}