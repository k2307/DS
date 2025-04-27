#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at Beginning
void insertAtBeginning() {
    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    head = newNode;

    printf("%d inserted at beginning.\n", value);
}

// Insert at End
void insertAtEnd() {
    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at end.\n", value);
}

// Insert at Specific Position
void insertAtPosition() {
    int pos, value, i = 1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of range!\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    printf("%d inserted at position %d.\n", value, pos);
}

// Delete at Beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete at End
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    if (temp->next == NULL) { // Only one node
        printf("Deleted %d from end.\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted %d from end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Delete Specific Value
void deleteSpecific() {
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("%d not found in list.\n", value);
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }
    printf("Deleted node with value %d.\n", value);
    free(temp);
}

// Display Forward
void displayForward() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display Backward
void displayBackward() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    printf("List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete Specific Node\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteAtBeginning(); break;
            case 5: deleteAtEnd(); break;
            case 6: deleteSpecific(); break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9:
                printf("Program Terminated.\n");
                exit(0);
            default:
                printf("Enter a valid choice.\n");
        }
    }

    getch();
    return 0;
}