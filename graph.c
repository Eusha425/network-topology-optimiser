//graph.c

#include "graph.h"

// Function to create a new node for the adjacency list
Node* createNode(int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (Node**)malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++) {
        graph->array[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    // For undirected graphs, you may want to add the reverse edge as well.
    newNode = createNode(src, weight);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

