#include <stdio.h>
#include <stdlib.h>
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
    int choice,val,ch,i=0,dq;
    printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
    scanf("%d",&choice);

    while(1){
        switch(choice){
            case 1:
            do{
                printf("Enter value %d: ",i+1);
                scanf("%d",&val);

                enqueue(val);

                printf("1.Continue\n0.Exit\n");
                scanf("%d",&ch);
                i++;
            }while(ch != 0);
            break;

            case 2:
            do{
                printf("Confirm Dequeue %d: ",i+1);
                scanf("%d",&dq);

                dequeue();

                printf("1.Continue\n0.Exit\n");
                scanf("%d",&ch);
                i++;
            }while(ch != 0);
            break;

            case 3:
            return 0;

            default:
            printf("Ivalid! input\n");
        }
    }

    return 0;
}