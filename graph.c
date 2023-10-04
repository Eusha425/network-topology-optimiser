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

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = src;
    newNode->weight = weight;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
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

void kruskalMST(Graph* graph) {
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
    if (edges == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Populate the edges array from the adjacency list
    int edgeIndex = 0;
    for (int i = 0; i < V; ++i) {
        Node* current = graph->array[i].head;
        while (current) {
            edges[edgeIndex].src = i;
            edges[edgeIndex].dest = current->dest;
            edges[edgeIndex].weight = current->weight;
            edgeIndex++;
            current = current->next;
        }
    }

    int e = 0; // Index for the result array
    int i = 0; // Index for sorted edges array

    // Step 1: Sort all edges in ascending order of weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Add the smallest edge to the result and check for cycles
    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i) {
        printf("%d - %d   Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    // Free dynamically allocated memory
    free(subsets);
    free(edges);
    free(result);
}
