//main.c

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int V; // Number of vertices (tower locations)
    printf("Enter the number of vertices (tower locations): ");
    scanf("%d", &V);

    Graph* graph = create_graph(V);

    int num_edges;
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    // Get edge inputs from the user
    printf("Enter the edges (source, destination, interference, cost) one by one:\n");
    for (int i = 0; i < num_edges; i++) {
        int src, dest, interference, cost;

        printf("Enter source vertex for edge %d: ", i + 1);
        scanf("%d", &src);

        printf("Enter destination vertex for edge %d: ", i + 1);
        scanf("%d", &dest);

        printf("Enter interference for edge %d: ", i + 1);
        scanf("%d", &interference);

        printf("Enter cost for edge %d: ", i + 1);
        scanf("%d", &cost);

        add_edge(graph, src, dest, interference, cost);
    }

    int max_interference, max_cost;
    printf("Enter the maximum allowed interference: ");
    scanf("%d", &max_interference);

    printf("Enter the maximum allowed cost: ");
    scanf("%d", &max_cost);

    printf("Running Kruskal's MST algorithm...\n");

    kruskal_MST(graph, max_interference, max_cost);

    // Free allocated memory
    free(graph);

    return 0;
}
