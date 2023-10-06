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

    int result = compareEdges(&edge1, &edge2);

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

    unionSets(subsets, 0, 1);
    unionSets(subsets, 2, 3);
    unionSets(subsets, 1, 3);

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
    Graph* graph = createGraph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1, 2, 3);
    addEdge(graph, 0, 2, 4, 1);
    addEdge(graph, 1, 2, 5, 2);

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
