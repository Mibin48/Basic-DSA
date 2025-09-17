#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int array3[100], n, key, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (in sorted order for binary search):\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &array3[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int linIndex = linearSearch(array3, n, key);
    if(linIndex != -1)
        printf("Linear Search: Element found at index %d\n", linIndex);
    else
        printf("Linear Search: Element not found\n");


    int binIndex = binarySearch(array3, n, key);
    if(binIndex != -1)
        printf("Binary Search: Element found at index %d\n", binIndex);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}
