//graph.c

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight, int cost) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight; // Interference
    newNode->cost = cost;     // Cost
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = src;
    newNode->weight = weight; // Interference
    newNode->cost = cost;     // Cost
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


int compareEdges(const void* a, const void* b) {
    const Edge* edgeA = (const Edge*)a;
    const Edge* edgeB = (const Edge*)b;

    if (edgeA->weight != edgeB->weight) {
        return edgeA->weight - edgeB->weight; // Compare interference first
    }
    else {
        return edgeA->cost - edgeB->cost;     // Compare cost if interference is the same
    }
}


int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(Graph* graph, int maxInterference, int maxCost) {
    int V = graph->V;
    int E = 0;
    for (int i = 0; i < V; ++i) {
        Node* current = graph->array[i].head;
        while (current) {
            E++;
            current = current->next;
        }
    }

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));

    int edgeIndex = 0;
    for (int i = 0; i < V; ++i) {
        Node* current = graph->array[i].head;
        while (current) {
            edges[edgeIndex].src = i;
            edges[edgeIndex].dest = current->dest;
            edges[edgeIndex].weight = current->weight;
            edges[edgeIndex].cost = current->cost;
            edgeIndex++;
            current = current->next;
        }
    }

    int e = 0; // Index for the result array
    int i = 0; // Index for sorted edges array

    // Sort all edges in ascending order of weight (interference)
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Add the smallest edge to the result and check for cycles
    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));

    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];

        // Check interference and cost constraints
        if (nextEdge.weight <= maxInterference) {
            int x = find(subsets, nextEdge.src);
            int y = find(subsets, nextEdge.dest);

            if (x != y) {
                result[e++] = nextEdge;
                unionSets(subsets, x, y);
            }
        }
    }

    // Print the MST with minimum weight and cost
    printf("Minimum Spanning Tree:\n");
    int minWeight = 0;
    int totalCost = 0;

    for (i = 0; i < e; ++i) {
        printf("%d - %d   Weight: %d   Cost: %d\n", result[i].src, result[i].dest, result[i].weight, result[i].cost);
        minWeight += result[i].weight;
        totalCost += result[i].cost;
    }

    printf("Minimum Weight (Interference): %d\n", minWeight);
    printf("Total Cost: %d\n", totalCost);

    // Free dynamically allocated memory
    free(subsets);
    free(edges);
    free(result);
}

