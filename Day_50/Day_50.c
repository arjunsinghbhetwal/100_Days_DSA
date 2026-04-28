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

// Insert (for building tree)
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Search function
struct Node* search(struct Node* root, int key) {
    // Base case
    if (root == NULL || root->data == key)
        return root;

    // Go left
    if (key < root->data)
        return search(root->left, key);

    // Go right
    return search(root->right, key);
}

// Main
int main() {
    struct Node* root = NULL;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);

    int key = 4;

    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element found: %d", result->data);
    else
        printf("Element not found");

    return 0;
}