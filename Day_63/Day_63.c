#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u); // remove if directed
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        int adjNode = temp->data;
        if (!visited[adjNode]) {
            dfs(adjNode);
        }
        temp = temp->next;
    }
}

// Main
int main() {
    int n = 4;

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);

    int start = 0;

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}