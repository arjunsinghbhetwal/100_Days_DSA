#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    struct Node* temp;

    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct Node* insert(struct Node* root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
       root->right = insert(root->right, value); 
    }

    return root;
}

struct Node* search(struct Node* root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(key == root->data)
    {
        return root;
    }

    if(key < root->data)
    {
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

struct Node* DeleteNode(struct Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(key < root->data)
    {
        root->left = DeleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = DeleteNode(root->right, key);
    }
    else
    {
        //Leaf Node
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        //Case2: Only Left Child
        else if(root->left != NULL &&
        root->right == NULL)
        {
            struct Node* temp;

            temp = root->left;

            free(root);

            return temp;
        }
        //case2: only right child
        else if(root->left == NULL &&
        root->right == NULL)
        {
            struct Node* temp;

            temp = root->right;

            free(root);

            return temp;
        }
        //case3: Two children
        else
        {
            struct Node* temp;

            temp = findmin(root->right);

            root->data = temp->data;

            root->right = DeleteNode(root->right,
                                    temp->data);
        }
    }
    return root;
}

void inorder(struct Node* root){
    if(root != NULL)
    {
        inorder(root->left);

        printf("%d ",root->data);

        inorder(root->right);
    }
}

//Inorder Successor
struct Node* findmin(struct Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

int main(){

    struct Node* root = NULL;
    struct Node* result;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    //Before Deletion
    printf("Before Deletion:\n");

    inorder(root);

    root = DeleteNode(root, 40);

    //After Deletion
    printf("\nAfter Deletion: ");

    inorder(root);

    // if(result != NULL)
    // {
    //     printf("\nNode Found");
    // }
    // else{
    //     printf("\nNode Not Found");
    // }

    return 0;
}