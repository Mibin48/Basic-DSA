#include <stdio.h>
#define SIZE 5

int circular_queue[SIZE];
int front = 0, rear = 0;

int isFull() {
    return (rear + 1) % SIZE == front;
}

int isEmpty() {
    return front == rear;
}

void enqueue() {
    if (isFull()) {
        printf("Queue overflow! Cannot insert more elements.\n");
        return;
    }

    int x;
    printf("Enter the element: ");
    scanf("%d", &x);
    circular_queue[rear] = x;
    rear = (rear + 1) % SIZE;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! No elements to delete.\n");
        return;
    }

    printf("Element dequeued: %d\n", circular_queue[front]);
    front = (front + 1) % SIZE;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", circular_queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        printf("Input the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
