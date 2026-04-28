#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// LCA function
struct Node* LCA(struct Node* root, int n1, int n2) {
    // Base case
    if (root == NULL)
        return NULL;

    // If one of the nodes matches
    if (root->data == n1 || root->data == n2)
        return root;

    // Search in left and right
    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    // If both sides return non-NULL → LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-NULL side
    return (left != NULL) ? left : right;
}

// Main
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int n1 = 4, n2 = 5;

    struct Node* ans = LCA(root, n1, n2);

    if (ans != NULL)
        printf("LCA: %d", ans->data);

    return 0;
}