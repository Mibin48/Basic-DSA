#include <stdio.h>
#define MAX 100

int arr[MAX];
int n = 0;  // number of elements

void display() {
    if (n == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int pos, int val) {
    if (n == MAX) {
        printf("Array overflow\n");
        return;
    }
    if (pos < 0 || pos > n) {
        printf("Invalid position\n");
        return;
    }
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void delete(int pos) {
    if (n == 0) {
        printf("Array underflow\n");
        return;
    }
    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return;
    }
    printf("Deleted element = %d\n", arr[pos]);
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int search(int val) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

void update(int pos, int val) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return;
    }
    arr[pos] = val;
}

int main() {
    int choice, pos, val;

    while (1) {
        printf("\n--- Array Operations ---\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            printf("Enter position (0 to %d): ", n);
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &val);
            insert(pos, val);
            break;
        case 3:
            printf("Enter position (0 to %d): ", n - 1);
            scanf("%d", &pos);
            delete(pos);
            break;
        case 4:
            printf("Enter value to search: ");
            scanf("%d", &val);
            pos = search(val);
            if (pos != -1)
                printf("Element %d found at index %d\n", val, pos);
            else
                printf("Element not found\n");
            break;
        case 5:
            printf("Enter position (0 to %d): ", n - 1);
            scanf("%d", &pos);
            printf("Enter new value: ");
            scanf("%d", &val);
            update(pos, val);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
