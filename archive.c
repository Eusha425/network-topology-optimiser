// archive of the test done on each individual components.

#include "graph.h"

// testing of edge
int main_edge() {
    Edge edge1, edge2;

    edge1.src = 0;
    edge1.dest = 1;
    edge1.weight = 2;
    edge1.cost = 3;

    edge2.src = 1;
    edge2.dest = 2;
    edge2.weight = 5;
    edge2.cost = 2;

    int result = compare_edges(&edge1, &edge2);

    printf("Comparison Result: %d\n", result); // Should print a negative value

    return 0;
}

// testing find and unionsets 
int main_union() {
    Subset subsets[5];

    for (int i = 0; i < 5; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    union_sets(subsets, 0, 1);
    union_sets(subsets, 2, 3);
    union_sets(subsets, 1, 3);

    int root0 = find(subsets, 0);
    int root1 = find(subsets, 1);
    int root2 = find(subsets, 2);
    int root3 = find(subsets, 3);
    int root4 = find(subsets, 4);

    printf("Root of 0: %d\n", root0); // Should print the root (representative) of the set containing 0 and 1
    printf("Root of 2: %d\n", root2); // Should print the root (representative) of the set containing 2, 3, and 1
    printf("Root of 4: %d\n", root4); // Should print 4 since it's not part of any union

    return 0;
}


// test for create graph and adding edge
int main_graph() {
    int V = 4; // Number of vertices
    Graph* graph = create_graph(V);

    // Add edges to the graph
    add_edge(graph, 0, 1, 2, 3);
    add_edge(graph, 0, 2, 4, 1);
    add_edge(graph, 1, 2, 5, 2);

    // Print the adjacency list to verify edge addition
    for (int i = 0; i < V; ++i) {
        printf("Adjacency List of Vertex %d:\n", i);
        Node* current = graph->array[i].head;
        while (current) {
            printf("-> %d (Interference: %d, Cost: %d)\n", current->dest, current->weight, current->cost);
            current = current->next;
        }
    }

    // Free allocated memory
    free(graph);

    return 0;
}

// kruskal solution
int main_kruskal() {
    int V = 6; // Number of vertices (tower locations)
    Graph* graph = create_graph(V);

    // Test Case 1: Basic graph with no constraints
    add_edge(graph, 0, 1, 2, 3);
    add_edge(graph, 0, 2, 4, 1);
    add_edge(graph, 1, 2, 5, 2);
    add_edge(graph, 1, 3, 3, 4);
    add_edge(graph, 2, 3, 1, 2);
    add_edge(graph, 3, 4, 4, 3);
    add_edge(graph, 4, 5, 2, 1);

    int max_interference = 10; // Maximum allowed interference (high value)
    int max_cost = 100;        // Maximum allowed cost (high value)

    printf("Test Case 1: Basic graph with no constraints\n");
    kruskal_MST(graph, max_interference, max_cost);

    // Free allocated memory
    free(graph);

    // Test Case 2: Graph with interference and cost constraints
    graph = create_graph(V);
    add_edge(graph, 0, 1, 2, 3);
    add_edge(graph, 0, 2, 4, 1);
    add_edge(graph, 1, 2, 5, 2);
    add_edge(graph, 1, 3, 3, 4);
    add_edge(graph, 2, 3, 1, 2);
    add_edge(graph, 3, 4, 4, 3);
    add_edge(graph, 4, 5, 2, 1);

    max_interference = 3; // Maximum allowed interference
    max_cost = 7;         // Maximum allowed cost

    printf("\nTest Case 2: Graph with interference and cost constraints\n");
    kruskal_MST(graph, max_interference, max_cost);

    // Free allocated memory
    free(graph);

    return 0;
}

// prim's solution
int main_prim() {
    int V = 6; // Number of vertices
    int E = 9; // Number of edges
    int cost_limit = 10; // Maximum allowed cost (high value)
    int maxInterference = 5; // Maximum allowed interference (high value)

    Graph* graph = create_graph(V);

    // Adding edges with pre-entered values
    add_edge(graph, 0, 1, 2, 5); // Edge from vertex 0 to 1, interference = 2, cost = 5
    add_edge(graph, 0, 2, 3, 6);
    add_edge(graph, 1, 2, 1, 4);
    add_edge(graph, 1, 3, 4, 7);
    add_edge(graph, 1, 4, 5, 8);
    add_edge(graph, 2, 4, 6, 9);
    add_edge(graph, 3, 5, 2, 3);
    add_edge(graph, 4, 5, 3, 6);
    add_edge(graph, 0, 5, 4, 10);

    prim_MST(graph, cost_limit, maxInterference);

    return 0;
}