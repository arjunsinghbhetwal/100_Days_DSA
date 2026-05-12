#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// ENQUEUE FUNCTION
void enqueue(int value){

    // CHECK OVERFLOW
    if((rear + 1) % SIZE == front){
        printf("Queue Overflow\n");
        return;
    }

    // FIRST ELEMENT INSERTION
    if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else{
        // CIRCULAR MOVEMENT
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;

    printf("Inserted: %d\n",value);
}

// DEQUEUE FUNCTION
void dequeue(){

    // CHECK UNDERFLOW
    if(front == -1){
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n",queue[front]);

    // SINGLE ELEMENT CASE
    if(front == rear){
        front = rear = -1;
    }
    else{
        // CIRCULAR MOVEMENT
        front = (front + 1) % SIZE;
    }
}

// DISPLAY FUNCTION
void display(){

    if(front == -1){
        printf("Queue Empty\n");
        return;
    }

    int i = front;

    printf("Queue: ");

    while(i != rear){

        printf("%d ",queue[i]);

        i = (i + 1) % SIZE;
    }

    // PRINT LAST ELEMENT
    printf("%d\n",queue[rear]);
}

// MAIN FUNCTION
int main(){

    int choice,val;

    while(1){

        printf("\n--- CIRCULAR QUEUE MENU ---\n");

        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        scanf("%d",&choice);

        switch(choice){

            case 1:

                printf("Enter value: ");
                scanf("%d",&val);

                enqueue(val);
                break;

            case 2:

                dequeue();
                break;

            case 3:

                display();
                break;

            case 4:

                return 0;

            default:

                printf("Invalid Choice\n");
        }
    }

    return 0;
}