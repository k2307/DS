#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;  // Queue front
struct Node* rear = NULL;   // Queue rear

// Enqueue (Insert at end)
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = rear;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued into queue.\n", val);
}

// Dequeue (Remove from front)
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct Node* temp = front;
    front = front->next;
    
    if (front != NULL)
        front->prev = NULL;
    
    printf("%d dequeued from queue.\n", temp->data);
    free(temp);
}

// Display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Queue Using Doubly Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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