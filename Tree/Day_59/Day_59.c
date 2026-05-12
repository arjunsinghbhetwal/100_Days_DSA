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

// Search in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

int postIndex;

// Build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end)
        return NULL;

    // Pick root from postorder
    int curr = postorder[postIndex--];
    struct Node* node = newNode(curr);

    // If leaf node
    if (start == end)
        return node;

    // Find position in inorder
    int pos = search(inorder, start, end, curr);

    //Build right first
    node->right = buildTree(inorder, postorder, pos + 1, end);
    node->left  = buildTree(inorder, postorder, start, pos - 1);

    return node;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main
int main() {
    int inorder[]   = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};
    int n = 5;

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    printf("Preorder: ");
    preorder(root);

    return 0;
}