#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to assign random weights to edges
int assignRandomWeight() {
    return rand() % 10 + 1; // Generates random weights between 1 and 10
}

int main() {
    int rows = 5; // Number of rows in the grid
    int cols = 5; // Number of columns in the grid
    Graph* graph = createGraph(rows * cols);

    // Seed the random number generator
    srand(time(NULL));

    // Create a grid with coverage and interference radii (simplified)
    int grid[5][5][2] = {
        {{1, 2}, {1, 2}, {1, 2}, {0, 0}, {0, 0}},
        {{1, 2}, {2, 3}, {2, 3}, {2, 3}, {0, 0}},
        {{1, 2}, {2, 3}, {2, 3}, {2, 3}, {0, 0}},
        {{0, 0}, {2, 3}, {2, 3}, {2, 3}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}
    };

    // Add edges between tower locations with random weights
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int src = i * cols + j;
            int interferenceThreshold = grid[i][j][1]; // Maximum allowed interference
            for (int x = i - grid[i][j][0]; x <= i + grid[i][j][0]; ++x) {
                for (int y = j - grid[i][j][0]; y <= j + grid[i][j][0]; ++y) {
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        int dest = x * cols + y;
                        if (src != dest && interferenceThreshold > 0) {
                            // Assign random weight to the edge
                            int weight = assignRandomWeight();
                            addEdge(graph, src, dest, weight);
                            interferenceThreshold--;
                        }
                    }
                }
            }
        }
    }

    kruskalMST(graph);

    return 0;
}
