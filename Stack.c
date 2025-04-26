#include <stdio.h>
#include <stdlib.h>  // For system("cls") or system("clear")
#include <conio.h>
int stack[100];
int top = -1;
int n;
// Function prototypes
void push();
void pop();
void peek();
void display();
// Function to push an element onto the stack
void push() {
    int num;
    if (top == n - 1) {
        printf("\nStack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter an Element: ");
        scanf("%d", &num);
        top++;
        stack[top] = num;
        printf("%d has been pushed onto the stack.\n", num);
    }
}
// Function to pop an element from the stack
void pop() {
    int num;
    if (top == -1) {
        printf("\nStack Underflow! Cannot pop.\n");
    } else {
        num = stack[top];
        top--;
        printf("\n%d has been popped from the stack.\n",num);
    }
}
// Function to peek at the top element of the stack
void peek() {
    if (top == -1) {
        printf("\nStack is empty!\n");
    } else {
        printf("\nThe top element is %d.\n", stack[top]);
    }
}// Function to display stack elements
void display() {
    int i;
    if (top == -1) {
        printf("\nStack is empty!\n");
    } else {
        printf("\nStack elements: ");
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice;
    printf("Enter the height of the stack: ");
    scanf("%d", &n);
    while (1) {  // Infinite loop for menu
        printf("\nEnter Your Choice:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display Stack");
        printf("\n5. End");
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
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
                printf("The Program Is Terminated\n");
                exit(0);
            default:
                printf("Enter A Valid Choice\n");
        }
    }
    getch();
    return 0;
}