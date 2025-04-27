#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Function to initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // -1 means empty
    }
}

// Function to insert an element using linear probing
void insert(int value) {
    int key = value % SIZE;
    int originalKey = key;

    while (hashTable[key] != -1) {
        key = (key + 1) % SIZE;
        if (key == originalKey) {
            printf("Hash table is full! Cannot insert %d\n", value);
            return;
        }
    }
    hashTable[key] = value;
    printf("Inserted %d at index %d\n", value, key);
}

// Function to display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

int main() {
    int n, value;

    initialize(); // Set all slots to empty

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(value);
    }

    display();

    return 0;
}