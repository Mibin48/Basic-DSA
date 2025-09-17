#include <stdio.h>

#define SIZE 50

int queue[SIZE];
int front = 0;
int rear = 0;

void enqueue() {
    if (rear == SIZE) {
        printf("Queue overflow! Cannot insert more elements.\n");
        return;
    }
    int n;
    printf("Enter the element: ");
    scanf("%d", &n);
    queue[rear] = n;
    rear++;
}

void dequeue() {
    if (front == rear) {
        printf("Queue underflow! No elements to delete.\n");
        return;
    }
    printf("Element dequeued: %d\n", queue[front]);
    front++;
    
    if (front == rear) {
        front = rear = 0;
    }
}

void display() {
    if (front == rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    while (1) {
        printf("\nMenu\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        int choice;
        printf("Input the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
