#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10

int hashTable[MAX];

int hashFunction(int key) {
    return key % MAX;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = index;
    while (hashTable[i] != -1) {
        i = (i + 1) % MAX;
        if (i == index) {
            printf("\nHash table is full. Cannot insert %d.\n", key);
            return;
        }
    }
    hashTable[i] = key;
    printf("%d inserted at index %d.\n", key, i);
}

void search(int key) {
    int index = hashFunction(key);
    int i = index;
    while (hashTable[i] != -1) {
        if (hashTable[i] == key) {
            printf("%d found at index %d.\n", key, i);
            return;
        }
        i = (i + 1) % MAX;
        if (i == index) {
            break;
        }
    }
    printf("%d not found in the hash table.\n", key);
}

void display() {
    printf("\nHash table: ");
    for (int i = 0; i < MAX; i++) {
        if (hashTable[i] == -1)
            printf("X ");
        else
            printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int main() {
    int choice, key;

    // Initialize hash table to -1 (empty slots)
    for (int i = 0; i < MAX; i++) {
        hashTable[i] = -1;
    }

    while (1) {
        printf("\n--- Hashing (Linear Probing) Operations Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Display Hash Table\n");
        printf("4. End\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("The Program Is Terminated\n");
                exit(0);
            default:
                printf("Enter A Valid Choice\n");
        }
    }
    getch();
    return 0;
}