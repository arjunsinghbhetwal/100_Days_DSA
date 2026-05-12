#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1,rear = -1;

//Enqueue
void enqueue(int value){
    if(rear == SIZE - 1){
        printf("Queue OverFlow\n");
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
        printf("Queue UnderFlow\n");
    }else{
        printf("Removed: %d\n",queue[front]);
        front++;
    }
}

//Peek
void peek(){
    if(front == -1){
        printf("Queue Underflow\n");
    }else{
        printf("Front element: %d\n",queue[front]);
    }
}

//Display
void display(){
    if(front == -1){
        printf("Queue Underflow\n");
    }else{
        printf("Queue: [");
        for(int i = front;i <= rear;i++){
            printf("%d",queue[i]);

            if(i != rear){
                printf(" ");
            }
        }
    }printf("]\n");
}

//MAIN MENU
int main(){

    int choice,val;

    while(1){
        printf("\n---QUEUE MENU---\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Rotate\n5.Exit\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:
            printf("Enter element: ");
            scanf("%d",&val);
            enqueue(val);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4: {
            int k;
            printf("No. of rotations: ");
            scanf("%d",&k);

            for(int i = 0;i < k;i++){
                if(front == -1 || front > rear){
                    printf("Queue UnderFlow!\n");
                    break;
                }

                int temp = queue[front];
                front++;

                rear++;
                queue[rear] = temp;
            }
            break;
        }

            case 5:
            return 0;

            default:
            printf("Invalid! Choice\n");
        }
    }

    return 0;
}