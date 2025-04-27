#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtSpecific() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int value, pos, i = 1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (i < pos-1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of range!\n");
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("%d inserted at position %d.\n", value, pos);
        }
    }
}

void deleteSpecific() {
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in list!\n");
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        printf("%d deleted from the list.\n", value);
        free(temp);
    }
}

void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("\nList is empty!\n");
    } else {
        printf("\nList elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Specific Position\n");
        printf("2. Delete Specific Node\n");
        printf("3. Display List\n");
        printf("4. End\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtSpecific(); break;
            case 2: deleteSpecific(); break;
            case 3: display(); break;
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