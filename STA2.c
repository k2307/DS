#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int stack[100];
int top = -1;
int n;

void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Cannot pop.\n");
    } else {
        printf("\n%d has been popped from the stack.\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("\nStack is empty!\n");
    } else {
        printf("\nThe top element is %d.\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty!\n");
    } else {
        printf("\nStack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, initialElements, element;
    printf("Enter the initial number of elements in the stack: ");
    scanf("%d", &initialElements);
    printf("Enter the elements:\n");
    for (int i = 0; i < initialElements; i++) {
        scanf("%d", &element);
        top++;
        stack[top] = element;
    }
    n = 100; // Max size

    while (1) {
        printf("\n--- Stack Menu (Pop-Peek-Display) ---\n");
        printf("1. Pop\n");
        printf("2. Peek\n");
        printf("3. Display Stack\n");
        printf("4. End\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: pop(); break;
            case 2: peek(); break;
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