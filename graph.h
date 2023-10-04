//graph.h

// importing the standard library
#include <stdio.h>
#include <stdlib.h>

// Define a struct for representing an edge in the graph
typedef struct {
    int src, dest, weight;
} Edge;

// Define a struct for representing a node in the adjacency list
typedef struct Node {
    int dest, weight;
    struct Node* next;
} Node;

// Define a struct for representing the adjacency list for each vertex
typedef struct {
    int V;       // Number of vertices
    Node** array; // Array of linked lists
} Graph;

// Structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Function prototypes
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest, int weight);
void kruskalMST(Edge edges[], int V, int E);
int find(Subset subsets[], int i);
void unionSets(Subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);
