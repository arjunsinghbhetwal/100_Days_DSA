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

// Queue
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

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

    newNode = createNode(u); // remove for directed
    newNode->next = adj[v];
    adj[v] = newNode;
}

// BFS function
void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp) {
            int adjNode = temp->data;

            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                enqueue(adjNode);
            }
            temp = temp->next;
        }
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

    printf("BFS Traversal: ");
    bfs(0);

    return 0;
}