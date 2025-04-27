#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertBeginning(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", val);
}

// Insert at end
void insertEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    printf("%d inserted at end.\n", val);
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) { // Only one node
        printf("%d deleted from beginning.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        struct Node* last = head->prev;
        head = head->next;
        last->next = head;
        head->prev = last;
        printf("%d deleted from beginning.\n", temp->data);
        free(temp);
    }
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) { // Only one node
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* last = head->prev;
        struct Node* secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
        printf("%d deleted from end.\n", last->data);
        free(last);
    }
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Doubly Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &val);
            insertBeginning(val);
            break;
        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            deleteBeginning();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Program Terminated!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}