#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning.\n", value);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("\nList is empty! Cannot delete.\n");
    } else if (head->next == NULL) {
        printf("\nDeleted node with value %d from end.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("\nDeleted node with value %d from end.\n", temp->data);
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
        printf("1. Insert at Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Display List\n");
        printf("4. End\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: deleteFromEnd(); break;
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