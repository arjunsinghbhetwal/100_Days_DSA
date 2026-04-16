#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Queue functions
void enqueue(int val){
    if(rear == MAX - 1){
        printf("Queue Overflow\n");
    } else {
        if(front == -1) front = 0;
        queue[++rear] = val;
    }
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}

// Stack functions
void push(int val){
    stack[++top] = val;
}

int pop(){
    return stack[top--];
}

// 🔥 Reverse function
void reverseQueue(){
    
    // Step 1: Queue → Stack
    while(front <= rear){
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue
    while(top != -1){
        enqueue(pop());
    }
}

// Display queue
void display(){
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main
int main(){
    int n, val;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        enqueue(val);
    }

    reverseQueue();

    display();

    return 0;
}