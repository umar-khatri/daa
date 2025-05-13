#include <stdio.h>
#include <stdbool.h>
#include <conio.h> // For Turbo C compatibility

#define MAX 100

// Function to check if the current color assignment is safe
bool isSafe(int v, int graph[MAX][MAX], int color[], int c, int V) {
    int i;
    for (i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// Recursive utility function to solve the graph coloring problem
bool graphColoringUtil(int graph[MAX][MAX], int m, int color[], int v, int V) {
    int c;
    if (v == V) {
        return true; // All vertices are assigned a color
    }

    for (c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c; // Assign color `c` to vertex `v`

            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true; // Recur for the next vertex
            }

            color[v] = 0; // Backtrack
        }
    }

    return false; // If no color can be assigned
}

// Function to solve the graph coloring problem
bool graphColoring(int graph[MAX][MAX], int m, int V) {
    int color[MAX], i;
    for (i = 0; i < V; i++) {
        color[i] = 0; // Initialize all vertices with no color
    }

    if (!graphColoringUtil(graph, m, color, 0, V)) {
        printf("Solution does not exist.\n");
        return false;
    }

    // Print the solution
    printf("Solution exists with the following color assignments:\n");
    for (i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
    return true;
}

int main() {
    int V, m, i, j;
    int graph[MAX][MAX];

    clrscr(); // Clear screen for Turbo C
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (use 0 for no edge, 1 for edge):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    getch(); // Wait for a key press in Turbo C
    return 0;
}