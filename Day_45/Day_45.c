#include <stdio.h>
#include <stdlib.h>

//---Structure create---//
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//---Create Node---//
struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//---Height---//
int height(struct Node* root){
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

//---Main Function---//
int main(){
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->right->right = createNode(50);

    printf("%d",height(root));

    return 0;
}