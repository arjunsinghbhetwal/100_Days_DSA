#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isCBT(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isCBT(root->left, 2 * index + 1, totalNodes) &&
           isCBT(root->right, 2 * index + 2, totalNodes);
}

// Check Min Heap property
int isMinHeap(struct Node* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL)
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);

    // Both children
    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return 0;
}

// Main validation
int isHeap(struct Node* root) {
    int totalNodes = countNodes(root);

    if (isCBT(root, 0, totalNodes) && isMinHeap(root))
        return 1;

    return 0;
}

// Main
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(7);
    root->left->right = newNode(9);
    root->right->left = newNode(8);
    root->right->right = newNode(10);

    if (isHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}