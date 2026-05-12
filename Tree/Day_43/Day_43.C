#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//-----CreateNode-----//
struct Node* CreateNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Build tree from order level
struct Node* buildtree(int arr[], int n){
    if(n == 0 || arr[0] == -1) return NULL;

    struct Node* root = CreateNode(arr[0]);

    struct Node* queue[100];
    int front = 0,rear = 0;

    queue[rear++] = root;
    int i = 1;

    while(i < n){
        struct Node* temp = queue[front++];

        //left child
        if(arr[i] != -1){
            temp->left = CreateNode(arr[i]);
            queue[rear++] = temp->left;
        }
        i++;

        //right child
        if(i <n && arr[i] != -1){
            temp->right = CreateNode(arr[i]);
            queue[rear++] = temp->right;
        }
        i++;
    }
    return root;
}

//Height Functiono.
int height(struct Node* root){
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

//---Main Function---//
int main(){
    int n;
    scanf("%d",&n);

    int arr[100];
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }

    struct Node* root = buildtree(arr, n);

    printf("%d", height(root));

    return 0;
}