#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* top = NULL;  // Stack pointer

// Push element onto the stack (Insert at beginning)
void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = top;
    
    if (top != NULL)
        top->prev = newNode;
    
    top = newNode;
    printf("%d pushed onto stack.\n", val);
}

// Pop element from the stack (Remove from beginning)
void pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    
    struct Node* temp = top;
    top = top->next;
    
    if (top != NULL)
        top->prev = NULL;
    
    printf("%d popped from stack.\n", temp->data);
    free(temp);
}

// Peek the top element
void peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Top element is: %d\n", top->data);
}

// Display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Stack Using Doubly Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Program Terminated!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}