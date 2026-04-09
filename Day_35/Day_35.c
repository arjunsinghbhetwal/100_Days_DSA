#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

//Enqueue
void enqueue(int value){
    if (rear == SIZE - 1){
        printf("Queue Overflow\n");
    }else{
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted: %d\n",value);
    }
}

//Dequeue
void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
    }else{
        printf("Removed: %d\n",queue[front]);
        front++;
    }
}

//Peek
void peek(){
    if(front == -1){
        printf("Queue is empty\n");
    }else{
        printf("Front element: %d",queue[front]);
    }
}

//Display
void display(){
    if(front == -1){
        printf("Queue is empty\n");
    }else{
        printf("Queue: ");
        for(int i = front;i <= rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

//Main menu
int main(){
    int choice,val,i=1,ch;
    char pos;

    while(1){
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            do{
                printf("Enter element %d: ",i);
                scanf("%d",&val);

                enqueue(val);

                printf("1.Continue\n0.Exit\n");
                scanf("%d",&ch);
                i++;
            }while(ch != 0);
            break;

            case 2:
            do{
                printf("Dequeue Confirm(yes/no): ");
                scanf("%s",&pos);

                dequeue();

                printf("1.Continue\n0.Exit\n");
                scanf("%d",&ch);
            }while(ch != 0);
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            return 0;
        }
    }

    return 0;
}