#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode;

int countNodes(struct Node* head){
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode;

    int n,val;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    for(int i = 0;i < n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));

        scanf("%d",&val);
        newNode->data=val;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        } else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    int result = countNodes(head);

    printf("Total Nodes: %d\n",result);

    return 0;
}