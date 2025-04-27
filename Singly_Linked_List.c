#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createInitialList() {
    int initialData[] = {10, 20, 30}; // Example values
    int n = sizeof(initialData) / sizeof(initialData[0]);
    for (int i = n - 1; i >= 0; i--) {  // Insert at beginning to maintain order
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = initialData[i];
        newNode->next = head;
        head = newNode;
    }
    printf("Initial linked list created.\n");
}

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
    createInitialList();
    while (1) {
        printf("\n--- Singly Linked List Operations Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete Specific Node\n");
        printf("7. Display List\n");
        printf("8. End\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtSpecific(); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: deleteSpecific(); break;
            case 7: display(); break;
            case 8:
                printf("The Program Is Terminated\n");
                exit(0);
            default:
                printf("Enter A Valid Choice\n");
        }
    }
    getch();
    return 0;
}
