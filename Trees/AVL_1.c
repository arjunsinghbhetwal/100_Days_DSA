#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int height;

    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    struct Node* temp;

    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->height = 1;

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);

        printf("%d ",root->data);

        inorder(root->right);
    }
}

int height(struct Node* node)
{
    if(node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getbalance(struct Node* node)
{
    if(node == NULL)
    {
        return 0;
    }
    return height(node->left)
         - height(node->right);
}

int Max(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main(){

    struct Node* root = NULL;

    root = createNode(30);

    root->left = createNode(20);

    root->left->left = createNode(10);

    root->left->height =
    1 + Max(height(root->left->left),
            height(root->left->right));

    root->height = 
    1 + Max(height(root->left),
            height(root->right));

    printf("Inorder Traversal: \n");
    inorder(root);

    printf("\nBalance Factor of Root: %d",getbalance(root));

    return 0;
}