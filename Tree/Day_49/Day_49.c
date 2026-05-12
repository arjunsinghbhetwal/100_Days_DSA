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

// Insert function
struct Node* insert(struct Node* root, int val) {
    // If tree is empty
    if (root == NULL)
        return newNode(val);

    // If val is smaller → left
    if (val < root->data)
        root->left = insert(root->left, val);

    // If val is greater → right
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Inorder traversal (for checking)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main
int main() {
    struct Node* root = NULL;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}