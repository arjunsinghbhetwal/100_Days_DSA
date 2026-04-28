#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize table
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Insert
void insert(int key) {
    int index = key % SIZE;

    int i = 0;
    while (hashTable[(index + i*i) % SIZE] != -1) {
        i++;
    }

    hashTable[(index + i*i) % SIZE] = key;
}

// Search
int search(int key) {
    int index = key % SIZE;

    int i = 0;
    while (hashTable[(index + i*i) % SIZE] != -1) {
        if (hashTable[(index + i*i) % SIZE] == key)
            return 1;
        i++;
    }
    return 0;
}

// Main
int main() {
    init();

    insert(49);
    insert(56);

    if (search(49))
        printf("FOUND\n");
    else
        printf("NOT FOUND\n");

    if (search(15))
        printf("FOUND\n");
    else
        printf("NOT FOUND\n");

    return 0;
}