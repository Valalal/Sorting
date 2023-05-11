#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Input(int *count, int **array);

void Heapify(int arr[], int count, int i);

void Heap_Sort(int arr[], int count);

void Output(int count, int array[]);

int main(void) {
    int count;
    int *array;
    Input(&count, &array);
    Output(count, array);
    Heap_Sort(array, count);
    Output(count, array);
    free(array);
}

void Input(int *count, int **arr) {
    printf("Number of elements:\n");
    if (scanf("%d", count) == 0) {
        puts("Error");
        exit(1);
    }
    *arr = (int *) malloc((*count) * sizeof(int));
    if (*arr) {
        for (int i = 0; i < *count; i++) {
            if (arr)
                (*arr)[i] = rand() % 20;
            else
                exit(-2);
        }
        printf(".........\n");
    }
}

void Output(int count, int array[]) {
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void Heapify(int arr[], int count, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < count && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < count && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int buff = arr[i];
        arr[i] = arr[largest];
        arr[largest] = buff;
        Heapify(arr, count, largest);
    }
}

void Heap_Sort(int arr[], int count) {
    for (int i = count / 2 - 1; i >= 0; i--) {
        Heapify(arr, count, i);
    }
    for (int i = count - 1; i >= 0; i--) {
        int buff = arr[0];
        arr[0] = arr[i];
        arr[i] = buff;
        Heapify(arr, i, 0);
    }
}