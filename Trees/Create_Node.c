#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value){
    struct Node* temp;

    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);

        preorder(root->left);

        preorder(root->right);
    }
}

void inorder(struct Node* root){
    if(root !=  NULL){
        inorder(root->left);

        printf("%d ",root->data);

        inorder(root->right);
    }
}

void postorder(struct Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);

        postorder(root->right);

        printf("%d ",root->data);
    }
}

int countNodes(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

int countLeafNodes(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNodes(root->left)
         + countLeafNodes(root->right);
}

int height(struct Node* root)
{
    int leftheight;
    int rightheight;

    if(root == NULL){
        return 0;
    }

    leftheight = height(root->left);
    rightheight = height(root->right);

    if(leftheight > rightheight){
        return leftheight + 1;
    }
    else{
        return rightheight + 1;
    }
}

int main(){

    struct Node* root;

    root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    printf("Preorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    
    printf("\nTotal nodes: %d",countNodes(root));

    printf("\nTotal Leaf Nodes: %d",countLeafNodes(root));
    
    printf("\nHeight of tree: %d",height(root));

    return 0;
}