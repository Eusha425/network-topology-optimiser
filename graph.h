#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;

typedef struct AdjList {
    Node* head;
} AdjList;

typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest, int weight);
int compareEdges(const void* a, const void* b);
int find(Subset subsets[], int i);
void unionSets(Subset subsets[], int x, int y);
void kruskalMST(Graph* graph);

#endif // GRAPH_H
