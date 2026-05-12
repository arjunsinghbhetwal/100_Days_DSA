#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

int main(){

    //creating root node
    struct Node* root;

    root = (struct Node*)malloc(sizeof(struct Node));

    root->data = 10;
    root->left = NULL;
    root->right = NULL;

    //creating left child
    struct Node* second;
    
    second = (struct Node*)malloc(sizeof(struct Node));

    second->data = 20;
    second->left = NULL;
    second->right = NULL;

    //creating right child
    struct Node* third;

    third = (struct Node*)malloc(sizeof(struct Node));

    third->data =  30;
    third->left  = NULL;
    third->right = NULL;

    //connecting nodes
    root->left = second;
    root->right = third;

    //printing nodes
    printf("Root Node: %d\n",root->data);
    printf("left child: %d\n",second->data);
    printf("right child: %d",third->data);

    // printf("Root Node Data = %d", root->data);

    return 0;
}