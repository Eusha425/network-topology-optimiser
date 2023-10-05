//graph.h


typedef struct Edge {
    int src, dest;
    int weight; // Interference
    int cost;   // Cost
} Edge;

typedef struct Node {
    int dest;
    int weight; // Interference
    int cost;   // Cost
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
void addEdge(Graph* graph, int src, int dest, int weight, int cost);
int compareEdges(const void* a, const void* b);
int find(Subset subsets[], int i);
void unionSets(Subset subsets[], int x, int y);
void kruskalMST(Graph* graph, int maxInterference, int maxCost);

