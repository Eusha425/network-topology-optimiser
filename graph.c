//graph.c

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph* create_graph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void add_edge(Graph* graph, int src, int dest, int weight, int cost) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->dest = dest;
    new_node->weight = weight; // Interference
    new_node->cost = cost;     // Cost
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;

    new_node = (Node*)malloc(sizeof(Node));
    new_node->dest = src;
    new_node->weight = weight; // Interference
    new_node->cost = cost;     // Cost
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;
}


int compare_edges(const void* a, const void* b) {
    const Edge* edge_a = (const Edge*)a;
    const Edge* edge_b = (const Edge*)b;

    if (edge_a->weight != edge_b->weight) {
        return edge_a->weight - edge_b->weight; // Compare interference first
    }
    else {
        return edge_a->cost - edge_b->cost;     // Compare cost if interference is the same
    }
}


int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void union_sets(Subset subsets[], int x, int y) {
    int x_root = find(subsets, x);
    int y_root = find(subsets, y);

    if (subsets[x_root].rank < subsets[y_root].rank)
        subsets[x_root].parent = y_root;
    else if (subsets[x_root].rank > subsets[y_root].rank)
        subsets[y_root].parent = x_root;
    else {
        subsets[y_root].parent = x_root;
        subsets[x_root].rank++;
    }
}

void kruskal_MST(Graph* graph, int max_interference, int max_cost) {
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

    int edge_index = 0;
    for (int i = 0; i < V; ++i) {
        Node* current = graph->array[i].head;
        while (current) {
            edges[edge_index].src = i;
            edges[edge_index].dest = current->dest;
            edges[edge_index].weight = current->weight;
            edges[edge_index].cost = current->cost;
            edge_index++;
            current = current->next;
        }
    }

    int e = 0; // Index for the result array
    int i = 0; // Index for sorted edges array

    // Sort all edges in ascending order of weight (interference)
    qsort(edges, E, sizeof(edges[0]), compare_edges);

    // Allocate memory for subsets
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Add the smallest edge to the result and check for cycles
    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));

    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];

        // Check interference and cost constraints
        if (next_edge.weight <= max_interference) {
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);

            if (x != y) {
                result[e++] = next_edge;
                union_sets(subsets, x, y);
            }
        }
    }

    // Print the MST with minimum weight and cost
    printf("Minimum Spanning Tree:\n");
    int min_weight = 0;
    int total_cost = 0;

    for (i = 0; i < e; ++i) {
        printf("%d - %d   Weight: %d   Cost: %d\n", result[i].src, result[i].dest, result[i].weight, result[i].cost);
        min_weight += result[i].weight;
        total_cost += result[i].cost;
    }

    printf("Minimum Weight (Interference): %d\n", min_weight);
    printf("Total Cost: %d\n", total_cost);

    // Free dynamically allocated memory
    free(subsets);
    free(edges);
    free(result);
}

