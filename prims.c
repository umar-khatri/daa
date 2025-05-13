#include <stdio.h>
#include <conio.h> // For Turbo C compatibility
#include <limits.h> // For INT_MAX

#define MAX 100

int findMinKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, minIndex, v;

    for (v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[MAX][MAX], int n) {
    int i;
    printf("Edge\tWeight\n");
    for (i = 1; i < n; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primsAlgorithm(int graph[MAX][MAX], int n) {
    int parent[MAX], key[MAX], mstSet[MAX];
    int i, count, u, v;

    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < n - 1; count++) {
        u = findMinKey(key, mstSet, n);
        mstSet[u] = 1;

        for (v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main() {
    int graph[MAX][MAX], n, i, j;

    clrscr(); // Clear screen for Turbo C
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    primsAlgorithm(graph, n);

    getch(); // Wait for a key press in Turbo C
    return 0;
}
/*
prims.c
Problem: Prim’s MST Algorithm
Time Complexity:

O(V^2) (with adjacency matrix)

O((V + E) log V) (with min-heap)
*/