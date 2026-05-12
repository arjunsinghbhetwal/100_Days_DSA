#include <stdio.h>
#include <stdlib.h>

//-----Structure Created-----//
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//-----Create Node-----//
struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;         //returns the address of the node to main() node.
}

//------Count Node-----//
int countNodes(struct Node* root){

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int count = 0;

    while(front < rear){
        struct Node* temp = queue[front++];
        
        count++;

        if(temp->left != NULL)
            queue[rear++] = temp->left;
        
        if(temp->right != NULL)
            queue[rear++] = temp->right;
    }
    return count;
}

//-----Preorder-----//
void preorder(struct Node* root){
    if(root == NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//----PostOrder-----//
void postorder(struct Node* root){
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

//------Count Leaf------//
int CountLeaf(struct Node* root){
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
    return 1;

    return CountLeaf(root->left) + CountLeaf(root->right);
}

//-----Find Min----//
struct Node* FindMin(struct Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

//------Delete------//
struct Node* DeleteNode(struct Node* root,int key){
    if(root == NULL)
        return NULL;

    if(key < root->data){
        root->left = DeleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = DeleteNode(root->right, key);
    }

    else{
        //Case1: Leaf Node
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        //Case2: One Child
        else if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        //Case3: Two Children
        else{
            struct Node* temp = FindMin(root->right); //successor
            root->data = temp->data;                  //replace
            root->right = DeleteNode(root->right, temp->data); //delete duplicate
        }
    }
    return root;
}

//----Height-----//
int height(struct Node* root){
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main(){

    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->right->right = createNode(50);

    printf("PreOrder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");

    int result = countNodes(root);
    printf("Count Nodes: %d\n",result);
    
    printf("Count Leaf: %d\n",CountLeaf(root));

    // struct Node* res1 = Findmin(root);

    // if(res1 != NULL)
    //     printf("Find MIN: %d\n",res1);

    printf("Height: %d",height(root));

    int key;
    printf("\nEnter Key: ");
    scanf("%d",&key);

    root = DeleteNode(root, key);

    preorder(root);

    return 0;
}