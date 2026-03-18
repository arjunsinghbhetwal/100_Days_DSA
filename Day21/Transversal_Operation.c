#include <Stdio.h>
#include <Stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

int main(){

    int i=0;

    struct node *n1;
    struct node *n2;
    struct node *n3;

    n1 = (struct node*) malloc(sizeof(struct node));
    n2 = (struct node*) malloc(sizeof(struct node));
    n3 = (struct node*) malloc(sizeof(struct node));

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = NULL;

    head = n1;

//------------Insert at beginning------------//
    struct node *newnode;

    newnode = (struct node*) malloc(sizeof(struct node));

    newnode->data = 5;
    newnode->next = head;           //new node points to old head.

    head = newnode;                //head moves to new node.
//-----------------------------------------//

    printf("Initial list: ");

//-------------Transversal--------------//

    struct node *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
//-------------------------------------//

//-------------Insert at End-------------//

    struct node *newnode2;
    struct node *temp2;

    newnode2 = (struct node*) malloc(sizeof(struct node));

    newnode2->data = 40;
    newnode2->next = NULL;

    temp2 = head;

    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    //temp points the last next of the node.
    temp2->next = newnode2;
//---------------------------------------//

//------------Transversal Again-------------//

    printf("\nAfter insertion at the end: ");

    temp = head;

    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
//---------------------------------------//

//------------Deletion at beggining----------//
    struct node *temp3;

    temp3 = head;
    head = head->next;

    free(temp3);
//---------------------------------------//

//-------------Transversal---------------//
     printf("\nAfter deletion at beginning: ");

     temp = head;

     while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
     }
//------------------------------------//

//------------Deletion at end-------------//
     struct node *temp4;
     struct node *prev;

     temp4 = head;

     while(temp4->next != NULL){
        prev = temp4;
        temp4 = temp4->next;
     }

     prev->next = NULL;
     free(temp4);
//--------------------------------------//

//---------------Transversal------------//
     printf("\nAfter deletion at end: ");

     temp = head;

     while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
     }
//----------------------------------------//

//-----------Insertion at position---------//
     struct node *newnode3;
     struct node *temp5;

     newnode3 = (struct node*) malloc(sizeof(struct node));

     newnode3->data = 25;

     int pos = 3;

     temp5 = head;

     for(int i = 1; i < pos-1; i++)
     {
        temp5 = temp5->next;
     }

     //Important Part.
     newnode3->next = temp5->next; //assigns newnode the next of node 2.
     temp5->next = newnode3;       //assigns temp5(2nd node)->next newnode(node).
//---------------------------------------//

//--------------Transversal---------------//
     printf("\nAfter Insertion at pos: ");

     temp = head;

     while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
     }
//---------------------------------------//

//----------Circular Linked list--------//
     struct node *temp6;

     temp6 = head;

     while(temp6->next != NULL){
        temp6 = temp6->next;
     }

     temp6->next = head;
//-----------------------------------//

//-------Circular Transversal--------//
     printf("\nCircular Lined List: ");

     struct node *temp7 = head;

     do{
        printf("%d ", temp7->data);
        temp7 = temp7->next;
     }
     while(temp7 != head);
//---------------------------------//

    return 0;
}