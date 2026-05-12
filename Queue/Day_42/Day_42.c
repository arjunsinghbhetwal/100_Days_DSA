#include <stdio.h>
#define SIZE 5
#define MAX 5

//Queue created.
int queue[SIZE];
int front = -1,rear = -1;

//stack created.
int stack[MAX];
int top = -1;

//Enqueue.
void enqueue(int value){
    if(rear == SIZE - 1){
        printf("Queue empty!\n");
    }else{
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
    }
}

//Fit into the Stack.
void reverse(int value){
    if(top == MAX - 1){
    printf("Stack OverFlow!\n");
    }else{
        top++;
        stack[top] = value;
    }
}

int main(){
    int val;
    printf("Enter enqueue: ");
    scanf("%d",&val);

    enqueue(val);

    return 0;
}