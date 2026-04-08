#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

//PUSH FUNCTION
void push(int value){
    if(top == MAX - 1){
        printf("Overflow\n");
    }else{
        top++;
        stack[top] = value;
        printf("Inserted: %d\n", value);
    }
}

//POP FUNCTION
int pop(){
    if(top == -1){
        printf("Underflow\n");
        return -1;
    }else{
        return stack[top--];
    }
}

//PEEK FUNCTION
int peek(){
    if(top == -1){
        printf("Stack empty\n");
        return -1;
    }else{
        return stack[top];
    }
}

//DISPLAY FUNCTION (STACK -> LIFO)
void display(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }else{
        printf("Stack Elements: ");

        printf("[");

        for(int i = top;i >= 0;i--){
            printf("%d",stack[i]);

            if(i != 0){
                printf(" ");
            }
        }
        printf("]\n");
    }
}

int main(){

    while(1){
        int choice,val,ch,i=0;
        printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:
            do{
                printf("Enter element %d: ",i+1);
                scanf("%d",&val);

                push(val);

                printf("1.Continue\n2.Exit\n");
                scanf("%d",&ch);
                i++;
            }while(ch != 2);

            break;

            case 2:
            val = pop();
            if(val != -1){
                printf("Element popped: %d\n",val);
            }
            break;

            case 3:
            printf("Top: %d\n",peek());
            break;

            case 4:
            display();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}