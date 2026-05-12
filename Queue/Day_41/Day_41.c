#include <stdio.h>
#define SIZE 5

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("-1\n"); //print if the front is empty.
        return;
    }

    struct Node* temp = front;
    printf("%d\n",front->data); //prints the ignored node.

    front = front->next; //jumps to the next node.

    if(front == NULL){
        rear = NULL;
    }
    free(temp); //frees the node from memory.
}

int main(){
    int n;
    scanf("%d",&n);

    while(n--){
        int choice;
        scanf("%d",&choice);

        if(choice == 1){
            int x;
            scanf("%d",&x);
            enqueue(x);
        }else if(choice == 2){
            dequeue();
        }
    }

    return 0;
}