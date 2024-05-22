#include <stdio.h>
void insert(int arr[], int *size, int pos, int value) {
    if (*size >= pos) {
        for (int i = *size; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = value;
        (*size)++;
        printf("Element %d inserted successfully.\n", value);
    } else {
        printf("Invalid position for insertion.\n");
    }
}
void delete(int arr[], int *size, int pos) {
    if (*size > 0 && pos <= *size) {
        int deletedValue = arr[pos - 1];
        for (int i = pos - 1; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element %d deleted successfully.\n", deletedValue);
    } else {
        printf("Invalid position for deletion.\n");
    }
}
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[100];
    int size = 0;
    insert(arr, &size, 1, 10); 
    insert(arr, &size, 2, 20);
    insert(arr, &size, 3, 30);
    display(arr, size);

    delete(arr, &size, 2);
    display(arr, size);

    return 0;
}
