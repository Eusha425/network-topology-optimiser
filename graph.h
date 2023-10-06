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

Graph* create_graph(int V);
void add_edge(Graph* graph, int src, int dest, int weight, int cost);
int compare_edges(const void* a, const void* b);
int find(Subset subsets[], int i);
void union_sets(Subset subsets[], int x, int y);
void kruskal_MST(Graph* graph, int max_interference, int max_cost);

