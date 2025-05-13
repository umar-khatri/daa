#include <stdio.h>
#include <conio.h> // For Turbo C compatibility
#include <limits.h> // For INT_MAX

#define MAX 100

int findMinDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, minIndex, v;
    for (v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX], visited[MAX], i, j, u;

    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (i = 0; i < n - 1; i++) {
        u = findMinDistance(dist, visited, n);
        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[MAX][MAX], n, src, i, j;

    clrscr(); // Clear screen for Turbo C
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    getch(); // Wait for a key press in Turbo C
    return 0;
}
/*dijkstras.c
Problem: Dijkstra’s Algorithm
Time Complexity: O((V + E) log V) with min-heap
or O(V^2) with an adjacency matrix
*/