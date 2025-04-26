#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue() {
    int num;
    if ((front == 0 && rear == n-1) || (front == rear+1)) {
        printf("\nQueue Overflow! Cannot enqueue more elements.\n");
    } else {
        printf("Enter an Element: ");
        scanf("%d", &num);
        if (front == -1) { // First element
            front = rear = 0;
        } else if (rear == n-1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = num;
        printf("%d has been inserted into the circular queue.\n", num);
    }
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue Underflow! Cannot dequeue.\n");
    } else {
        printf("\n%d has been dequeued from the circular queue.\n", queue[front]);
        if (front == rear) { // Only one element
            front = rear = -1;
        } else if (front == n-1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nCircular Queue elements: ");
        if (rear >= front) {
            for (i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        } else {
            for (i = front; i < n; i++)
                printf("%d ", queue[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &n);
    while (1) {
        printf("\n--- Circular Queue Operations Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. End\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
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