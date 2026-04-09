#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int size = 0;

//ELEMENT INSERTION.
void insert(int value){
    if(size == SIZE){
        printf("Queue OverFlow!\n");
        return;
    }else{
        queue[size++] = value;
    }
}

//ELEMENT DELETION.
void deleteElement(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    int minindex = 0;

    for(int i = 1;i < size;i++){
        if(queue[i] < queue[minindex]){
            minindex = i;
        }
    }

    int deleted = queue[minindex];

    //shift elements.
    for(int i = minindex;i < size - 1;i++){
        queue[i] = queue[i + 1];
    }

    printf("%d\n",deleted);

    size--;
}

//PEEK (show smallest element)
void peek(){
    if(size == 0){
        printf("-1\n");
        return;
    }
    
    int minindex = 0;
    
    for(int i = 1;i < size;i++){
        if(queue[i] < queue[minindex])
        minindex = i;
    }
    printf("%d\n",queue[minindex]);
}

int main(){
    int choice,val,ch,i=1;

    while(1){

    printf("\n---MAIN MENU---\n");
    printf("1.Insert\n2.Delete\n3.Peek\n4.Exit\n");
    scanf("%d",&choice);

        switch(choice){
            case 1:
            do{
                printf("Enter element %d: ",i);
                scanf("%d",&val);

                insert(val);
                
                printf("1.Continue\n0.Exit\n");
                scanf("%d",&ch);
                i++;
            }while(ch != 0);
            break;

            case 2:
            deleteElement();
            break;

            case 3:
            peek();
            break;

            case 4:
            return 0;

            default:
            printf("Invalid! choice\n");
            break;
        }
    }
    return 0;
}