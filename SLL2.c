#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at the end.\n", value);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("\nList is empty! Cannot delete.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        printf("\nDeleted node with value %d from beginning.\n", temp->data);
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
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Display List\n");
        printf("4. End\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtEnd(); break;
            case 2: deleteFromBeginning(); break;
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