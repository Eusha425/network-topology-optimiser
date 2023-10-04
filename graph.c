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

// Function to find the set of an element 'i' using the union-find algorithm
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
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

// Function to compare two edges based on their weight
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Function to find the MST using Kruskal's algorithm
void kruskalMST(Edge edges[], int V, int E) {
    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));  // Stores the MST
    int i = 0;       // Index for the result array
    int e = 0;       // Index for sorted edges array

    // Sort all edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Initialize subsets data structure
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0; 
    }

    // Process each edge
    while (i < V - 1 && e < E) {
        Edge next_edge = edges[e++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[i++] = next_edge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST edges
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < V - 1; i++) {
        printf("(%d - %d) : %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    // Free dynamically allocated memory
    free(result);
    free(subsets);
}
