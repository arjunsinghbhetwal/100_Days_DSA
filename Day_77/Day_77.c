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

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS
void dfs(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data);
        }
        temp = temp->next;
    }
}

// Check connected
int isConnected(int n) {
    dfs(1); // start from node 1

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

// Main
int main() {
    int n = 4;

    // Initialize
    for (int i = 0; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Edges
    addEdge(1, 2);
    addEdge(3, 4);

    if (isConnected(n))
        printf("CONNECTED");
    else
        printf("NOT CONNECTED");

    return 0;
}