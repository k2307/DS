#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Insert based on priority (smaller number = higher priority)
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL || val < head->data) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->data <= val)
            temp = temp->next;

        newNode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d enqueued into priority queue.\n", val);
}

// Remove element with highest priority (smallest number)
void dequeue() {
    if (head == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("%d dequeued from priority queue.\n", temp->data);
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

// Display queue
void display() {
    if (head == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Priority queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove Highest Priority)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Program Terminated!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}