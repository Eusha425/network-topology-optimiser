#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int V = 4; // Number of vertices
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 3, 15);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 3, 6);
    addEdge(graph, 3, 4, 7);
    kruskalMST(graph);

    return 0;
}
