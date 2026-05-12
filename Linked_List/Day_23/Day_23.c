#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node {
    int data;
    struct Node* next;
};

// Create Linked List
struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode;
    int val;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Merge Function
struct Node* merge(struct Node* head1, struct Node* head2) {

    struct Node* p = head1;
    struct Node* q = head2;

    struct Node* result = NULL;
    struct Node* tail = NULL;

    // First node set
    if(p->data < q->data) {
        result = p;
        tail = p;
        p = p->next;
    } else {
        result = q;
        tail = q;
        q = q->next;
    }

    // Main loop
    while(p != NULL && q != NULL) {
        if(p->data < q->data) {
            tail->next = p;
            tail = p;
            p = p->next;
        } else {
            tail->next = q;
            tail = q;
            q = q->next;
        }
    }

    // Remaining nodes
    if(p != NULL)
        tail->next = p;

    if(q != NULL)
        tail->next = q;

    return result;
}

// Display function
void display(struct Node* head) {
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main
int main() {
    int n, m;

    // First list
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    // Second list
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    // Merge
    struct Node* result = merge(head1, head2);

    // Output
    display(result);

    return 0;
}