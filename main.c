//main.c

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int V = 6; // Number of vertices (tower locations)
    Graph* graph = createGraph(V);

    // Adding edges with interference and cost constraints
    addEdge(graph, 0, 1, 2, 3);
    addEdge(graph, 0, 2, 4, 1);
    addEdge(graph, 1, 2, 5, 2);
    addEdge(graph, 1, 3, 3, 4);
    addEdge(graph, 2, 3, 1, 2);
    addEdge(graph, 3, 4, 4, 3);
    addEdge(graph, 4, 5, 2, 1);

    int maxInterference = 3; // Maximum allowed interference
    int maxCost = 7;         // Maximum allowed cost

    printf("Tower Locations with Constraints:\n");
    kruskalMST(graph, maxInterference, maxCost);

    // Free allocated memory
    free(graph);

    return 0;
}
