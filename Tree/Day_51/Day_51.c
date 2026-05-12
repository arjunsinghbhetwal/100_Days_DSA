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

// Insert (BST banane ke liye)
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// LCA function
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // dono left me
    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    // dono right me
    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    // split point → LCA
    return root;
}

// Main
int main() {
    struct Node* root = NULL;

    int arr[] = {6, 2, 8, 0, 4, 7, 9};
    int n = 7;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    int n1 = 2, n2 = 8;

    struct Node* ans = LCA(root, n1, n2);

    if (ans != NULL)
        printf("LCA: %d", ans->data);

    return 0;
}