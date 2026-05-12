#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// 🔥 CREATE LIST
struct Node* createList(int n){
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newnode;
    int val;

    for(int i = 0; i < n; i++){
        newnode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter element: ");
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// 🔥 DISPLAY
void display(struct Node* head){
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 🔥 DELETE FUNCTION (MAIN LOGIC)
struct Node* deleteKey(struct Node* head, int key){

    struct Node* temp = head;
    struct Node* prev = NULL;

    // 🟢 CASE 1: First node delete
    if(temp != NULL && temp->data == key){
        head = temp->next;   // head aage shift
        free(temp);          // memory free
        return head;
    }

    // 🟡 CASE 2: Traverse to find key
    while(temp != NULL && temp->data != key){
        prev = temp;         // previous track
        temp = temp->next;   // aage badh
    }

    // 🔴 CASE 3: Key not found
    if(temp == NULL){
        printf("Key not found\n");
        return head;
    }

    // 🔥 CASE 4: Delete (JUMP LOGIC)
    prev->next = temp->next;   // node skip
    free(temp);                // memory free

    return head;
}

// 🔥 MAIN
int main(){

    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* head = createList(n);

    printf("Original List: ");
    display(head);

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    printf("Updated List: ");
    display(head);

    return 0;
}