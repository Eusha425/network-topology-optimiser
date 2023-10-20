//main.c

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#pragma warning(disable:4996) // to suppress CRT SECURE NO WARNINGS
#include <time.h>

int main() {
    // Start measuring time
    clock_t start_time = clock();
    int V;
    printf("Enter the number of vertices (tower locations): ");
    scanf("%d", &V);

    Graph* graph = create_graph(V);

    // Input the edges
    printf("Enter edges (format: source destination interference cost):\n");
    int source, destination, interference, cost;

    while (1) {
        printf("Source Destination Interference Cost (-1 to finish): ");
        scanf("%d %d %d %d", &source, &destination, &interference, &cost);

        if (source == -1 || destination == -1) {
            break;
        }

        if (source < 0 || source >= V || destination < 0 || destination >= V) {
            printf("Invalid vertex numbers. Please enter valid vertices.\n");
            continue;
        }

        add_edge(graph, source, destination, interference, cost);
    }

    int max_interference, max_cost;
    printf("Enter the maximum allowed interference: ");
    scanf("%d", &max_interference);
    printf("Enter the maximum allowed cost: ");
    scanf("%d", &max_cost);

    printf("MST for the graph:\n");
    prim_MST(graph, max_interference, max_cost);
    //kruskal_MST(graph, max_interference, max_cost);

    // Free allocated memory
    free(graph);

    // Stop measuring time
    clock_t end_time = clock();

    // Calculate the elapsed time in milliseconds
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000.0;

    // Print the elapsed time
    printf("Operation took %.2f milliseconds\n", elapsed_time);


    return 0;
}


