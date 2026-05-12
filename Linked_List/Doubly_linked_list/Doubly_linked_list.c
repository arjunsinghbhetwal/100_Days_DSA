#include <stdio.h>
#include <stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

//Head Pointer
struct Node* head = NULL;

void insertatbeginning(int value){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void insertatend(int value){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    
    //if list is empty.
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    newNode->prev = temp;
}

void display(){

    struct Node* temp = head;

    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteatbeginning(){

    struct Node* temp = head;

    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }

    free(temp);
}

void deleteatend(){

    if(head == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node* temp = head;

    //Single Node case
    if(temp->next == NULL){

        head = NULL;

        free(temp);

        return;
    }

    //Traverse till the Last Node
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev = NULL;

    free(temp);
}



int main(){

    insertatbeginning(10);
    insertatbeginning(20);

    insertatend(30);
    insertatend(40);

    deleteatbeginning();

    display();

    deleteatend();

    display();

    return 0;
}