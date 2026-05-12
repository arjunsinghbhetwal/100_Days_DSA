#include <stdio.h>
#define V 4
#define INF 99999

// Find min key
int minKey(int key[], int mst[]) {
    int min = INF, min_index;

    for (int i = 0; i < V; i++) {
        if (!mst[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Prim's Algorithm
void primMST(int graph[V][V]) {
    int key[V];
    int mst[V];
    int parent[V];

    // Initialize
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mst);
        mst[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] &&
                !mst[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate total weight
    int total = 0;
    for (int i = 1; i < V; i++) {
        total += graph[i][parent[i]];
    }

    printf("Total MST weight: %d", total);
}

// Main
int main() {
    int graph[V][V] = {
        {0, 3, 1, 0},
        {3, 0, 5, 4},
        {1, 5, 0, 2},
        {0, 4, 2, 0}
    };

    primMST(graph);

    return 0;
}