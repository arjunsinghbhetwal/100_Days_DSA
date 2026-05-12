#include <stdio.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];

// Find min distance node
int minDistance(int dist[], int visited[], int n) {
    int min = INF, index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX], visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

// Main
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; // remove if directed
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}